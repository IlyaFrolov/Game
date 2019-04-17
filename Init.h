#ifndef INIT_INCLUDED
#define INIT_INCLUDED
#include <SFML/Graphics.hpp>
#include "map.h"
#include "object.h"
#include <iostream>
#include "mouse.h"
#include "lion.h"
#include <fstream>
#include <list>

class Init
{
private:
	int co;
	char buffer[30];
	int w;
	int n;
	int h;
	std::list <mouse*> store;
	lion* Lion;
	String g[25];
public:
	map* m;
	sf::RenderWindow* window;
	Init();
	int get_num(){ return n; };
};
#endif