#include "shadergl.h"


Shader::Shader(const char* vecpath, const char* fragpath) {
	std::string vcode, fcode;
	std::ifstream vpath, fpath;

	vpath.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fpath.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	

	try {
		vpath.open(vecpath);
		fpath.open(fragpath);
		if (!fpath.is_open()) {
			std::cout << "File not opened";
			
		}
		std::stringstream vstream, fstream;
		vstream << vpath.rdbuf();
		fstream << fpath.rdbuf();
		 
		vpath.close();
		fpath.close();

		vcode = vstream.str();
		fcode = fstream.str(); 
		
	}
	catch (std::ifstream::failure e) {
		std::cout << "Shader file not successfuly read" << std::endl;
	}
	const char* vshadercode = vcode.c_str();
	const char* fshadercode = fcode.c_str();

	unsigned int vertid, fragid;
	vertid = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertid, 1, &vshadercode, NULL);
	glCompileShader(vertid);
	int success0;
	char infoLog0[512];
	
	glGetShaderiv(vertid, GL_COMPILE_STATUS, &success0);
	if (!success0)
	{
		glGetShaderInfoLog(vertid, 512, NULL, infoLog0);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
			infoLog0 << std::endl;
	}

	fragid = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragid, 1, &fshadercode, NULL);
	glCompileShader(fragid);

	int success1;
	char infoLog1[512];
	
	glGetShaderiv(fragid, GL_COMPILE_STATUS, &success1);
	if (!success1)
	{
		glGetShaderInfoLog(vertid, 512, NULL, infoLog1);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" <<
			infoLog1 << std::endl;
	}



    id = glCreateProgram();
	glAttachShader(id, vertid);
	glAttachShader(id, fragid);
	glLinkProgram(id);

	glDeleteShader(vertid);
	glDeleteShader(fragid);




}

 void Shader::use() {
	 glUseProgram(id);
}
 void Shader::setBool(const std::string& name, bool value) const
 {
	 glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
 }
 void Shader::setInt(const std::string& name, int value) const
 {
	 glUniform1i(glGetUniformLocation(id, name.c_str()), value);
 }
 void Shader::setFloat(const std::string& name, float value) const
 {
	 glUniform1f(glGetUniformLocation(id, name.c_str()), value);
 }
