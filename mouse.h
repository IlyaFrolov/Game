#ifndef MOUSE_INCLUDED
#define MOUSE_INCLUDED
#include "map.h"
#include "object.h"

class map;
class object;

class mouse: public object
{
private:
	float vision;
	float dx;
	float dy;
	float speed;
	int count;
	int k;
	int g;
	int p;
public:
	virtual void render(RenderWindow & window, map & m);
	mouse(float _x, float _y, String path, float q);
	void move(float t, RenderWindow & window, map & m);


};
#endif
