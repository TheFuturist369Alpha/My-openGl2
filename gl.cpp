
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "shadergl.h"
#include "stb_image.h"



		void framebuffer_size_callback(GLFWwindow * window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void processInput(GLFWwindow * win) {
			if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
				glfwSetWindowShouldClose(win, true);
			}
		}

		int main() {
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

			GLFWwindow* window = glfwCreateWindow(800, 600, "Hello GL", NULL, NULL);

			if (window == nullptr) {
				std::cout << "failed to create window" << std::endl;
				glfwTerminate();
				return -1;

			}
			glfwMakeContextCurrent(window);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize GLAD" << std::endl;
				return -1;
			}
			glViewport(0, 0, 800, 600);
			
			float vertices[] = {
			0.7f, -0.7f, 0.0f, 1.0f, 0.0f, 0.0f,
           -0.7f, -0.7f, 0.0f, 0.0f, 1.0f, 0.0f, 
            0.0f, 0.7f, 0.0f, 0.0f, 0.0f, 1.0f 
			};

			unsigned int indices[] = {
				0,2,1
				
			};
			Shader sh("C:\\Users\\RISSY\\Desktop\\VsCpp Projects\\MyopenGL2\\Vert_shad.shader", "C:\\Users\\RISSY\\Desktop\\VsCpp Projects\\MyopenGL2\\Frag_shad.shader");
			
			unsigned int VBO;
			glGenBuffers(1, &VBO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
			Shader shader();

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
				(void*)0);

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
				(void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);
			

			
			unsigned int VAO;
			glGenVertexArrays(1, &VAO);


			glBindVertexArray(VAO);
			// 2. copy our vertices array in a buffer for OpenGL to use
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
			// 3. then set our vertex attributes pointers
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
				(void*)0);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
				(void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);

			
			
			// ..:: Drawing code (in render loop) :: ..
			// 4. draw the object

			unsigned int EBO;
			glGenBuffers(1, &EBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,
				GL_STATIC_DRAW);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
				(void*)0);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
				(void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);

			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

			
 
			glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

			while (!glfwWindowShouldClose(window))
			{
				processInput(window);

				glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT);
				
				sh.use();
				
				glBindVertexArray(VAO);
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
				glEnableVertexAttribArray(0);
				
				

				glfwSwapBuffers(window);
				glfwPollEvents();
			}


			glfwTerminate();


			return 0;
		}
	

