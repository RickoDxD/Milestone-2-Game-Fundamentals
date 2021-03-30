#ifndef _GAME_H
#define _GAME_H



#include "SDL.h"
#include "Sprite.h"
#include"Plane.h"
#include "Firelist.h"

class Game
{

public:

	Game();
	~Game();

	bool init(const char* title, int xPos, int yPos, int width, int height);

	void prepare();

	void handleEvents();
	void update();
	void render();
	void waitForNextTime();

	void cleanup();

	bool running() { return m_bRunning; }

private:

	Sprite background;
	Plane plane;
	FireList Fires;

	bool m_bRunning = false;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int targetFramerate = 30;
	int frameDelayMs = 1000 / targetFramerate;

	Uint32 currntFrameEndTime;
	Uint32 currentFrameStartTime;
	Uint32 currentFrameLastTime;

	float deltaTime;
	float gameTime = 0;
};

#endif 