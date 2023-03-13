#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Fruit.h"
#include "MenuWindow.h"
#include "Game.h"
#include "Options.h"


const float windowHeight{ 400.0f };
const float windowWidth{ 400.0f };

bool gameOn = true;
bool menu = true;
bool game = false;
bool options = false;
bool about = false;

int main()
{
    while (gameOn)
    {
        if (menu)
        {
            MenuWindow menuWindow(windowHeight, windowWidth);
            if (menuWindow.newGameModeStatus() && !menuWindow.menuModeStatus())
            {
                menu = false;
                game = true;
            }
            if (menuWindow.optionsModeStatus() && !menuWindow.menuModeStatus())
            {
                menu = false;
                options = true;
            }
            if (menuWindow.aboutModeStatus() && !menuWindow.menuModeStatus())
            {
                menu = false;
                about = true;
            }
            if (menuWindow.exitModeStatus() && !(menuWindow.aboutModeStatus() && menuWindow.optionsModeStatus() && menuWindow.newGameModeStatus() && menuWindow.menuModeStatus()))
            {
                break;
            }
        }
        if (game)
        {
            Game window(windowHeight, windowWidth);
            if (!window.gameStatusCheck())
            {
                game = false;
                menu = true;
            }
        }

        if (options)
        {
            Options opcje(windowHeight, windowWidth);
            if (!opcje.optionsStatus())
            {
                options = false;
                menu = true;
            }
        }
    }
    return 0;
}