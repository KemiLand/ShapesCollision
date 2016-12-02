#ifndef MONSTER_H //Monster.cpp
#define MONSTER_H

#include <string>
#include <SFML/Graphics.hpp>

enum class MonsterType
{
	ORC = 1,
	TROLL = 2,
	GOBLIN = 3,
};

class Monster
{
public:
	Monster(std::string fileName, double x, double y);
	void attack(Monster *m);
	double getSpeed();
	MonsterType getRace();
	double getHealth();
	~Monster();
	void draw(sf::RenderWindow*);
private:
	double health;
	double attackPower;
	double defensivePower;
	double speed;
	double damage;
	double PosX;
	double PosY;
	MonsterType race;
	int currentPlayer;
	sf::Texture texture;
	sf::Sprite sprite;
	std::string fileName;
	void lostLife(double damage, Monster *m);
};

#endif //MONSTER_H