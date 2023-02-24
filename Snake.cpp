#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Snake");

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
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Key::Space)
                {
                    if (blocks[x].horizDir() < 0)
                        blocks.emplace_back(blocks[x].right(), blocks[x].top());

                    if (blocks[x].horizDir() > 0)
                        blocks.emplace_back(blocks[x].left() - blocks[x].blockSize(), blocks[x].top());

                    if (blocks[x].verticDir() < 0)
                        blocks.emplace_back(blocks[x].left(), blocks[x].bottom());

                    if (blocks[x].verticDir() > 0)
                        blocks.emplace_back(blocks[x].left(), blocks[x].top() - blocks[x].blockSize());
                    
                    blocks[(x + 1)].setVelocity(blocks[x].getVelocity());

                    x++;
                }

                if (event.key.code == sf::Keyboard::Key::Z)
                {
                    std::cout << blocks[(x)].getVelocity().x << ' ' << blocks[(x)].getVelocity().y << std::endl;
                    std::cout << blocks.size() << std::endl;
                }
            }
        }

        window.clear(sf::Color::White);

        for (auto block : blocks)
        {
            window.draw(block);
        }

        blocks[0].update();
        
        if (blocks.size() > 1)
        {
            for (int i = 1; i <= blocks.size()-1; i++)
            {
                blocks[i].tailUpdate(blocks[i-1]);
            }
        }
        window.display();
    }

    return 0;
}