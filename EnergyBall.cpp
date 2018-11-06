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
	/*
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_acceleration.setX(1);
	*/
	m_velocity.setX(0);
	// m_velocity.setY(0);

	// m_velocity.operator+ = 1;

	handleInput();	// add our function

	// m_currentFrame = int((SDL_GetTicks() / 100) % 6);


	SDLGameObject::update();
}

void EnergyBall::clean()
{
}

void EnergyBall::handleInput() {
	/*
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
	*/
}
