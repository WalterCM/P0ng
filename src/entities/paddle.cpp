
#include "paddle.hpp"
#include "../core/game_constants.hpp"

Paddle::Paddle(int playerNumber)
{
    this->playerNumber = playerNumber;
    this->load("paddle.png");
    switch (this->playerNumber) {
    case 0:
        this->setColor(sf::Color::Red);
        break;

    default:
        this->setColor(sf::Color::Blue);
        break;
    }

    velocity.x = 0;
    velocity.y = 0;
}

void Paddle::update()
{
    switch (playerNumber) {
    case 0:
        velocity.y =    sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) -
                        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
        break;

    default:
        velocity.y =    sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) -
                        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
        break;
    }

    velocity.y *= PADDLE_BASE_SPEED;

    Entity::update();
}
