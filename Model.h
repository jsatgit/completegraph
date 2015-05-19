#ifndef __MODEL_H__
#define __MODEL_H__
#include <GLFW/glfw3.h>
#include <vector>
#include "Coord.h"

class Model {
public:
	Model();
	void init(GLFWwindow* window);
	static Model& getInstance();
	static void mouse_button_callback(GLFWwindow* window,
		  						  	  int button,
		 						  	  int action,
		  						  	  int mods); 

	void push(Coord* coord);

	const Coords& getCoords();

	// move all coordinates to new locations
	void move();
	
	static Model& m_this;
private:
	bool inRange(const Coord* coord);
	void getNewCoord(Coord* coord);
	void adjustCoord(Coord* coord);

	GLFWwindow* m_window;
	Coords m_newCoords;
	int m_winWidth;
	int m_winHeight;
};

#endif // __MODEL_H__
