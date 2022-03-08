#pragma once
#include "Entity.h"

class StationaryEntity : public Entity
{
private:

public:

	StationaryEntity(sf::RectangleShape Rect, sf::Color color);

	~StationaryEntity();
};

