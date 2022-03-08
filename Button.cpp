#include "Button.h"

Button::Button(sf::RectangleShape aButtonShape, std::string Text, sf::Color aButtonColor, sf::Color aTextColor, int CSz)
{
	ButtonFont.loadFromFile("PressStart2P-Regular.ttf");

	ButtonText.setString(Text);
	ButtonText.setFont(ButtonFont);
	ButtonText.setCharacterSize(CSz);

	ButtonShape = aButtonShape;

	ButtonShape.setOrigin(sf::Vector2f(ButtonShape.getSize().x / 2, ButtonShape.getSize().y / 2));
	ButtonText.setOrigin(sf::Vector2f(ButtonText.getCharacterSize() * ButtonText.getString().getSize() / 2, ButtonText.getCharacterSize() / 2));

	ButtonColor = aButtonColor;
	TextColor = aTextColor;

	ButtonShape.setFillColor(ButtonColor);
	ButtonText.setFillColor(TextColor);
}

Button::~Button()
{

}

void Button::SetPosition(sf::Vector2f poz)
{
	ButtonShape.setPosition(poz);
	ButtonText.setPosition(poz);
}

void Button::Draw(sf::RenderWindow* window)
{
	window->draw(ButtonShape);
	window->draw(ButtonText);
}

bool Button::IsHovered(sf::RenderWindow* window)
{
	if (sf::Mouse::getPosition(*window).x >= ButtonShape.getPosition().x - ButtonShape.getSize().x / 2 && sf::Mouse::getPosition(*window).x <= ButtonShape.getPosition().x + ButtonShape.getSize().x / 2
		&& sf::Mouse::getPosition(*window).y >= ButtonShape.getPosition().y - ButtonShape.getSize().y / 2 && sf::Mouse::getPosition(*window).y <= ButtonShape.getPosition().y + ButtonShape.getSize().y / 2)
	{
		if (ButtonShape.getFillColor() != sf::Color(ButtonColor.r * 0.5, ButtonColor.g * 0.5, ButtonColor.b * 0.5))
			ButtonShape.setFillColor(sf::Color(ButtonColor.r * 0.5, ButtonColor.g * 0.5, ButtonColor.b * 0.5));
		return true;
	}

	if (ButtonShape.getFillColor() != ButtonColor)
		ButtonShape.setFillColor(ButtonColor);

	return false;
}