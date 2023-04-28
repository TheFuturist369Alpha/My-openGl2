#ifndef SHADER
#define SHADER

#include <glad/glad.h>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>


class Shader {

public:
	Shader(const char* vecpath, const char* fragpath);
	int id;
	void use();
	// utility uniform functions
	void setBool(const std::string& name, bool value) const;
	void setFloat(const std::string& name, float value) const;
	void setInt(const std::string& name, int value) const;





};



#endif
