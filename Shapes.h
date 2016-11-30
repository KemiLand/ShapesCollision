#ifndef SHAPES_H
#define SHAPES_H

#include <SFML/Graphics.hpp>

class Shape
{
public:
	Shape(double x, double y);
	~Shape();

	virtual bool isColliding(Shape*) = 0;
	double GetX();
	double GetY();

protected:
	double x;
	double y;
};

class circle;

class Rectangle : public Shape
{
public:
	Rectangle(double width, double height, double x, double y);
	~Rectangle();

	bool Rectangle::isColliding(Shape*);
	bool Rectangle::isColliding(Rectangle*);
	bool Rectangle::isColliding(circle*);

	double GetWidth();
	double GetHeight();

	sf::RectangleShape Sprite;

private:
	double width;
	double height;
};

class circle : public Shape
{
public:
	circle(double r, double x, double y);
	~circle();

	bool circle::isColliding(Shape*);
	bool circle::isColliding(Rectangle*);
	bool circle::isColliding(circle*);

	double r;

	sf::CircleShape Sprite;
};

#endif //SHAPES_H