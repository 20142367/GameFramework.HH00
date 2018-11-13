#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public :
	Player(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

private :
	void handleInput();

	Uint32 startTime = 0;
	Uint32 currentTime = 0;

	const float coolTime = 500.0f;

};