
#include "main_game.hpp"
#include "main_menu.hpp"

#include "../core/game_constants.hpp"

void MainGame::init(sf::RenderWindow *window)
{
    paddle0 = new Paddle(0);
    paddle1 = new Paddle(1);
    paddle1->setPosition(window->getSize().x - paddle1->getGlobalBounds().width, 0);

    ball = new Ball(paddle0, paddle1);
    ball->setPosition(window->getSize().x / 2, window->getSize().y / 2);

    line = new sf::RectangleShape(sf::Vector2f(window->getSize().y, 5));
    line->setPosition(window->getSize().x / 2, 0);
    line->rotate(90);
    line->setFillColor(sf::Color::White);
}

void MainGame::update(sf::RenderWindow *window)
{
    paddle0->update();
    paddle1->update();
    ball->update();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        coreState.setState(new MainMenu());

    if (ball->left <= 0 || ball->right >= WINDOW_WIDTH)
        coreState.setState(new MainMenu());
}

void MainGame::draw(sf::RenderWindow *window)
{
    window->draw(*line);
    window->draw(*paddle0);
    window->draw(*paddle1);
    window->draw(*ball);
}

void MainGame::destroy(sf::RenderWindow *window)
{
    delete line;
    delete paddle0;
    delete paddle1;
    delete ball;
}
