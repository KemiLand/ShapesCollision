#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "Shapes.h"

int main()
{
	sf::RenderWindow
		window(sf::VideoMode(500, 500), "My window 500x500 px");

	//-----------------------Shapes Sizes and Positions(X,Y)-----------------------//
	circle* objetCircle = new circle(50, 50, 50); // R , x , y

	Rectangle* objetRectangle = new Rectangle(100, 100, 200, 200); // L , H , x , y

	objetCircle->Sprite.setFillColor
	(sf::Color(100, 250, 50)); // Green

	objetRectangle->Sprite.setFillColor
	(sf::Color(24, 146, 209)); // Blue


	while (window.isOpen()) //Game Loop
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear();

		//Circle movement and speed
		float Speed = 0.10;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			objetCircle->Sprite.move(-Speed, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			objetCircle->Sprite.move(Speed, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			objetCircle->Sprite.move(0, -Speed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			objetCircle->Sprite.move(0, Speed);
		}

		//"Prohibiting" the circle to go out of the window
		if (objetCircle->Sprite.getPosition().x < 0)
		{
			objetCircle->Sprite.setPosition(sf::Vector2f(0.f, objetCircle->Sprite.getPosition().y));
		}

		if (objetCircle->Sprite.getPosition().y < 0)
		{
			objetCircle->Sprite.setPosition(sf::Vector2f(objetCircle->Sprite.getPosition().x, 0.f));
		}

		if (objetCircle->Sprite.getPosition().x > 400)
		{
			objetCircle->Sprite.setPosition(sf::Vector2f(400.f, objetCircle->Sprite.getPosition().y));
		}

		if (objetCircle->Sprite.getPosition().y > 400)
		{
			objetCircle->Sprite.setPosition(sf::Vector2f(objetCircle->Sprite.getPosition().x, 400.f));
		}

		
		//Collision happens
		if (objetCircle->isColliding(objetRectangle))
		{
			objetCircle->Sprite.setFillColor
			(sf::Color::Red);

			objetRectangle->Sprite.setFillColor
			(sf::Color::Red);
		}
		else
		{
			objetCircle->Sprite.setFillColor
			(sf::Color(100, 250, 50)); // Green

			objetRectangle->Sprite.setFillColor
			(sf::Color(24, 146, 209)); // Blue
		}

		window.draw(objetCircle->Sprite);
		window.draw(objetRectangle->Sprite);

		//end of the current frame, display of everything we have drawn
		window.display();
	}

	// Windows specifics
	system("pause");
	return 0;
}