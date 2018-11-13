#include "EnergyBall.h"
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
