#pragma once
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class StateManager;


class Scene
{
protected:
	StateManager* StateMan;

public:
	virtual void Draw(sf::RenderWindow* window) {};
	virtual void Update(sf::Time dtt) {};
	virtual void FixedUpdate(sf::Time dt) {};
	virtual void HandleEvents() {};

};

