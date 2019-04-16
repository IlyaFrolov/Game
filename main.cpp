#include <SFML/Graphics.hpp>
#include "map.h"
#include "object.h"
#include <iostream>
#include "mouse.h"
#include "lion.h"
#include <fstream>
#include "Init.h"

int main()
{
	Init init;
	char buffer[30];
	int w;
	int n;
	String g[25];
	
	
	
	Clock clock;
	while ((*(init.window)).isOpen())
	{
		float time1 = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time1 = time1 / 800;
		sf::Event event;
		while ((*(init.window)).pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				(*(init.window)).close();
		}

		(*(init.window)).clear();
		(*(init.m)).render((*(init.window)));
		(*(init.Mouse)).move(time1, *(init.window), *(init.m));
		(*(init.Lion)).move(time1, *(init.window), *(init.m));
		(*(init.Lion)).render((*(init.window)));
		(*(init.Mouse)).render(*(init.window), *(init.m));
		(*(init.window)).display();
		
	}
	return 0;
}