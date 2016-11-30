#include <SFML/Graphics.hpp>
#include <cmath>

#include "Shapes.h"


Shape::Shape(double x, double y)
{
	this->x = x;
	this->y = y;
}

Shape::~Shape()
{
}

double Shape::GetX()
{
	return this->x;
}

double Shape::GetY()
{
	return this->y;
}


Rectangle::Rectangle(double width, double height, double x, double y) : Shape(x, y)
{
	this->width = width;
	this->height = height;

	sf::RectangleShape
		Image(sf::Vector2f(width, height));

	this->Sprite = Image;
	Sprite.setPosition(x, y);
}

Rectangle::~Rectangle()
{
}

bool Rectangle::isColliding(Shape* s)
{
	Rectangle* r = dynamic_cast <Rectangle*> (s);
	if (r != NULL)
	{
		return isColliding(r);
	}

	circle* c = dynamic_cast <circle*> (s);
	if (c != NULL)
	{
		return isColliding(c);
	}
}


bool Rectangle::isColliding(Rectangle* r)
{
	if ((this->Sprite.getPosition().x + this->width) < r->Sprite.getPosition().x ||
		this->Sprite.getPosition().x > (r->Sprite.getPosition().x + r->width))
	{
		return false;
	}

	if ((this->Sprite.getPosition().y + this->height) < r->Sprite.getPosition().y ||
		(r->Sprite.getPosition().y + r->height) < this->Sprite.getPosition().y)
	{
		return false;
	}

	return true;
}

bool Rectangle::isColliding(circle* c)
{
	return c->isColliding(this);
}

double Rectangle::GetHeight()
{
	return this->height;
}

double Rectangle::GetWidth()
{
	return this->width;
}


circle::circle(double r, double x, double y) : Shape(x, y)
{
	this->r = r;

	sf::CircleShape
		Image(r);

	this->Sprite = Image;
	Sprite.setPosition(x, y);
}

circle::~circle()
{
}

bool circle::isColliding(Shape* s)
{
	Rectangle* r = dynamic_cast <Rectangle*> (s);
	if (r != NULL)
	{
		return isColliding(r);
	}

	circle* c = dynamic_cast <circle*> (s);
	if (c != NULL)
	{
		return isColliding(c);
	}
}

bool circle::isColliding(Rectangle* r)
{
	double circleDistanceX = abs(this->Sprite.getPosition().x - r->Sprite.getPosition().x);
	double circleDistanceY = abs(this->Sprite.getPosition().y - r->Sprite.getPosition().y);

	if (circleDistanceX > (r->GetWidth() / 2.0 + this->r))
	{
		return false;
	}

	if (circleDistanceY > (r->GetHeight() / 2 + this->r))
	{
		return false;
	}
	return true;

	if (circleDistanceX <= (r->GetWidth() / 2))
	{
		return true;
	}

	if (circleDistanceY <= (r->GetHeight() / 2))
	{
		return true;
	}

	double cornerDistance = pow((circleDistanceX - r->GetWidth() / 2.0), 2.0) +
		pow((circleDistanceY - r->GetHeight() / 2.0), 2.0);
}

bool circle::isColliding(circle* c)
{
	double tempR = this->r + c->r;
	double tempX = this->Sprite.getPosition().x - c->Sprite.getPosition().x;
	double tempY = this->Sprite.getPosition().y - c->Sprite.getPosition().y;

	if (tempX < tempR)
	{
		return true;
	}

	if (tempY < tempR)
	{
		return true;
	}

	return false;
}