#include "StationaryEntity.h"

StationaryEntity::StationaryEntity(sf::RectangleShape Rect, sf::Color color)
{
	Shape = Rect;

	Shape.setOrigin(Shape.getSize().x / 2, Shape.getSize().y / 2);

	Shape.setFillColor(color);
}

StationaryEntity::~StationaryEntity()
{
}