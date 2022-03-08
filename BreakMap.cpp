#include "BreakMap.h"

BreakMap::BreakMap()
{

	BreakEntityList = new LinkedList<StationaryEntity>();

	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			EntityMap[i][j] = new StationaryEntity(sf::RectangleShape(sf::Vector2f(40.f, 20.f)), sf::Color(255 / 8 * i, 0, 255 - 255 / 8 * i));
			EntityMap[i][j]->setPosition(sf::Vector2f(j * 43.f - 23.f, 400.f - i * 27.5f));
		}
	}

	for (int i = 0; i < 16; i++)
	{
		EntityMap[0][i] = EntityMap[9][i] = nullptr;
	}

	for (int i = 1; i < 7; i++)
	{
		EntityMap[i][0] = EntityMap[i][15] = nullptr;
	}

	for (int i = 1; i < 15; i++)
	{
		BreakEntityList->PushBack(EntityMap[1][i]);
		BreakEntityList->PushBack(EntityMap[8][i]);
	}



}

BreakMap::~BreakMap()
{
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			if(EntityMap[i][j])
				delete EntityMap[i][j];
		}
	}

	delete BreakEntityList;
}

void BreakMap::Draw(sf::RenderWindow* window)
{
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			if (EntityMap[i][j])
			{
				EntityMap[i][j]->Draw(window);
			}
		}
	}
}

void BreakMap::Destroy(Node<StationaryEntity>* p)
{
	sf::Vector2i v = GetIndex(p);

	if (EntityMap[v.x + 1][v.y] && !BreakEntityList->Contains(EntityMap[v.x + 1][v.y])) BreakEntityList->PushBack(EntityMap[v.x + 1][v.y]);
	if (EntityMap[v.x - 1][v.y] && !BreakEntityList->Contains(EntityMap[v.x - 1][v.y])) BreakEntityList->PushBack(EntityMap[v.x - 1][v.y]);
	if (EntityMap[v.x][v.y + 1] && !BreakEntityList->Contains(EntityMap[v.x][v.y + 1])) BreakEntityList->PushBack(EntityMap[v.x][v.y + 1]);
	if (EntityMap[v.x][v.y - 1] && !BreakEntityList->Contains(EntityMap[v.x][v.y - 1])) BreakEntityList->PushBack(EntityMap[v.x][v.y - 1]);

	EntityMap[v.x][v.y] = nullptr;
}

StationaryEntity* BreakMap::GetEntity(int i, int j)
{
	return nullptr;
}

sf::Vector2i BreakMap::GetIndex(Node<StationaryEntity>* Node)
{
	return sf::Vector2i(((400.f - Node->Data->getRect().getPosition().y) / 27.f), (Node->Data->getRect().getPosition().x + 23.f) / 43.f);
}

LinkedList<StationaryEntity>* BreakMap::GetEntityList()
{
	return BreakEntityList;
}
