#include "Coord.h"

using namespace std;

Coord::Coord() : 
	x(0),
	y(0)
{
}

Coord::Coord(int x, int y) :
	x(x),
	y(y)
{
}

ostream& operator<< (ostream& out, const Coord& coord) {
	out << "(" << coord.x << ", " << coord.y << ")";
	return out;
}

ostream& operator<< (ostream& out, const Coords& coords) {
	out << "[ ";
	for (auto itr = coords.begin(); itr != coords.end(); ++itr) {
		out << **itr << " ";
	}
	out << "]";
	return out;
}
