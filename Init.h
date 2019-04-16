#ifndef INIT_INCLUDED
#define INIT_INCLUDED
#include <SFML/Graphics.hpp>
#include "map.h"
#include "object.h"
#include <iostream>
#include "mouse.h"
#include "lion.h"
#include <fstream>

class Init
{
private:
	int co;
	char buffer[30];
	int w;
	int n;
	int h;
	map* m;
	mouse** Mouse;
	lion* Lion;
	String g[25];
public:
	sf::RenderWindow* window;
	Init()
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
		Mouse = new  mouse*[n - 1];
		for (int i = 0; i < n - 1;i++) Mouse[i]=new mouse(300, 300, "mouse.png", 20);
		Lion=new lion(300, 300, "LionNice.png", 300);
		m = new map(g, n);
		for (int i = 0; i < n - 1; i++)
		{
			if ((*m).reg(&(*(Mouse[i]))))
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
		h = n - 1;
	}
	int get_num(){ return n; };
	void render(float time1)
	{
		(*window).clear();
		(*m).render((*window));
		for (int i = 0; i < n - 1;i++) (*(Mouse[i])).move(time1, *(window), *(m), h);
		(*Lion).move(time1, *(window), *(m));
		(*Lion).render((*window));
		for (int i = 0; i < n - 1; i++) (*(Mouse[i])).render((*window), (*m));
		(*window).display();
		std::cout << m->count();
	}
	

};
#endif