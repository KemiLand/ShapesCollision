#include "Monster.h"
#include <fstream>
#include <streambuf>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

/*Incuding Json lib*/
#include "json.hpp"
using json = nlohmann::json;


Monster::Monster(std::string fileName, double x, double y)
{
	int tempMonsterRace;

	/*Setting Json config for use the lib*/
	std::ifstream json_file("Data/" + fileName);
	std::string json_str((std::istreambuf_iterator<char>(json_file)),
		std::istreambuf_iterator<char>());

	auto j3 = json::parse(json_str.c_str());
	auto jRace = json::parse(json_str.c_str());

	/*Setting the value for the monster*/
	tempMonsterRace = j3["RACE"];
	race = (MonsterType)tempMonsterRace;
	health = j3["HP"];
	attackPower = j3["AP"];
	defensivePower = j3["DP"];
	speed = j3["S"];
	this->PosX = x;
	this->PosY = y;

	if ((int)race == 1)
	{
		texture.loadFromFile("Data/orc.png");
		sprite.setTexture(texture);
		sprite.setScale(sf::Vector2f(0.2f, 0.2f));
		sprite.setPosition(x, y);
	}

	if ((int)race == 2)
	{
		texture.loadFromFile("Data/troll.png");
		sprite.setTexture(texture);
		sprite.setScale(sf::Vector2f(0.2f, 0.2f));
		sprite.setPosition(x, y);
	}

	if ((int)race == 3)
	{
		texture.loadFromFile("Data/goblin.png");
		sprite.setTexture(texture);
		sprite.setScale(sf::Vector2f(0.3f, 0.3f));
		sprite.setPosition(x, y);
	}
}

void Monster::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}

void Monster::attack(Monster *m)
{
	sf::Font font;
	sf::Text text;
	font.loadFromFile("arial.ttf");

	double damage = this->attackPower - m->defensivePower;

	if (damage < 0.0)
	{
		damage = 0.0;
	}

	/*Showing damage*/
	auto strDamage = std::to_string(damage);
	text.setString(strDamage);
	lostLife(damage, m);
}

void Monster::lostLife(double damage, Monster *m)
{
	m->health -= damage;
	if (m->health <= 0)
	{
		m->health = 0;
	}

}

MonsterType Monster::getRace()
{
	return race;
}


double Monster::getHealth()
{
	return health;
}

double Monster::getSpeed()
{
	return speed;
}

Monster::~Monster()
{
}
