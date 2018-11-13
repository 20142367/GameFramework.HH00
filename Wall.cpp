#include "Wall.h"
#include "Player.h"
#include "Game.h"
#include "InputHandler.h"
#include "EnergyBall.h"

Wall::Wall(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Wall::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Wall::update()
{
	m_currentFrame = 0;

//	if (checkCollision(wall, EnergyBall::GetRect()))

	SDLGameObject::update();
}

void Wall::clean()
{
}

bool Wall::checkCollision(SDL_Rect A, SDL_Rect B) 
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

SDL_Rect Wall::setRect(SDL_Rect rect)
{
	rect.x = 500;
	rect.y = 100;
	rect.w = 64;
	rect.h = 64;

	return rect;
}