#ifndef MENUWINDOW_CPP
#define MENUWINDOW_CPP
#include "MenuWindow.h"

template<class T1, class T2>
bool MenuWindow::test(T1& render, T2& text)
{
	return sf::Mouse::getPosition(render).x >= text.getGlobalBounds().left && sf::Mouse::getPosition(render).x <= text.getGlobalBounds().left + text.getGlobalBounds().width
		&& sf::Mouse::getPosition(render).y >= text.getGlobalBounds().top && sf::Mouse::getPosition(render).y <= text.getGlobalBounds().top + text.getGlobalBounds().height;
}

MenuWindow::MenuWindow(float height, float width)
{
	menuWindow.create(sf::VideoMode(height, width), "Menu");
	
	this->menu = true;

	if (!font.loadFromFile("C:/Users/lukla/source/repos/Snake/Font/arial-cufonfonts/ARIAL.TTF"))
	{
		std::cout << "Error";
	}

	std::vector<sf::Text> options;
	for (int i = 0; i < 4; i++)
	{
		options.emplace_back();
		options[i].setCharacterSize(24);
		options[i].setFillColor(sf::Color::Yellow);
		options[i].setPosition(sf::Vector2f((height / 2) - 100, (width / 2) + (i * 30)));
		options[i].setFont(font);
	}
	options[0].setString("Nowa gra");

	options[1].setString("Ustawienia");

	options[2].setString("O autorze");

	options[3].setString("Wyjscie");

	while (menuWindow.isOpen())
	{
		sf::Event e;
		while (menuWindow.pollEvent(e))
		{
			if (e.type == sf::Event::Closed || (test(menuWindow, options[3]) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)))
			{
				this->menu = false;
				menuWindow.close();
				this->exit = true;
			}
			for (int i = 0; i < 4; i++)
			{
				if (test(menuWindow, options[i]))
					options[i].setFillColor(sf::Color::Red);
				else
				{
					options[i].setFillColor(sf::Color::Yellow);
				}
			}
			if (test(menuWindow, options[0]) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				this->menu = false;
				this->newGameMode = true;
				menuWindow.close();
			}
			else
				this->newGameMode = false;
			if (test(menuWindow, options[1]) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				this->menu = false;
				this->optionsMode = true;
				menuWindow.close();
			}
			else
				this->optionsMode = false;
			if (test(menuWindow, options[2]) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				this->menu = false;
				this->aboutMode = true;
				menuWindow.close();
			}
			else
				this->aboutMode = false;
		}
		menuWindow.clear(sf::Color::Black);

		for (auto write : options)
		{
			menuWindow.draw(write);
		}
		menuWindow.display();
	}
}

void MenuWindow::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->text, state);
}

bool MenuWindow::menuModeStatus()
{
	return this->menu;
}

void MenuWindow::menuModeChange()
{
	this->menu = !(this->menu);
}

bool MenuWindow::newGameModeStatus()
{
	return this->newGameMode;
}

void MenuWindow::newGameModeChange()
{
	this->newGameMode = !(this->newGameMode);
}

bool MenuWindow::optionsModeStatus()
{
	return this->optionsMode;
}

void MenuWindow::optionsModeChange()
{
	this->optionsMode = !(this->optionsMode);
}

bool MenuWindow::aboutModeStatus()
{
	return this->aboutMode;
}

void MenuWindow::aboutModeChange()
{
	this->aboutMode = !(this->aboutMode);
}

bool MenuWindow::exitModeStatus()
{
	return this->exit;
}

void MenuWindow::exitModeChange()
{
	this->exit = !(this->exit);
}





#endif