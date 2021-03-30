#include"Game.h"
#include"Plane.h"
#include "Sprite.h"
#include "Fire.h"
#include "FireList.h"

Game::Game() 
{

}
Game::~Game() 
{}

bool Game::init(const char* title, int xPos, int yPos, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
	m_pWindow = SDL_CreateWindow(title, xPos, yPos, width, height, 0);

	if (m_pWindow != 0)
	  {
		 m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
				return true;
			}
	  }

	return false;
  
}



	void Game::prepare()
	{
		background = Sprite(m_pRenderer, "background.png", 1024, 1024);
		Plane = Plane(m_pRenderer, "Plane.png", ) //size of plane need to be given here eg: 0, 0, 154, 221, 300, 200,  
	    Fires = FireList();

		deltaTime = 1.0f / targetFramerate;
		currentFrameTime = SDL_GetTicks();

		m_bRunning = true;
	
	}

	void Game::handleEvents()
	{
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				m_bRunning = false;
			}
		}
		else if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				plane.velY = -1;
				break;
			case SDLK_DOWN:
				plane.velY = 1;
				break;
			case SDLK_LEFT:
				plane.velX = -1;
				break;
			case SDLK_RIGHT:
				plane.velX = 1;
				break;
			case SDLK_SPACE:
				Fires.AddFire(m_pRenderer, plane.getWeaponX(), plane.getWeaponY());

            default:
				break;

			}
		}
		else if (event.type == SDL_KEYUP)
		{
			case SDLK_UP:
				plane.velY = 0;
				break;
			case SDLK_DOWN:
				plane.velY = 0;
				break;
			case SDLK_LEFT:
				plane.velX = 0;
				break;
			case SDLK_RIGHT:
				plane.velX = 0;
				break;
			case SDLK_ESCAPE:
				m_bRunning = false;


			default:
				break;
		}
	}

	void Game::update()
	{
		Plane.moveBy(plane.velX, plane.velY);
	}

	void Game::render()
	{
		SDL_RenderClear(m_pRenderer);

		background.draw(m_pRenderer);
		ship.draw(m_pRenderer);
		Fires.UpdateFires(m_pRenderer);

		SDL_RenderPresent(m_pRenderer);
	}

	void Game::waitForNextFrame()
	{

		Unit32 gameTimeMs = SDL_Geticks();
		timeSinceLastFrame = gameTimeMs - currentFrameStartTime;

		if (timeSinceLastFrame < frameDelayMs)
		{
			SDL_Delay(frameDelayMs - timeSinceLastFrame);
		}


		currentFrameTimeStartTime;

		detaTime = (currentFrameEndTime - currentFrameStartTime) / 1000.f;
		gameTime = currentFrameEndTime / 1000.f;

		currentFrameStartTime = currentFrameEndTime;

	}

	void Game::cleanup()
	{
		SDL_DestroyWindow(m_pWindow);
		SDL_DestroyRenderer(m_pRenderer);
		SDL_Quit();
	}
