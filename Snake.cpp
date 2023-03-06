#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Fruit.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

clock_t endwait;

template <class T1, class T2>
bool isIntersecting(T1& pl, T2& fr)
{
    return pl.top()+0.5 <= fr.bottom()-0.5 && pl.bottom()-0.5 >= fr.top()+0.5 && pl.left()+0.5 <= fr.right()-0.5 && pl.right()-0.5 >= fr.left()+0.5;
}

int main()
{
    srand((unsigned int)time(NULL));
    sf::RenderWindow window(sf::VideoMode(400, 400), "Snake");

    sf::Texture texture;
    texture.loadFromFile("C:/Users/lukla/Pictures/grass.jpg");

    sf::Sprite background;
    background.setTexture(texture);
    
    sf::RectangleShape frame;
    frame.setSize(sf::Vector2f(380.0f, 380.0f));
    frame.setPosition(sf::Vector2f(10.0f, 10.0f));
    frame.setFillColor(sf::Color::Transparent);
    frame.setOutlineThickness(10.0f);
    frame.setOutlineColor(sf::Color::Yellow);

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

        //if (blocks.size() > 1)
        //{
        //    if (isIntersecting(blocks[0], blocks[1]))
        //        blocks[0].delayActivation();
        //}

        window.clear(sf::Color::White);

        window.draw(background);
        window.draw(frame);

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
        if (blocks[0].delayStatus() == true)
        {
            if (clock() >= blocks[0].startDelayStatus(0.21)) { blocks[0].delayActivation(); }
        }
        window.display();
    }

    return 0;
}