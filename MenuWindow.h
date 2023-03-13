#pragma once
#ifndef MENUWIDNOW_H
#define MENUWIDNOW_H

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include<vector>

class MenuWindow : public sf::RenderWindow, public sf::Drawable
{
public:
	template<class T1, class T2>
	bool test(T1& render, T2& text);
	MenuWindow(float height, float width);
	~MenuWindow() = default;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool menuModeStatus();
	void menuModeChange();
	bool newGameModeStatus();
	void newGameModeChange();
	bool optionsModeStatus();
	void optionsModeChange();
	bool aboutModeStatus();
	void aboutModeChange();
	bool exitModeStatus();
	void exitModeChange();
private:
	sf::RenderWindow menuWindow;
	sf::Font font;
	sf::Text text;
	bool menu = true;
	bool newGameMode = false;
	bool optionsMode = false;
	bool aboutMode = false;
	bool exit = false;
};

#endif
