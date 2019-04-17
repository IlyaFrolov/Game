#include"map.h"
#include "object.h"
#include <iostream>

map::map(String _k[25], sf::RenderWindow* _window)
{
	map_image.loadFromFile("floor.png");
	map_texture.loadFromImage(map_image);
	map_sprite.setTexture(map_texture);
	buff[0] = 1;
	buff[1] = 1;
	window = _window;
	for (int i = 0; i < 25; i++)  arr[i] = _k[i];
};
int map::reg(mouse* obj)
{
	
	if (store.size() != store.max_size())
	{
		store.push_back(obj);
		std::cout << "store size is " << store.size() << std::endl;
		return 1;
	}
	return 0;
};
int map::reg(lion* obj)
{
	Lion = obj;
	return 1;
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
		x1 = Lion->get_x();
		y1 = Lion->get_y();
		b = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
		if (b>0 && b < 10) return 2;
		if (b>0 && b < R) return 1;
	return 0;
}
int map::count()
{
	return store.size();
}
void map::render(float time1)
{
	window->clear();
	for (auto it = store.begin(); it != store.end(); it++)
	{
		if (!((*it)->get_flag()))
		{
			delete (*it);
			store.erase(it);
			break;
		}
	}
	for (int i = 0; i < 25; i++)
	for (int g = 0; g < 25; g++)
	{
		if (arr[i][g] == '0') map_sprite.setTextureRect(IntRect(0, 0, 100, 100));
		if (arr[i][g] == '1') map_sprite.setTextureRect(IntRect(100, 0, 100, 100));
		map_sprite.setPosition(g * 100, i * 100);
		window->draw(map_sprite);

	}
	for (auto it = store.begin(); it != store.end(); it++)
	{
		(*it)->move(time1, (*window), (*this));
		(*it)->render((*window), (*this));
	}
	Lion->move(time1, (*window), (*this));
	Lion->render(*window, *this);
	(*window).display();
	std::cout << store.size() << std::endl;
}