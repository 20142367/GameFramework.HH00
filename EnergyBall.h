#pragma once
#include "SDLGameObject.h"

class EnergyBall : public SDLGameObject
{
public:
	EnergyBall(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	SDL_Rect GetRect() { return ball; }

private:
	void handleInput();

	SDL_Rect ball;

	SDL_Rect setRect(SDL_Rect rect);
};

