#pragma once
#ifndef OPTIONS_H
#define OPTIONS_H
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<vector>
#include<iostream>
#include<typeinfo>


class Options : public sf::RenderWindow, public sf::Drawable
{
public:
	template<class T1, class T2>
	bool test(T1& render, T2& text);
	Options(float hight, float width);
	~Options() = default;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void optionsStatusChange();
	bool optionsStatus();
private:
	sf::RenderWindow optionsWindow;
	sf::Font font;
	sf::Text text;
	sf::RectangleShape shape;
	bool options = false;
};

#endif