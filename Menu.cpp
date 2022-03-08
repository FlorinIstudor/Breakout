#include "Menu.h"

Menu::Menu(StateManager* AStateMan)
	: PlayButton(Button(sf::RectangleShape(sf::Vector2f(280.f, 60.f)), "Play", sf::Color(153, 153, 153), sf::Color(135, 206, 235), 30)),
	  ExitButton(Button(sf::RectangleShape(sf::Vector2f(280.f, 60.f)), "Exit", sf::Color(153, 153, 153), sf::Color(135, 206, 235), 30))
{
	StateMan = AStateMan;

	MenuFont.loadFromFile("PressStart2P-Regular.ttf");

	TitleText.setString("BREAKOUT");
	TitleText.setFont(MenuFont);
	TitleText.setCharacterSize(50);

	TitleText.setFillColor(sf::Color(135, 206, 235));

	TitleText.setOrigin(sf::Vector2f(200.f, 30.f));

	TitleText.setPosition(sf::Vector2f(300.f, 200.f));

	PlayButton.SetPosition(sf::Vector2f(300.f, 300.f));

	ExitButton.SetPosition(sf::Vector2f(300.f, 400.f));
}

Menu::~Menu()
{
}

void Menu::Draw(sf::RenderWindow* window)
{
	window->draw(TitleText);
	PlayButton.Draw(window);
	ExitButton.Draw(window);
}

void Menu::HandleEvents()
{
	sf::Event event;
	while (StateMan->Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			StateMan->Window->close();
		
		if (PlayButton.IsHovered(StateMan->Window))
		{
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
			{
				StateMan->NextScene = new GameMenu(StateMan);
			}
		}

		if (ExitButton.IsHovered(StateMan->Window))
		{
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
			{
				StateMan->NextScene = new EndScreen(StateMan, "Thank you for playing!\n\n Credits : Florinlego ");
			}
		}
	}
}
