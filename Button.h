#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Button
{
private:
	sf::RectangleShape ButtonShape;
	sf::Text ButtonText;
	sf::Font ButtonFont;

	sf::Color ButtonColor, TextColor;

public:

	Button(sf::RectangleShape aButtonShape, std::string Text, sf::Color aButtonColor, sf::Color aTextColor, int CSz);

	~Button();

	void SetPosition(sf::Vector2f poz);

	void Draw(sf::RenderWindow* window);

	bool IsHovered(sf::RenderWindow* window);
};

