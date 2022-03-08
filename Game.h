#pragma once

#include "BreakMap.h"
#include "MovableEntity.h"
#include "Scene.h"
#include "StateManager.h"
#include <math.h>
#include <string.h>
#include "EndScreen.h"

class GameMenu : public Scene
{
private:

	MovableEntity Ball, Pallete;
	BreakMap BrickMap;

	sf::Texture TopBarTx;

	sf::Font TextFont;
	sf::Text ScoreTxt, LivesTxt;

	int Score, Lives;
	float multiplier;

	sf::RectangleShape LeftCollider, RightCollider, UpCollider;

	float ballXDir, ballYDir;

	const float PI = 3.14f / 160.f;

public:

	GameMenu(StateManager* AStateMan);

	~GameMenu();

	void Update(sf::Time dt) override;

	void Draw(sf::RenderWindow* window) override;

	void HandleEvents() override;

	void HandleInput(sf::Time dt);

	void HandleBallCollision();

};