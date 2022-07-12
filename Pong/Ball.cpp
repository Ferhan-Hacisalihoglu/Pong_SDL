#include "Ball.h"
#include "PongGame.h"

void Ball::Move(double deltaTime)
{

	GameObject::Move(deltaTime);

	if (y <= 0 && directionY < 0)
	{
		directionY *= -1;
	}
	else if (y >= PongGame::SCREEN_HEIGHT - height && directionY > 0)
	{
		directionY *= -1;
	}
}
