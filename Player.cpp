#include "Player.h"
#include "Game.h"
#include "InputHandler.h"
#include "EnergyBall.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);

	handleInput();	// add our function

	m_currentFrame = int((SDL_GetTicks() / 100) % 6);


	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput() {
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

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		
		currentTime = SDL_GetTicks();

		if (currentTime - startTime > coolTime)
		{
			TheGame::Instance()->m_gameObjects.push_back(new EnergyBall(new LoaderParams(m_position.getX() + 80, m_position.getY() + 30, 32, 32, "ball")));

			startTime = SDL_GetTicks();
		}
	}
}