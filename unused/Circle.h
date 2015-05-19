#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Coord.h"

class Circle {
public:
	Circle(const Coord& coord, int radius);

	Coords circumf();

private:
	int f(int x);

	Coords flipX (const Coords& coords);
	
	Coords flipY (const Coords& coords);
	
	Coord m_centre;	
	int m_radius;
};

#endif // __CIRCLE_H__
