#include "EndScreen.h"

EndScreen::EndScreen(StateManager* aStateMan, std::string Text) :
	ExitButton(Button(sf::RectangleShape(sf::Vector2f(280.f, 60.f)), "Return to desktop", sf::Color(153, 153, 153), sf::Color(135, 206, 235), 15.f))
{
	StateMan = aStateMan;

	MenuFont.loadFromFile("PressStart2P-Regular.ttf");

	MenuText.setString(Text);
	MenuText.setFont(MenuFont);
	MenuText.setCharacterSize(25.f);

	MenuText.setFillColor(sf::Color(135, 206, 235));

	MenuText.setOrigin(sf::Vector2f(MenuText.getCharacterSize() / 2, 17.5f));

	MenuText.setPosition(sf::Vector2f((MenuText.getString().getSize() * MenuText.getCharacterSize())%(aStateMan->Window->getSize().x/8), 300.f));
	ExitButton.SetPosition(sf::Vector2f(300.f, 500.f));
}

void EndScreen::Draw(sf::RenderWindow* window)
{
	window->draw(MenuText);
	ExitButton.Draw(window);
}

void EndScreen::HandleEvents()
{
	sf::Event event;
	while (StateMan->Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			StateMan->Window->close();

		if (ExitButton.IsHovered(StateMan->Window))
		{
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
			{
				StateMan->Window->close();
			}
		}
	}
}
