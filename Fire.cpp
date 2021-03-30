#include "Fire.h"
#include "Sprite.h"

FireList::FireList()

Fire::Fire(SDL_Renderer* renderer, int x, int y)

{
	m_pSprite = Sprite(renderer, "Fire.png", 0, 0, 47, x, y, 5, 5);
}

FireList::~FireList()
{

}

void Fire::cleanup()
{
	m_pSprite.cleanup();
}

void Fire::update()
{
	m_pSprite.dst.y -= velY;
}
void Fire::draw(SDL_Renderer* renderer)
{
	m_pSprite.draw(renderer);
}