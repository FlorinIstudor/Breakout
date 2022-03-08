#include "Entity.h"

void Entity::setPosition(sf::Vector2f pos)
{
	Shape.setPosition(pos);
}

void Entity::Draw(sf::RenderWindow* window)
{
	window->draw(this->Shape);
}

sf::RectangleShape Entity::getRect()
{
	return Shape;
}
