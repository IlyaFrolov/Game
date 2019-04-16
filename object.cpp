#include "map.h"
#include "object.h"
#include <iostream>

object::object(float _x, float _y, String path, float _q)
{
	x = _x;
	y = _y;
	object_image.loadFromFile(path);
	object_image.createMaskFromColor(Color(255, 255, 255));
	object_texture.loadFromImage(object_image);
	object_sprite.setTexture(object_texture);
	width = (object_image.getSize().x) / 3;
	height = (object_image.getSize().y) / 4;
	object_sprite.setTextureRect(IntRect(width, 0, width, height));
	q = _q;
	object_sprite.setPosition(q, q);
	up = 0;
	down = 0;
	right = 0;
	left = 0;
	speed = 0.2;
	count = 0;
	g = 1;
	k = 1;
	sprite_speed = speed / 20;

};
float object::get_x()
{
	return object_sprite.getPosition().x;
}
float object::get_y()
{
	return object_sprite.getPosition().y;
}
void object::sprite_update(float dx, float dy, float time)
{
	if (abs(dx) > abs(dy))
	{
		if (dx > 0)
		{
			object_sprite.setTextureRect(IntRect(((int)right) * width, 2*height, width, height));
			right = right + dx / 25;
			if (right > 2.99) right = 0;
		};
		if (dx<0)
		{
			object_sprite.setTextureRect(IntRect((2 - ((int)left)) * width, height, width, height));
			left = left + (-1)*dx / 25;
			if (left > 2.99) left = 0;
		};
	};
	if (abs(dx) < abs(dy))
	{
		if (dy<0)
		{
			object_sprite.setTextureRect(IntRect((int)up * width, 3*height, width, height));
			up = up + (-1)*dy / 25;
			if (up > 2.99) up = 0;
		};
		if (dy>0)
		{
			object_sprite.setTextureRect(IntRect((int)down * width, 0, width, height));
			down = down + dy / 25;
			if (down > 2.99) down = 0;
		};
	};
};

void object::render(RenderWindow & window)
{
	window.draw(object_sprite);
};

Sprite & object::get_sprite()
{
	return object_sprite;
};
float object::get_speed()
{
	return speed;
};
float object::get_width()
{
	return width;
};
float object::get_height()
{
	return height;
};

