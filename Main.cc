#include <GLFW/glfw3.h>
#include <iostream>

#include "View.h"
#include "Model.h"

using namespace std;
using namespace std::chrono;

static void error_callback(int error, 
						   const char* description) {
	cerr << description << endl;
}

static void key_callback(GLFWwindow* window, 
						 int key, 
						 int scancode, 
						 int action, 
						 int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

#define LOG_AND_RETURN_IF(cond, msg, ret) 	\
	if (cond) { 						  	\
		cerr << msg << endl; 			 	\
		return ret; 						\
	}

void mainLoop(GLFWwindow* window, View& view) {
	while (!glfwWindowShouldClose(window))
	{
		view.draw();
	}
}

int main(void)
{
	glfwSetErrorCallback(error_callback);

	LOG_AND_RETURN_IF(!glfwInit(), "Unable to initialize glfw.", -1);

	int width = 640;
	int height = 480;
	
	GLFWwindow* window 
		= glfwCreateWindow(width, height, "Complete Graph", 
							NULL, NULL);    
	if (!window) {
		glfwTerminate();
		cerr << "Unable to create window." << endl;
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	Model& model = Model::getInstance();
	model.init(window);
	View view(window, model);
	view.init();
	mainLoop(window, view);
	
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
