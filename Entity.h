#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

class Entity
{
protected:
	sf::RectangleShape Shape;

public:
	Entity() {};
	~Entity() {};

	void setPosition(sf::Vector2f pos);
	void Draw(sf::RenderWindow* window);
	sf::RectangleShape getRect();
};

