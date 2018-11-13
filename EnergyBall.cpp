#include "EnergyBall.h"
#include "Player.h"
#include "InputHandler.h"

EnergyBall::EnergyBall(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void EnergyBall::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void EnergyBall::update()
{
	m_velocity.setX(5);

	m_currentFrame = 0;

	SDLGameObject::update();
}

void EnergyBall::clean()
{
}

void EnergyBall::handleInput() {
}

SDL_Rect EnergyBall::setRect(SDL_Rect rect)
{
	rect.x = m_position.getX();
	rect.y = m_position.getY();
	rect.w = 32;
	rect.h = 32;

	return rect;
}
