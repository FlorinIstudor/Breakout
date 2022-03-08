#include "Utilities.h"

bool IsColliding(sf::RectangleShape FirstShape, sf::RectangleShape SecondShape)
{
	float xdist = abs(FirstShape.getPosition().x - SecondShape.getPosition().x);
	float ydist = abs(FirstShape.getPosition().y - SecondShape.getPosition().y);

	if (xdist < (FirstShape.getSize().x + SecondShape.getSize().x) / 2 && ydist < (FirstShape.getSize().y + SecondShape.getSize().y) / 2)
		return true;

	return false;
}

bool IsOnSide(sf::RectangleShape FirstShape, sf::RectangleShape SecondShape)
{
	float x1 = FirstShape.getPosition().x;
	float y1 = FirstShape.getPosition().y;

	float x2 = SecondShape.getPosition().x;
	float y2 = SecondShape.getPosition().y;

	if (y2 < y1 + FirstShape.getSize().y /2 + SecondShape.getSize().y /2 && y2 > y1 - FirstShape.getSize().y / 2 - SecondShape.getSize().y / 2 && (x2 >= x1 + FirstShape.getSize().x + SecondShape.getSize().x) || (x2 <= x1 - FirstShape.getSize().x - SecondShape.getSize().x))
		return true;

	return false;
}
