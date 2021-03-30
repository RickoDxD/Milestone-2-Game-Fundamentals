#pragma once

#include "Fire.h"
#include <vector>


class FireList
{
	std::vector<Fire> fireArray;
public:
	FireList();
	~FireList();

	void AddFire(SDL_Renderer* renderer, int x, int y);
	void UpdateFire(SDL_Renderer* renderer);


};

