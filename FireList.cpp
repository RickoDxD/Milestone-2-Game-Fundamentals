#include "FireList.h"

FireList::FireList()
{
}

FireList::~FireList()
{
}

void FireList::AddFire(SDL_Renderer* renderer, int x, int y)
{
	fireArray.emplace_back(Fire(renderer, x, y));
}

void FireList::UpdateFire(SDL_Renderer* renderer)
{
	for (auto it = fireArray.begin(); it != fireArray.end();)
	{
		it->update();
		if (it->outOfScreen())
		{
			it = fireArray.erase(it);
		}
		else
		{
			it->draw(renderer);
			++it;
		}
	}
}
