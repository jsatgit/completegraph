#include "View.h"
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

View::View(GLFWwindow* window, Model& model) : 
	m_window(window),
	m_model(model)
{
}

void View::init() {
	int width, height;
	glfwGetFramebufferSize(m_window, &width, &height);
	glDisable(GL_DEPTH_TEST);
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,width,height,0,1,-1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void View::square(const Coord& c, int w) {
	glPointSize(w);
	glBegin(GL_POINTS);
	glColor4f(1,1,1,1);
	glVertex2f(c.x,c.y);
	glEnd();
}

void View::line(const Coord& beg, const Coord& end, int width) {
	glLineWidth(width);
	glBegin(GL_LINES);
	glColor4f(1,1,1,1);
	glVertex2f(beg.x, beg.y);
	glVertex2f(end.x, end.y);
	glEnd();
}

void View::draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	update();

	this_thread::sleep_for(milliseconds(15));
	glfwSwapBuffers(m_window);
	glfwPollEvents();
}

void View::update() {
	m_model.move();

	// points
	int squareWidth = 5;
	auto coords = m_model.getCoords();
	for (auto itr = coords.begin(); itr != coords.end(); ++itr)
		square(**itr, squareWidth);

	// lines
	for (int i = 0; i < coords.size(); ++i) {
		for (int j = i+1; j < coords.size(); ++j) {
			line(*coords[i], *coords[j], squareWidth);
		}
	}
}
