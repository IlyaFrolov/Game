#ifndef MAP_INCLUDED
#define MAP_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include "string.h"
#include "mouse.h"
#include "lion.h"
#include "object.h"
#include <list>
#include <malloc.h>
using namespace sf;
class lion;
class mouse;
class map
{
private:
	int num;
	String arr[25];
	sf::RenderWindow* window;
	Image map_image;
	Texture map_texture;
	Sprite map_sprite;
	std::list<mouse*> store;//map has it's own base of objects
	lion* Lion;
public:
	int buff[2];
	map(String _k[25], sf::RenderWindow* _window);
	int reg(mouse* obj);
	int reg(lion* obj);
	
	
	void render(RenderWindow & window);
	int* isAllowed(RenderWindow & window, float x, float y, float dx, float dy);
	char get_square_type(int X, int Y);
	char get_place(float x, float y);
	int isAny(float x, float y, float R);
	int count();
	void delete_object(int n);
	void render(float time1);
};
#endif //MAP_INCLUDED