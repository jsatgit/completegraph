#ifndef __OBJ_H__
#define __OBJ_H__
#include "Coord.h"

class Obj {
public:
	Obj(Coord* coord, const std::string& name);

private:
	Coord* coord;
	std::string name;
};

#endif // __OBJ_H__
