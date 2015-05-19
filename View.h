#ifndef __VIEW_H__
#define __VIEW_H__

#include <GLFW/glfw3.h>
#include "model.h"

class View {
public:
	View(GLFWwindow* window, Model& model);
	void init();
	void draw();
	void update();

	// Draw a square at c with width w
	void square(const Coord& c, int w);

	// Draw a line from beg to end with width width
	void line(const Coord& beg,
			  const Coord& end,
			  int width);

private:
	GLFWwindow* m_window;
	Model& 		m_model;
};

#endif // __VIEW_H__
