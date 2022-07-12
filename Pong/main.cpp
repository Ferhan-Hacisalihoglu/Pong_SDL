#include "SDL.h"
#include "iostream"
#include "PongGame.h"

using namespace std;

SDL_Window* window;
SDL_Surface* surface;
PongGame* pongGame;

int main(int arcg,char *args[])
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("PONG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, PongGame::SCREEN_WIDTH, PongGame::SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

	surface = SDL_GetWindowSurface(window);

	pongGame = new PongGame;
	pongGame->init();

	bool quit = false;

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	SDL_Event event;

	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}

			const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

			if (keyboardState[SDL_SCANCODE_ESCAPE])
			{
				quit = true;
			}

			if (keyboardState[SDL_SCANCODE_W])
			{
				pongGame->setPlayer1Direction(-1);
			}
			else if (keyboardState[SDL_SCANCODE_S])
			{
				pongGame->setPlayer1Direction(1);
			}
			else
			{
				pongGame->setPlayer1Direction(0);
			}

			if (keyboardState[SDL_SCANCODE_UP])
			{
				pongGame->setPlayer2Direction(-1);
			}
			else if (keyboardState[SDL_SCANCODE_DOWN])
			{
				pongGame->setPlayer2Direction(1);
			}
			else
			{
				pongGame->setPlayer2Direction(0);
			}
		}

		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (NOW - LAST)/(double) SDL_GetPerformanceFrequency()*2;

		Uint32 backgroundcolor = SDL_MapRGB(surface->format, 255, 255, 255);
		SDL_FillRect(surface,NULL, backgroundcolor);

		pongGame->update(deltaTime);

		pongGame->render(*surface);

		SDL_UpdateWindowSurface(window);
	}

	SDL_DestroyWindow(window);
	SDL_FreeSurface(surface);

	window = NULL;
	surface = NULL;

	return 0;
}
