#include <iostream>
#include "StateManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 800), "Breakout",sf::Style::Close + sf::Style::Titlebar);

    StateManager StateM(&window);

    sf::Time dt;
    sf::Clock MainClock;

    window.setFramerateLimit(60);

    while (window.isOpen())
    {

      dt = MainClock.restart();

      StateM.CheckForChange();

      StateM.HandleEventsSecene();

      StateM.UpdateScene(dt);

      StateM.DrawScene();

      std::cout << 1.f / dt.asSeconds() <<'\n';
    }

    return 0;
}