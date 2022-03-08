#include "Game.h"

GameMenu::GameMenu(StateManager* AStateMan) : Ball(MovableEntity(sf::RectangleShape(sf::Vector2f(10.f,10.f)),300.f,sf::Color::Red)), Pallete(MovableEntity(sf::RectangleShape(sf::Vector2f(100.f, 20.f)), 650.f, sf::Color::Red))
{

	StateMan = AStateMan;
	multiplier = 1.f;

	Score = 0;
	Lives = 3;

	TextFont.loadFromFile("PressStart2P-Regular.ttf");

	ScoreTxt.setFont(TextFont);
	LivesTxt.setFont(TextFont);

	ScoreTxt.setCharacterSize(30);
	LivesTxt.setCharacterSize(30);

	ScoreTxt.setString(std::to_string(Score));
	LivesTxt.setString(std::to_string(Lives));

	ScoreTxt.setPosition(sf::Vector2f(0.f,40.f));
	LivesTxt.setPosition(sf::Vector2f(490.f, 10.f));

	TopBarTx.loadFromFile("BreakoutTopBar.png");

	LeftCollider = RightCollider = sf::RectangleShape(sf::Vector2f(30.f,800.f));

	LeftCollider.setOrigin(sf::Vector2f(15.f,400.f));
	RightCollider.setOrigin(sf::Vector2f(15.f, 400.f));

	UpCollider = sf::RectangleShape(sf::Vector2f(600.f,90.f));
	UpCollider.setOrigin(sf::Vector2f(300.f, 45.f));

	LeftCollider.setPosition(sf::Vector2f(-15.f, 400.f));
	RightCollider.setPosition(sf::Vector2f(615.f, 400.f));
	UpCollider.setPosition(sf::Vector2f(300.f, 45.f));
	UpCollider.setTexture(&TopBarTx);

	ballXDir = 0.f;
	ballYDir = 1.f;

	Pallete.setPosition(sf::Vector2f(300.f,700.f));
	Ball.setPosition(sf::Vector2f(300.f, 400.f));
}

GameMenu::~GameMenu()
{
	
}

void GameMenu::Update(sf::Time dt)
{
	if (BrickMap.GetEntityList()->GetLen() == 0)
		StateMan->NextScene = new EndScreen(StateMan,"You have won!");

	if (Lives == 0)
		exit(0);

	HandleInput(dt);
	HandleBallCollision();

	Ball.Move(dt, ballXDir, ballYDir);
}

void GameMenu::Draw(sf::RenderWindow* window)
{
	window->draw(UpCollider);
	window->draw(ScoreTxt);
	window->draw(LivesTxt);

	Pallete.Draw(window);
	Ball.Draw(window);
	BrickMap.Draw(window);
}

void GameMenu::HandleEvents()
{
	sf::Event event;
	while (StateMan->Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			StateMan->Window->close();
	}
}

void GameMenu::HandleInput(sf::Time dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && Pallete.getRect().getPosition().x >= 0)
	{
		Pallete.Move(dt, -1.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && Pallete.getRect().getPosition().x <= 600)
	{
		Pallete.Move(dt, 1.f, 0.f);
	}
}

void GameMenu::HandleBallCollision()
{
	if (Ball.getRect().getPosition().y > 800.f)
	{
		Ball.SetMVSP(300.f);
		ballXDir = 0.f;
		ballYDir = 1.f;

		Ball.setPosition(sf::Vector2f(300.f,400.f));

		multiplier = 1.f;

		Lives--;
		LivesTxt.setString(std::to_string(Lives));

		return;
	}

	if (IsColliding(Pallete.getRect(), Ball.getRect()))
	{
		ballXDir = sin(PI * (Ball.getRect().getPosition().x - Pallete.getRect().getPosition().x));
		ballYDir = -1 * sqrt(1 - pow(ballYDir, 2));

		multiplier = 1.f;

		return;
	}

	if (IsColliding(UpCollider, Ball.getRect()))
	{
		ballYDir = abs(ballYDir);
	}

	if (IsColliding(LeftCollider, Ball.getRect()))
	{
		ballXDir = abs(ballXDir);
	}

	if (IsColliding(RightCollider, Ball.getRect()))
	{
		ballXDir = -1 * abs(ballXDir);
	}

	Node<StationaryEntity>* node;

	for (int i = 1; i <= BrickMap.GetEntityList()->GetLen(); i++)
	{
		node = BrickMap.GetEntityList()->GetNode(i);

		if (IsColliding(node->Data->getRect(), Ball.getRect()))
		{
			Score += 100.f * BrickMap.GetIndex(node).x * multiplier;

			Ball.SetMVSP(Ball.GetMVSP() > 500.f ? 500.f : Ball.GetMVSP() * 1.05f );

			ScoreTxt.setString(std::to_string(Score));

			if (IsOnSide(node->Data->getRect(), Ball.getRect()))
			{
				ballXDir = -1 * ballXDir;
			}
			else
			{
				ballYDir = -1 * ballYDir;
			}
			BrickMap.Destroy(node);
			BrickMap.GetEntityList()->DeleteNode(node);
			i--;
			
			multiplier += 0.05f;

			return;
		}
	}
}

/*void BreakMap::UpdateCollision(sf::RectangleShape rect)
{
	Node<StationaryEntity>* node;

	for (int i = 1; i <= BreakEntityList->GetLen(); i++)
	{
		node = BreakEntityList->GetNode(i);

		if (IsColliding(node->Data->getRect(), rect))
		{
			Destroy(node);
			BreakEntityList->DeleteNode(node);
			i--;
		}
	}
}*/