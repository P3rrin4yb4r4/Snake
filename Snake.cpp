#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Fruit.h"
#include <vector>
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

bool isIntersecting(Player pl, Fruit fr)
{
    return pl.top() <= fr.bottom() && pl.bottom() >= fr.top() && pl.left() <= fr.right() && pl.right() >= fr.left();
}

int main()
{
    srand((unsigned int)time(NULL));
    sf::RenderWindow window(sf::VideoMode(400, 400), "Snake");

    Fruit fruit;

    std::vector<Player> blocks;
    blocks.emplace_back(200.0f, 200.0f);
    
    int x = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();

                if (event.key.code == sf::Keyboard::Key::Z)
                {
                   /* std::cout << blocks[(x)].getVelocity().x << ' ' << blocks[(x)].getVelocity().y << std::endl;
                    std::cout << blocks.size() << std::endl;*/
                }
            
        }

        if (isIntersecting(blocks[0], fruit))
        {
            if (blocks[x].horizDir() < 0)
                blocks.emplace_back(blocks[x].right(), blocks[x].top());

            if (blocks[x].horizDir() > 0)
                blocks.emplace_back(blocks[x].left() - blocks[x].blockSize(), blocks[x].top());

            if (blocks[x].verticDir() < 0)
                blocks.emplace_back(blocks[x].left(), blocks[x].bottom());

            if (blocks[x].verticDir() > 0)
                blocks.emplace_back(blocks[x].left(), blocks[x].top() - blocks[x].blockSize());
            fruit.changePosition();
            x++;
        }

        window.clear(sf::Color::White);

        for (auto block : blocks)
        {
            window.draw(block);
        }
        window.draw(fruit);

        blocks[0].update();
        
        if (blocks.size() > 1)
        {
            for (int i = 1; i <= blocks.size()-1; i++)
            {
                blocks[i].tailUpdate(blocks[(i-1)]);
            }
        }
        window.display();
    }

    return 0;
}