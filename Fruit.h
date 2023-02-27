#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>

class Fruit : public sf::Drawable
{
public:
	Fruit();
	~Fruit() = default;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	float top();
	float bottom();
	float left();
	float right();
	void changePosition();
private:
	sf::Vector2f size{ 10.0,10.0 };
	sf::RectangleShape shape;
	float x = (float)(rand()) / (float)(RAND_MAX);
	float y = (float)(rand()) / (float)(RAND_MAX);
};

