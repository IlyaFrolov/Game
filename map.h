#ifndef MAP_INCLUDED
#define MAP_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include "string.h"
#include <malloc.h>
using namespace sf;
class object;
class map
{
private:
	String arr[25];
	Image map_image;
	Texture map_texture;
	Sprite map_sprite;
	object** store;
	int store_size;
	int max_size;
public:
	int buff[2];
	map(String _k[25], int num_of_objects);
	int reg(object* obj);
	
	
	void render(RenderWindow & window);
	int* isAllowed(RenderWindow & window, float x, float y, float dx, float dy);
	char get_square_type(int X, int Y);
	char get_place(float x, float y);
	int isAny(float x, float y, float R);
};
#endif //MAP_INCLUDED