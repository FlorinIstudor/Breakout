#include "StateManager.h"

StateManager::StateManager(sf::RenderWindow* aWindow)
{
	NextScene = nullptr;
	CurrentScene = new Menu(this);
	Window = aWindow;
}

StateManager::~StateManager()
{
	delete CurrentScene;
	if (NextScene)
		delete NextScene;
}

void StateManager::DrawScene()
{
	Window->clear();

	CurrentScene->Draw(Window);

	Window->display();
}

void StateManager::UpdateScene(sf::Time dt)
{
	CurrentScene->Update(dt);
}

void StateManager::FixedUpdateScene(sf::Time dt)
{
	CurrentScene->FixedUpdate(dt);
}

void StateManager::HandleEventsSecene()
{
	CurrentScene->HandleEvents();
}

void StateManager::CheckForChange()
{
	if (NextScene)
	{
		delete CurrentScene;
		CurrentScene = NextScene;
		NextScene = nullptr;
	}
}
