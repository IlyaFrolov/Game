#include"map.h"
#include "object.h"
#include <iostream>

map::map(String _k[25], int num_of_objects)
{
	map_image.loadFromFile("floor.png");
	map_texture.loadFromImage(map_image);
	map_sprite.setTexture(map_texture);
	buff[0] = 1;
	buff[1] = 1;
	for (int i = 0; i < 25; i++)  arr[i] = _k[i];
	store = NULL;
	store_size = 0;
	max_size = num_of_objects;
};
int map::reg(object* obj)
{
	if (store == NULL) store = new object*[max_size];
	if (store != NULL)
	{
		store[store_size] = obj;
		store_size++;
		std::cout << "store size is " << store_size << std::endl;
		return 1;
	}
	return 0;
};
void map::render(RenderWindow & window)
{
	for (int i = 0; i < 25; i++)
	for (int g = 0; g < 25; g++)
	{
		if (arr[i][g] == '0') map_sprite.setTextureRect(IntRect(0, 0, 100, 100));
		if (arr[i][g] == '1') map_sprite.setTextureRect(IntRect(100, 0, 100, 100));
		map_sprite.setPosition(g * 100, i * 100);
		window.draw(map_sprite);

	}
};
int* map::isAllowed(RenderWindow & window, float x, float y, float dx, float dy)//says whether you can take a step along axis X and axis Y
{
	float ddx;
	float ddy;
	buff[0] = 1;
	buff[1] = 1;
	float maxx = window.getSize().x;
	float maxy = window.getSize().y;

	if (dx >= 0)
	{
		if (dx + x > maxx - 100) buff[0] = 0;
	}
	if (dy >= 0)
	{
		if (dy + y > maxy - 100) buff[1] = 0;
	}
	if (dx < 0)
	{
		ddx = dx;
		ddx = (-1)*ddx;
		if (x - ddx < 0) buff[0] = 0;
	}
	if (dy < 0)
	{
		ddy = dy;
		ddy = (-1)*ddy;
		if (y - ddy < 0) buff[1] = 0;
	}
	return buff;
};
char map::get_square_type(int X, int Y)
{
	return arr[X - 1][Y - 1];
};
char map::get_place(float x, float y)//says whether there is floor or armchair
{
	return arr[(int)(y / 100)][(int)(x / 100)];
};
int map::isAny(float x, float y, float R) //indicates the presence of other objects within the radius R
{
	float x1;
	float y1;
	float b;
	for (int q = 0; q < store_size; q++)
	{
		x1 = (store[q])->get_x();
		y1 = (store[q])->get_y();
		b = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
		if (b>0 && b < R) return 1;
	}
	return 0;
}