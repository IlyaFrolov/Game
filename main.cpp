#include <SFML/Graphics.hpp>
#include "map.h"
#include "object.h"
#include <iostream>
#include "mouse.h"
#include "lion.h"
#include <fstream>

int main()
{
	char* buffer=new char[25];
	int w;
	int n;
	String g[25];
	std::ifstream input("map.txt");
	if (input.is_open())
	{
		for (int j = 0; j < 25; j++)
		{
			input >> buffer;
			g[j]=buffer;
		}
	}
	else 
	{
		std::cout<<"the text file with map configurations was not read..."<<std::endl;
		std::cout<<"press any key to exit";
		return 0
	}
	input.close();
	std::cout << "enter the number of the animals expected...   ";
	std::cin >> n;
	
	sf::RenderWindow window(sf::VideoMode(900, 900), "Lesson 1. kychka-pc.ru");
	mouse Mouse(300, 300, "mouse.png");
	lion Lion(300, 300, "LionNice.png");
	map m(g, n);
	if (m.reg(&Lion))
	{
		std::cout << "the object has been registrated successfully..." << std::endl;
	}
	else
	{
		std::cout << "the error ocurred... enter any number to exit..." << std::endl;
		std::cin >> w;
	};
	if (m.reg(&Mouse))
	{
		std::cout << "the object has been registrated successfully..." << std::endl;
	}
	else
	{
		std::cout << "the error ocurred... enter any number to exit..." << std::endl;
		std::cin >> w;
	};
	std::cout << "all the players have been registrated successfully..." << std::endl;
	std::cout << "enter any number to start the game..." << std::endl;
	std::cin >> w;
	Clock clock;
	while (window.isOpen())
	{
		float time1 = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time1 = time1 / 800;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		m.render(window);
		Mouse.move(time1, window, m);
		Lion.move(time1, window, m);
		Lion.render(window);
		Mouse.render(window, m);
		window.display();
		
	}
	return 0;
}