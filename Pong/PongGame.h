#pragma once
#include "GameObject.h"
#include "Ball.h"


class PongGame
{
public:

	static const int SCREEN_WIDTH = 1280;
	static const int SCREEN_HEIGHT = 720;

	int player1Score = 0;
	int player2Score = 0;

	GameObject* player1;
	GameObject* player2;
	Ball* ball;

	void init();
	void render(SDL_Surface surface);

	void setPlayer1Direction(double direction);
	void setPlayer2Direction(double direction);
	void update(double deltaTime);

	void collisionDetection();

	void chechIfAnyoneScored();
	void resetGame();
};
