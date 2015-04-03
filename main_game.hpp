
#ifndef MAIN_GAME_HPP
#define MAIN_GAME_HPP

#include <iostream>

#include "game_state.hpp"
#include "paddle.hpp"
#include "ball.hpp"

class MainGame : public GameState
{
public:
    MainGame() {}

    void init(sf::RenderWindow *window);
    void update(sf::RenderWindow *window);
    void draw(sf::RenderWindow *window);
    void destroy(sf::RenderWindow *window);

private:
    sf::RectangleShape *line;

    Paddle *paddle0;
    Paddle *paddle1;
    Ball *ball;
};


#endif // MAIN_GAME_HPP
