#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <iostream>
#include "game_state.hpp"

class MainMenu : public GameState
{
public:

    void init(sf::RenderWindow *window);
    void update(sf::RenderWindow *window);
    void draw(sf::RenderWindow *window);
    void destroy(sf::RenderWindow *window);

private:
    sf::Font *font;
    sf::Text *title;
    sf::Text ** option;

    int selected;
    bool upKey, downKey;
    bool wKey, sKey;
};

#endif // MAIN_MENU_HPP

