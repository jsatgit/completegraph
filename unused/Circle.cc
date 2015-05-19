#include "Circle.h"
#include <cmath>
#include <iostream>

using namespace std;

Circle::Circle(const Coord& coord, int radius) : 
	m_centre(coord),
	m_radius(radius)
{}

int Circle::f(int x) {
	return sqrt(pow(m_radius, 2) - pow(x - m_centre.x, 2)) + m_centre.y;
}

Coords Circle::flipX (const Coords& coords) {
	Coords flipped;
	for (auto itr = coords.begin(); itr != coords.end(); ++itr) {
		int diff = (*itr)->x - m_centre.x;
		flipped.push_back(new Coord(m_centre.x - diff, (*itr)->y));
	}
	return flipped;
}

Coords Circle::flipY (const Coords& coords) {
	Coords flipped;
	for (auto itr = coords.begin(); itr != coords.end(); ++itr) {
		int diff = m_centre.y - (*itr)->y;
		flipped.push_back(new Coord((*itr)->x, m_centre.y + diff));
	}
	return flipped;
}

Coords Circle::circumf() {
	Coords coords;
	int y;
	for (int x = m_centre.x; x <= m_centre.x + m_radius; ++x) {
		y = f(x);
		Coord* coord = new Coord(x, y);	
		coords.push_back(coord);
	}

	Coords yFlip = flipY(coords);
	coords.insert(coords.end(), yFlip.begin(), yFlip.end());
	
	Coords xFlip = flipX(coords);
	coords.insert(coords.end(), xFlip.begin(), xFlip.end());
	
	return coords;
}
