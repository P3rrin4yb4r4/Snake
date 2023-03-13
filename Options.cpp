#ifndef OPTIONS_CPP
#define OPTIONS_CPP

#include "Options.h"

template<class T1, class T2>
bool Options::test(T1& render, T2& shape)
{
	return sf::Mouse::getPosition(render).x >= shape.getGlobalBounds().left && sf::Mouse::getPosition(render).x <= shape.getGlobalBounds().left + shape.getGlobalBounds().width
		&& sf::Mouse::getPosition(render).y >= shape.getGlobalBounds().top && sf::Mouse::getPosition(render).y <= shape.getGlobalBounds().top + shape.getGlobalBounds().height;
}

Options::Options(float height, float width)
{
	optionsWindow.create(sf::VideoMode(height, width), "Options");
	optionsStatusChange();

	if (!font.loadFromFile("C:/Users/lukla/source/repos/Snake/Font/arial-cufonfonts/ARIAL.TTF"))
	{
		std::cout << "Error";
	}

	std::vector<sf::RectangleShape> shape;
	for (int i = 0; i < 4; i++)
	{
		shape.emplace_back();
		shape[i].setSize(sf::Vector2f(15.0f, 15.0f));
		shape[i].setFillColor(sf::Color::Red);
	}
	shape[0].setPosition(sf::Vector2f((width / 2) + 20.0f, (height / 2) + 8.0f));
	shape[1].setPosition(sf::Vector2f((width / 2) + 100.0f, (height / 2) + 8.0f));
	shape[2].setPosition(sf::Vector2f((width / 2) + 20.0f, (height / 2) + 38.0f));
	shape[3].setPosition(sf::Vector2f((width / 2) + 100.0f, (height / 2) + 38.0f));

	std::vector<sf::Text> opcje;
	for (int i = 0; i < 3; i++)
	{
		opcje.emplace_back();
		opcje[i].setFont(font);
		opcje[i].setCharacterSize(24);
		opcje[i].setPosition(sf::Vector2f((width / 2) - 150, (height / 2) + (i * 30)));
		opcje[i].setFillColor(sf::Color::Yellow);
	}

	opcje[0].setString("Kolor weza: ");
	opcje[1].setString("Kolor owoca: ");
	opcje[2].setString("Wyjscie");

	while (optionsWindow.isOpen())
	{
		sf::Event ev;
		while (optionsWindow.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) || (test(optionsWindow, opcje[2]) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)))
			{
				optionsStatusChange();
				optionsWindow.close();
			}
			for (int i = 0; i < 4; i++)
			{
				if (test(optionsWindow, shape[i]))
				{
					shape[i].setOutlineThickness(2.0f);
					shape[i].setOutlineColor(sf::Color::White);
				}
				else
				{
					shape[i].setOutlineThickness(0.0f);
					shape[i].setOutlineColor(sf::Color::Transparent);
				}
			}
			if (test(optionsWindow, opcje[2]))
			{
				opcje[2].setFillColor(sf::Color::Red);
				
				if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
					optionsWindow.close();
			}
			else
				opcje[2].setFillColor(sf::Color::Yellow);
		}

		optionsWindow.clear(sf::Color::Black);

		for (auto x : opcje)
		{
			optionsWindow.draw(x);
		}

		for (auto y : shape)
		{
			optionsWindow.draw(y);
		}

		optionsWindow.display();
	}
}

void Options::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(typeid(target) == typeid(this->text))
		target.draw(this->text, states);
	if (typeid(target) == typeid(this->shape))
		target.draw(this->shape, states);
}

void Options::optionsStatusChange()
{
	this->options = !(this->options);
}

bool Options::optionsStatus()
{
	return options;
}











#endif