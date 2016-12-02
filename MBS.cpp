#include <iostream>
#include "Monster.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//Damage & winner aren't shown

int main()
{
	double m1PosX = 350.0;
	double m1PosY = 350.0;
	double m2PosX = 450.0;
	double m2PosY = 150.0;

	Monster m1 = Monster("Monster1.json", m1PosX, m1PosY);
	Monster m2 = Monster("Monster2.json", m2PosX, m2PosY);

	sf::RenderWindow window(sf::VideoMode(750, 750), "Monster Battle Simulator");

	while (window.isOpen()) //GameLoop
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		while (m1.getHealth() > 0.0 && m2.getHealth() > 0.0)
		{
			if (m1.getSpeed() > m2.getSpeed())
			{
				m1.attack(&m2);
				m2.attack(&m1);
			}
			else
			{
				m2.attack(&m1);
				m1.attack(&m2);
			}
		}

		window.clear();
		m1.draw(&window);
		m2.draw(&window);
		window.display();
	}

}