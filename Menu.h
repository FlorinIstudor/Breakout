#pragma once
#include "Scene.h"
#include "Button.h"
#include "StateManager.h"
#include "EndScreen.h"

class Menu : public Scene
{
private:

	sf::Text TitleText;
	sf::Font MenuFont;

	Button PlayButton, ExitButton;

public:

	Menu(StateManager* AStateMan);

	~Menu();

	void Draw(sf::RenderWindow* window) override;

	void HandleEvents() override;
};

