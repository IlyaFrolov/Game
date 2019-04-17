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

		(init.m)->render(time1);
		
	}
	return 0;
}