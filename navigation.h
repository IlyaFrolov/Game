#ifndef NAVIGATION_INCLUDED
#define NAVIGATION_INCLUDED
#include "map.h"
#include "object.h"

class navigator
{
public:
	navigator(object* _object, map* _map)
	{
		m = _map;
		store = _object;
	}
	char get_place_type(float x, float y)
	{
		
		return m->get_square_type((int)(x / 100) + 1, (int)(y / 100) + 1);
	};

private:
	object* store;
	map* m;

};
#endif