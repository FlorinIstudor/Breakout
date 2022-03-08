#pragma once
#include "Entity.h"

class MovableEntity : public Entity
{
private:
	float movementspeed;

public:
	MovableEntity(sf::RectangleShape Rect, float mvsp, sf::Color color);

	~MovableEntity();

	//functions

	void Move(sf::Time dt, float xdir, float ydir);

	void SetMVSP(float mvsp);

	float GetMVSP();
};

