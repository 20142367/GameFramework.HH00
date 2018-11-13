#pragma once
#include "SDLGameObject.h"

class Wall : public SDLGameObject
{
public:
	Wall(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

	bool checkCollision(SDL_Rect A, SDL_Rect B);

private:

	SDL_Rect wall;

	SDL_Rect setRect(SDL_Rect rect);

};

