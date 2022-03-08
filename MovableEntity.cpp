#include "MovableEntity.h"

MovableEntity::MovableEntity(sf::RectangleShape Rect, float mvsp, sf::Color color)
{
	Shape = Rect;
	movementspeed = mvsp;

	Shape.setOrigin(Shape.getSize().x / 2, Shape.getSize().y / 2);

	Shape.setFillColor(color);
}

MovableEntity::~MovableEntity()
{
}

void MovableEntity::Move(sf::Time dt, float xdir, float ydir)
{
	Shape.move(dt.asSeconds() * xdir * movementspeed, dt.asSeconds() * ydir * movementspeed);
}

void MovableEntity::SetMVSP(float mvsp)
{
	movementspeed = mvsp;
}

float MovableEntity::GetMVSP()
{
	return movementspeed;
}
