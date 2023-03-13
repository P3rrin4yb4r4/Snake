#ifndef GAME_H
#define GAME_H
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include"Fruit.h"
#include"Player.h"

class Game : public sf::RenderWindow, sf::Drawable
{
public:
	Game(float height, float width);
	~Game() = default;

	template <class T1, class T2>
	bool isIntersecting(T1& pl, T2& fr);
	bool gameStatusCheck();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	bool gameStatus = false;
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite background;
	sf::RectangleShape frame;

};
#endif