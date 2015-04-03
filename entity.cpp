#include <iostream>
#include <cmath>
#include <cstring>
#include "entity.hpp"
#include "game_constants.hpp"

Entity::Entity()
{
    texture = new sf::Texture();
}

void Entity::setPosition(float x, float y)
{
    sf::Sprite::setPosition(x, y);
    top = this->getPosition().y;
    bottom = this->getPosition().y + this->getGlobalBounds().height;
    left = this->getPosition().x;
    right = this->getPosition().x + this->getGlobalBounds().width;
}

void Entity::load(std::string filename)
{
    texture->loadFromFile("Content/" + filename);
    this->setTexture(*texture);
}

void Entity::update()
{

    this->move(velocity);

    top = this->getGlobalBounds().top;
    bottom = top + this->getGlobalBounds().height;
    left = this->getPosition().x;
    right = this->getPosition().x + this->getGlobalBounds().width;


    if (left <= 0) {
        velocity.x = abs(velocity.x);
        this->move(velocity.x, 0);
    }
    if (right >= WINDOW_WIDTH) {
        velocity.x = -abs(velocity.x);
        this->move(velocity.x, 0);
    }
    if (top <= 0) {
        velocity.y = abs(velocity.y);
        this->move(0, velocity.y);
    }
    if (bottom >= WINDOW_HEIGHT) {
        velocity.y = -abs(velocity.y);
        this->move(0, velocity.y);
    }
}


void Entity::checkCollision(Entity *entity)
{
    if (this->collidesFromLeft(entity)) {
        std::cout << "IZQUIERDA\n";
        velocity.x = -abs(velocity.x) + entity->velocity.x;
        this->move(2 * velocity.x, 0);
    }
    if (this->collidesFromRight(entity)) {
        std::cout << "DERECHA\n";
        velocity.x = abs(velocity.x) + entity->velocity.x;
        this->move(2 * velocity.x , 0);
    }
    if (this->collidesFromAbove(entity)) {
        std::cout << "ARRIBA\n";
        velocity.y = -abs(velocity.y) + entity->velocity.y;
        this->move(0, 2 * velocity.y);
    }
    if (this->collidesFromBelow(entity)) {
        std::cout << "ABAJO\n";
        velocity.y = abs(velocity.y) + entity->velocity.y;
        this->move(0, 2 * velocity.y);
    }
}

bool Entity::collides(Entity *entity)
{
    return this->getGlobalBounds().intersects(entity->getGlobalBounds());
}

bool Entity::collidesFromAbove(Entity *entity)
{
    bool above = (this->bottom < entity->top);
    bool collides = (this->bottom + this->velocity.y >= entity->top + entity->velocity.y);

    bool leftInside = (this->left <= entity->right && this->left >= entity->left);
    bool rightInside = (this->right <= entity->right && this->right >= entity->left);

    bool futureLeftInside = (this->left + this->velocity.x <= entity->right + entity->velocity.x) &&
                            (this->left + this->velocity.x >= entity->left + entity->velocity.x);
    bool futureRightInside = (this->right + this->velocity.x <= entity->right + entity->velocity.x) &&
                              (this->right + this->velocity.x >= entity->left + entity->velocity.x);

    return  above && collides && (leftInside || rightInside || futureLeftInside || futureRightInside);
}

bool Entity::collidesFromBelow(Entity *entity)
{
    bool below = (this->top > entity->bottom);
    bool collides = (this->top + this->velocity.y <= entity->bottom + entity->velocity.y);

    bool leftInside = (this->left <= entity->right && this->left >= entity->left);
    bool rightInside = (this->right <= entity->right && this->right >= entity->left);

    bool futureLeftInside = (this->left + this->velocity.x <= entity->right + entity->velocity.x) &&
                            (this->left + this->velocity.x >= entity->left + entity->velocity.x);
    bool futureRightInside = (this->right + this->velocity.x <= entity->right + entity->velocity.x) &&
                              (this->right + this->velocity.x >= entity->left + entity->velocity.x);

    return below && collides && (leftInside || rightInside || futureLeftInside || futureRightInside);
}

bool Entity::collidesFromLeft(Entity *entity)
{
    bool left = (this->right < entity->left);
    bool collides =  (this->right + this->velocity.x >= entity->left + entity->velocity.x);

    bool topInside = (this->top <= entity->bottom && this->top >= entity-> top);
    bool bottomInside = (this->bottom <= entity->bottom && this->bottom >= entity-> top);

    bool futureTopInside = (this->top + this->velocity.y <= entity->bottom + entity->velocity.y) &&
                            (this->top + this->velocity.y >= entity-> top + entity->velocity.y);
    bool futureBottomInside = (this->bottom + this->velocity.y <= entity->bottom + entity->velocity.y) &&
                               (this->bottom + this->velocity.y >= entity-> top + entity->velocity.y);

    return left && collides && (topInside || bottomInside || futureTopInside || futureBottomInside);
}

bool Entity::collidesFromRight(Entity *entity)
{
    bool right = (this->left > entity->right);
    bool collides = (this->left + this->velocity.x <= entity->right + entity->velocity.x);

    bool topInside = (this->top <= entity->bottom && this->top >= entity-> top);
    bool bottomInside = (this->bottom <= entity->bottom && this->bottom >= entity-> top);

    bool futureTopInside = (this->top + this->velocity.y <= entity->bottom + entity->velocity.y) &&
                            (this->top + this->velocity.y >= entity-> top + entity->velocity.y);
    bool futureBottomInside = (this->bottom + this->velocity.y <= entity->bottom + entity->velocity.y) &&
                               (this->bottom + this->velocity.y >= entity-> top + entity->velocity.y);

    return right && collides && (topInside || bottomInside || futureTopInside || futureBottomInside);
}

Entity::~Entity()
{
    delete texture;
}
