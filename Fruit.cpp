#ifndef FRUIT_CPP
#define FRUIT_CPP
#include "Fruit.h"

Fruit::Fruit()
{
	shape.setSize(size);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition((this->x)*370+10, (this->y)*370+10);
	shape.setOutlineColor(sf::Color::Black);
	shape.setOutlineThickness(1.0f);
}

void Fruit::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}


float Fruit::top()
{
	return shape.getPosition().y;
}

float Fruit::bottom()
{
	return shape.getPosition().y + shape.getSize().y;
}

float Fruit::left()
{
	return shape.getPosition().x;
}

float Fruit::right()
{
	return shape.getPosition().x + shape.getSize().x;
}

void Fruit::changePosition()
{
	shape.setPosition(((float)(rand()) / (float)(RAND_MAX))*370+10, ((float)(rand()) / (float)(RAND_MAX)) * 370+10);
}

#endif