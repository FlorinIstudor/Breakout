#pragma once
#include "Scene.h"
#include "Game.h"
#include "Menu.h"

class StateManager
{
private:
	Scene* CurrentScene;

public:
	Scene* NextScene;
	sf::RenderWindow* Window;

	StateManager(sf::RenderWindow* aWindow);

	~StateManager();

	void DrawScene();

	void UpdateScene(sf::Time dt);
	void FixedUpdateScene(sf::Time dt);
	void HandleEventsSecene();

	void CheckForChange();
};

