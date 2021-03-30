#include "Game.h"

Game* g_game = 0;

// Main function.
int main(int argc, char* args[]) // Main MUST have these parameters for SDL.
{
	g_game = new Game();
	g_game->init("Week 09", 100, 100, 640, 480);

	g_game->prepare();



	while (g_game->running())
	{
	    g_game->handleEvents();
		g_game->update();
		g_game->render();
		g_game->waitForNextFrame();
    } 

	g_game->cleanup();

	return 0;
}
