#include "lion.h"
#include "map.h"
#include "object.h"

void lion::render(RenderWindow & window, map & m)
{
	object::render(window);
};
void lion::move(float time, RenderWindow & window, map & m)//directing the lion with buttons
{
	int* i = NULL;
	dx = 0;
	dy = 0;

	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))))
	{

		dx = dx + (-1)*speed*time;
	}

	else if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))
	{
		dx = dx + speed*time;
	}
	else if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
	{
		dy = dy + (-1)*speed*time;
	}
	else if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
	{
		dy = dy + speed*time;
	};
	i = m.isAllowed(window, (object::get_sprite()).getPosition().x, (object::get_sprite()).getPosition().y, dx, dy);
	dx = i[0] * dx;
	dy = i[1] * dy;
	object::sprite_update(dx, dy, time);
	(object::get_sprite()).move(dx, dy);

};
lion::lion(float _x, float _y, String path, float q) :object(_x, _y, path, q)
{
	speed = 0.4;
};