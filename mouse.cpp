#include "mouse.h"
#include "map.h"
#include "object.h"

void mouse::render(RenderWindow & window, map & m)
{
	if (flag == 1)
	{
		if (m.get_place(object::get_x() + (object::get_width()) / 2, object::get_y() + (object::get_height()) / 2) != '1') object::render(window);
	}
};
mouse::mouse(float _x, float _y, String path, float q) :object(_x, _y, path, q)
{
	speed = 0.2;
	vision = 200;
	p = 1;
	flag = 1;
};
void mouse::move(float t, RenderWindow & window, map & m, int h)//the function of wandering within the map
{
	int* i = NULL;
	int q = m.isAny(object::get_x(), object::get_y(), vision, h);
	if (q != 2)
	{
		if (q == 0)
		{
			if (count == 0 || count > 250)
			{
				dx = 0;
				dy = 0;
				if (count > 250) count = 0;
				g = 1;
				k = rand() % 100;
				if (k > 75 || k < 25) g = -1;
				std::cout << k << std::endl;
				if (k >= 50) k = -1;
				else k = 1;
				dx = sqrt(rand() % 100);
				dy = sqrt(100 - dx*dx);
				dx = dx / 100;
				dy = dy / 100;
				if (dx > dy)
				{
					dy = 0;
					dx = 1;
				}
				if (dx < dy)
				{
					dx = 0;
					dy = 1;
				}
			}
			count++;
		}
		if (q == 1)
		{
			dx = -1;
			dy = -1;
			k = 1;
			g = 1;
			p = p*(-1);
		};
		i = m.isAllowed(window, (object::get_sprite()).getPosition().x, (object::get_sprite()).getPosition().y, k*dx*speed*t, g*dy*speed*t);
		if (i[0] == 0 || i[1] == 0) count = 0;
		if (m.isAny(object::get_x(), object::get_y(), vision, h))
		{
			if (i[0] > 0) dy = 0;
			else dx = 0;
		};
		sprite_update(i[0] * k*dx*speed*t, i[1] * g*dy*speed*t, t);
		(object::get_sprite()).move(i[0] * k*dx*speed*t, i[1] * g*dy*speed*t);
	}
	else flag = 0;
};