#include "Model.h"
 
#include <iostream>
#include <ctime>

using namespace std;

Model& Model::m_this = getInstance();

Model::Model()
{
	srand(time(0));
}

Model& Model::getInstance() {
	static Model model;
	return model;
}

void Model::init(GLFWwindow* window) {
	m_window = window;
	glfwSetMouseButtonCallback(m_window, mouse_button_callback);
	glfwGetFramebufferSize(m_window, &m_winWidth, &m_winHeight);
}

bool Model::inRange(const Coord* coord) {
	return (coord->x >= 0 && coord->x < m_winWidth &&
			coord->y >= 0 && coord->y < m_winHeight );
}

void Model::push(Coord* coord) {
	if (inRange(coord)) {
		m_newCoords.push_back(coord);
	}	
}

void Model::mouse_button_callback(GLFWwindow* window,
		  						  int button,
		 						  int action,
		  						  int mods) {
	if (action == GLFW_PRESS && button == GLFW_MOUSE_BUTTON_LEFT) {
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		Coord* coord = new Coord(2*xpos,2*ypos);
		m_this.push(coord);
	}	
}

const Coords& Model::getCoords() {
	return m_newCoords;
}

void Model::getNewCoord(Coord* coord) {
	int dir = rand() % 8;
	switch(dir) {
		case 0: 
			coord->x = coord->x + 1;
			break;
		case 1:
			coord->x = coord->x - 1;
			break;
		case 2:
			coord->x = coord->x + 1;
			coord->y = coord->y + 1;
			break;
		case 3:
			coord->x = coord->x - 1;
			coord->y = coord->y + 1;
			break;
		case 4:
			coord->x = coord->x + 1;
			coord->y = coord->y - 1;
			break;
		case 5:
			coord->x = coord->x - 1;
			coord->y = coord->y - 1;
			break;
		case 6:
			coord->y = coord->y + 1;
			break;
		case 7:
			coord->y = coord->y - 1;
			break;
	}
}

void Model::adjustCoord(Coord* coord) {
	if (coord->x < 0) {
		coord->x = 1;
	} else if (coord->x >= m_winWidth) {
		coord->x = m_winWidth - 2;
	}
	if (coord->y < 0) {
		coord->y = 1;
	} else if (coord->y >= m_winHeight) {
		coord->y -= m_winHeight - 2;
	}
}

void Model::move() {
	for (auto itr = m_newCoords.begin(); itr != m_newCoords.end(); ++itr) {
		getNewCoord(*itr);
		adjustCoord(*itr);
	}
}
