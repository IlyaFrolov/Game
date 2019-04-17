#ifndef OBJECT_INCLUDED
#define OBJECT_INCLUDED
#include <iostream>
#include <ctime>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "map.h"
using namespace sf;//SFML namespace
class object
{
private:
	float q = 300;
	float width;
	float height;
	float x; //initial coordinates
	float y; //initial coordinates
	int g; //random generator flag
	int k; //random generator flag
	Image object_image;
	Texture object_texture;
	Sprite object_sprite;
	float up; //counter for updating sprite
	float down; //counter for updating sprite
	float right; //counter for updating sprite
	float left; //counter for updating sprite
	float speed; 
	int count;
	float sprite_speed;
protected:
	int flag = 1;
public:
	object(float _x, float _y, String path, float _q);
	float get_x();
	float get_y();
	float get_speed();
	Sprite & get_sprite();
	void sprite_update(float dx, float dy, float time);
	virtual void render(RenderWindow & window);
	float get_width();//sprite width in pixels 
	float get_height();//sprite height in pixels
	int get_flag() { return flag; };


};
#endif //OBJECT_INCLUDED