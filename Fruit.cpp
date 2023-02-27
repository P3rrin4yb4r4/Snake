#include "Fruit.h"

Fruit::Fruit()
{
	shape.setSize(size);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition((this->x)*390, (this->y)*390);
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
	shape.setPosition(((float)(rand()) / (float)(RAND_MAX))*390, ((float)(rand()) / (float)(RAND_MAX)) * 390);
}
