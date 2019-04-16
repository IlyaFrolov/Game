#ifndef LION_INCLUDED
#define LION_INCLUDED
#include "map.h"
#include "object.h"

class map;
class object;

class lion : public object
{
private:
	float dx;
	float dy;
	float speed;
public:
	virtual void render(RenderWindow & window);
	lion(float _x, float _y, String path, float q);
	void move(float t, RenderWindow & window, map & m);
};
#endif