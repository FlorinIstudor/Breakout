#pragma once
#include "StationaryEntity.h"
#include "LinkedList.h"
#include <iostream>
#include "Utilities.h"
#include <vector>

class BreakMap
{
private:

	StationaryEntity* EntityMap[10][16];
	LinkedList<StationaryEntity>* BreakEntityList;

public:

	BreakMap();

	~BreakMap();

	void Draw(sf::RenderWindow* window);

	void Destroy(Node<StationaryEntity>* p);

	StationaryEntity* GetEntity(int i, int j);

	sf::Vector2i GetIndex(Node<StationaryEntity>* Node);

	LinkedList<StationaryEntity>* GetEntityList();
};

