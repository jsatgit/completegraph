#ifndef __COORD_H__
#define __COORD_H__

#include <vector>
#include <iostream>

class Coord {
public:
	Coord();
	Coord(int x, int y);
	int x;
	int y;
};

typedef std::vector<Coord*> Coords;

std::ostream& operator<<(std::ostream& out, const Coord& coord);

std::ostream& operator<< (std::ostream& out, const Coords& coords);

#endif // __COORD_H__
