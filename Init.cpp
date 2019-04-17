#include <SFML/Graphics.hpp>
#include "map.h"
#include "object.h"
#include <iostream>
#include "mouse.h"
#include "lion.h"
#include "Init.h"
#include <fstream>
#include <list>

Init::Init()
	{
		std::ifstream input("map.txt");
		if (input.is_open())
		{
			for (int j = 0; j < 25; j++)
			{
				input >> buffer;
				g[j] = buffer;
			}
		}
		else
		{
			std::cout << "the text file with map configurations was not read..." << std::endl;
			std::cout << "press any key to exit";
			std::cin >> w;
		}
		input.close();
		std::cout << "enter the number of the animals expected...   ";
		std::cin >> n;
		window = new sf::RenderWindow(sf::VideoMode(900, 900), "Lesson 1. kychka-pc.ru");
		for (int i = 0; i < n - 1; i++) store.push_back(new mouse(300, 300, "mouse.png", 20));
		Lion = new lion(300, 300, "LionNice.png", 300);
		m = new map(g, window);
		for (auto it = store.begin(); it != store.end(); it++)
		{
			if ((*m).reg(&(**it)))
			{
				std::cout << "the object has been registrated successfully..." << std::endl;
			}
			else
			{
				std::cout << "the error ocurred... enter any number to exit..." << std::endl;
				std::cin >> w;
			};
		}
		if ((*m).reg(&(*Lion)))
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
};