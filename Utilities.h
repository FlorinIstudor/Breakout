#pragma once
#include "MovableEntity.h"
#include "StationaryEntity.h"
#include "BreakMap.h"

bool IsColliding(sf::RectangleShape FirstShape, sf::RectangleShape SecondShape);

bool IsOnSide(sf::RectangleShape FirstShape, sf::RectangleShape SecondShape);