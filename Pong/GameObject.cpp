#include "GameObject.h"
#include "PongGame.h"

GameObject::GameObject()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	speed = 0;
	directionX = 0;
	directionY = 0;
}

void GameObject::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;
}

void GameObject::setSize(double width, double height)
{
	this->width = width;
	this->height = height;
}

void GameObject::setDirection(double directionX, double directionY)
{
	this->directionX = directionX;
	this->directionY = directionY;
}

void GameObject::setSpeed(double speed)
{
	this->speed = speed; 
}

void GameObject::render(SDL_Surface surface)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	Uint32 color = SDL_MapRGB(surface.format,0,0,0);
	SDL_FillRect(&surface, &rect, color);
}

void GameObject::Move(double deltaTime)
{
	x += directionX * speed * deltaTime;
	y += directionY * speed * deltaTime;

	if (y < 0)
	{
		y = 0;
	}
	else if (y>PongGame::SCREEN_HEIGHT-height)
	{
		y = PongGame::SCREEN_HEIGHT - height;
	}
}

SDL_Rect GameObject::getRectangle()
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

    return rect;
}
