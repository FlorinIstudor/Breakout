#pragma once
#include "Scene.h"
#include "StateManager.h"
#include "Button.h"

class EndScreen : public Scene
{
private:
	sf::Font MenuFont;
	sf::Text MenuText;
	Button ExitButton;


public:
	EndScreen(StateManager* aStateMan, std::string Text);

	void Draw(sf::RenderWindow* window) override;

	void HandleEvents() override;
};

