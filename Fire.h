#pragma once

#include "Sprite.h"


class Fire
{

private:

	Plane();
	Sprite m_pSprite;

public:

	Fire();
	
	Fire(SDL_Renderer* renderer, int x, int y);

	~Fire();

	void cleanup();

	void update();
    void draw(SDL_Renderer* renderer);

	bool outOfScreen() { return m_pSprite.dst.y < -0; }



	float velY = 10;

	


};