#ifndef GAME_CPP
#define GAME_CPP
#include"Game.h"


template <class T1, class T2>
bool Game::isIntersecting(T1& pl, T2& fr)
{
    return pl.top() + 0.5 <= fr.bottom() - 0.5 && pl.bottom() - 0.5 >= fr.top() + 0.5 && pl.left() + 0.5 <= fr.right() - 0.5 && pl.right() - 0.5 >= fr.left() + 0.5;
}


Game::Game(float height, float width)
{
    srand((unsigned int)time(NULL));

    window.create(sf::VideoMode(height, width), "Snake");
    
    this->gameStatus = true;

    if (!texture.loadFromFile("C:/Users/lukla/Pictures/grass.jpg"))
    {
        std::cout << "Error";
    }

    background.setTexture(texture);

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
            {
                this->gameStatus = false;
                window.close();
            }
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
            for (int i = 1; i <= blocks.size() - 1; i++)
            {
                blocks[i].tailUpdate(blocks[(i - 1)]);
            }
        }
        if (blocks[0].delayStatus() == true)
        {
            if (clock() >= blocks[0].startDelayStatus(0.21)) { blocks[0].delayActivation(); }
        }
        window.display();
    }
}

bool Game::gameStatusCheck()
{
    return this->gameStatus;
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    if (typeid(target) == typeid(this->frame))
        target.draw(this->frame, state);
    if (typeid(target) == typeid(this->background))
        target.draw(this->background, state);

}

#endif