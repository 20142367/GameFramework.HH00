#include "Game.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {


	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, false);

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true;

		// load �κ� ��ġ
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/ball.png", "ball", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("Assets/wall.png", "wall", m_pRenderer))
		{
			return false;
		}

		m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
		m_gameObjects.push_back(new Wall(new LoaderParams(500, 100, 64, 64, "wall")));

		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	}
	else
	{
		return false;
	}

	return true;
}

void Game::render() {

	// draw color�� render �����
	SDL_RenderClear(m_pRenderer);

	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		m_gameObjects[i]->draw();

	// ȭ�� ����
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {

	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		m_gameObjects[i]->update();
}

void Game::clean() {
	
	cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents() {

	TheInputHandler::Instance()->update();
}

Game *Game::Instance() {

	if (s_pInstance == 0) {

		s_pInstance = new Game();
		return s_pInstance;
	}
	return s_pInstance;
}

void Game::quit()
{
	m_bRunning = false;
}