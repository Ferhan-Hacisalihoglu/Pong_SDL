#include "PongGame.h",
#include "iostream"

using namespace std;

void PongGame::init()
{
	player1 = new GameObject();

	player2 = new GameObject();

	ball = new Ball();

	resetGame();
}

void PongGame::render(SDL_Surface surface)
{
	player1->render(surface);
	player2->render(surface);
	ball->render(surface);
}

void PongGame::setPlayer1Direction(double direction)
{
	player1->setDirection(0, direction);
}

void PongGame::setPlayer2Direction(double direction)
{
	player2->setDirection(0, direction);
}

void PongGame::update(double deltaTime)
{
	player1->Move(deltaTime);
	player2->Move(deltaTime);

	collisionDetection();

	ball->Move(deltaTime);

	chechIfAnyoneScored();
}

void PongGame::collisionDetection()
{
	SDL_Rect player1Rect = player1 -> getRectangle();
	SDL_Rect ballRect = ball ->getRectangle();

	if (SDL_HasIntersection(&player1Rect,&ballRect))
	{
		if (ball->directionX < 0)
		{
			ball->directionX *= -1;
			return;
		}
	}

	SDL_Rect player2Rect = player2->getRectangle();

	if (SDL_HasIntersection(&player2Rect, &ballRect))
	{
		if (ball->directionX > 0)
		{
			ball->directionX *= -1;
			return;
		}
	}
}

void PongGame::chechIfAnyoneScored()
{
	if (ball->x <= 0)
	{
		player2Score++;
		resetGame();
	}
	else if (ball->x >= SCREEN_WIDTH)
	{
		player1Score++;
		resetGame();
	}
}

void PongGame::resetGame()
{
	double paddleSizeX = 50;
	double paddleSizeY = 150;

	double paddlePosY = (SCREEN_HEIGHT - paddleSizeY) / 2;

	player1->setPosition(10, paddlePosY);
	player1->setSize(paddleSizeX, paddleSizeY);
	player1->setSpeed(50);

	player2->setPosition(SCREEN_WIDTH - paddleSizeX - 10, paddlePosY);
	player2->setSize(paddleSizeX, paddleSizeY);
	player2->setSpeed(50);

	ball->setPosition((SCREEN_WIDTH - paddleSizeX) / 2, (SCREEN_HEIGHT - paddleSizeX) / 2);
	ball->setSize(50, 50);
	ball->setSpeed(100);
	ball->setDirection(1, 1);

	cout << player1Score << "-" << player2Score << endl;
}
