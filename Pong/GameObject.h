#pragma once

#include "SDL.h"

class GameObject
{
public:
	double x, y;
	double width, height;

	double speed;
	double directionX, directionY;

	GameObject();

	void setPosition(double x,double y);
	void setSize(double width, double height);
	void setDirection(double directionX, double directionY);
	void setSpeed(double speed);

	void render(SDL_Surface surface);
	void Move(double deltaTime);

	SDL_Rect getRectangle();

};
