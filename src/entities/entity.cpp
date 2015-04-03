#include <iostream>
#include <cmath>
#include <cstring>
#include "entity.hpp"
#include "../core/game_constants.hpp"

Entity::Entity()
{
    texture = new sf::Texture();
}

void Entity::setPosition(float x, float y)
{
    // Sets the position on the window
    sf::Sprite::setPosition(x, y);

    // Saves the position of:
    // Top and bottom: the maximun and minimun 'y' coordinate
    // Left and right: the maximun and minimun 'x' coordinate
    top = this->getPosition().y;
    bottom = this->getPosition().y + this->getGlobalBounds().height;
    left = this->getPosition().x;
    right = this->getPosition().x + this->getGlobalBounds().width;
}

void Entity::load(std::string filename)
{
    // Loads the texture that obtains from a file on the Content folder
    texture->loadFromFile("Content/" + filename);
    // And uses it as the texture of the entity
    this->setTexture(*texture);
}

void Entity::update()
{
    // Updates the position of the entitiy based on its velocity
    this->move(velocity);

    // Updates the top, bottom, left and right variables
    top = this->getGlobalBounds().top;
    bottom = top + this->getGlobalBounds().height;
    left = this->getPosition().x;
    right = this->getPosition().x + this->getGlobalBounds().width;

    // Uses those variables to check if it left the window
    // If ti's true, bounce
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

void Entity::bounce(Entity *entity)
{
    // Check if it colldes from the left side of the specified entity and bounce
    if (this->collidesFromLeft(entity)) {
        std::cout << "IZQUIERDA\n";
        velocity.x = -abs(velocity.x) + entity->velocity.x;
        this->move(velocity.x, 0);
    }

    // Check if it colldes from the right side of the specified entity and bounce
    if (this->collidesFromRight(entity)) {
        std::cout << "DERECHA\n";
        velocity.x = abs(velocity.x) + entity->velocity.x;
        this->move(velocity.x , 0);
    }

    // Check if it colldes from the top side of the specified entity and bounce
    if (this->collidesFromAbove(entity)) {
        std::cout << "ARRIBA\n";
        velocity.y = -abs(velocity.y) + entity->velocity.y;
        this->move(0, velocity.y);
    }

    // Check if it colldes from the bottom side of the specified entity and bounce
    if (this->collidesFromBelow(entity)) {
        std::cout << "ABAJO\n";
        velocity.y = abs(velocity.y) + entity->velocity.y;
        this->move(0, velocity.y);
    }
}

bool Entity::collides(Entity *entity)
{
    return this->getGlobalBounds().intersects(entity->getGlobalBounds());
}

bool Entity::collidesFromAbove(Entity *entity)
{
    // Is it above now?
    bool above = (this->bottom < entity->top);
    // Will it enter the 'y' range next frame?
    bool yRange = (this->bottom + this->velocity.y >= entity->top + entity->velocity.y);

    // If it's above, and will collide next frame, return true
    return  above && yRange && insideXCoordinates(entity);
}

bool Entity::collidesFromBelow(Entity *entity)
{
    // Is it below now
    bool below = (this->top > entity->bottom);
    // Will it enter the 'y' range next frame?
    bool yRange = (this->top + this->velocity.y <= entity->bottom + entity->velocity.y);

    // If it's below, and will collide next frame, return true
    return below && yRange && insideXCoordinates(entity);
}

bool Entity::collidesFromLeft(Entity *entity)
{
    // Is it at the left now?
    bool left = (this->right < entity->left);
    // Will it enter the x range next frame?
    bool xRange =  (this->right + this->velocity.x >= entity->left + entity->velocity.x);

    // If it's at the left and will collide next frame, return true
    return left && xRange && insideYCoordinates(entity);
}

bool Entity::collidesFromRight(Entity *entity)
{
    // Is it at the right now?
    bool right = (this->left > entity->right);
    // Will it enter the 'y' range next frame?
    bool xRange = (this->left + this->velocity.x <= entity->right + entity->velocity.x);

    // If it's at the right and will collide next frame, return true
    return right && xRange && insideYCoordinates(entity);
}

Entity::~Entity()
{
    delete texture;
}

bool Entity::insideXCoordinates(Entity *entity)
{
    // Is the left side of the object inside the 'x' range of the second object?
    bool leftInside = (this->left <= entity->right && this->left >= entity->left);
    // Is the right side of the obejct inside the 'x' range of the seocnd object?
    bool rightInside = (this->right <= entity->right && this->right >= entity->left);

    // Will the left side of the obejct beinside the 'x' range of the second object in the next frame?
    bool futureLeftInside = (this->left + this->velocity.x <= entity->right + entity->velocity.x) &&
                            (this->left + this->velocity.x >= entity->left + entity->velocity.x);
    // Will the right side of the obejct beinside the 'x' range of the second object in the next frame?
    bool futureRightInside = (this->right + this->velocity.x <= entity->right + entity->velocity.x) &&
                              (this->right + this->velocity.x >= entity->left + entity->velocity.x);

    return leftInside || rightInside || futureLeftInside || futureRightInside;
}
bool Entity::insideYCoordinates(Entity *entity)
{
    // Is the top side of the object inside the 'y' range of the second object?
    bool topInside = (this->top <= entity->bottom && this->top >= entity-> top);
    // Is the bottom side of the obejct inside the 'y' range of the seocnd object?
    bool bottomInside = (this->bottom <= entity->bottom && this->bottom >= entity-> top);

    // Will the top side of the obejct beinside the 'y' range of the second object in the next frame?
    bool futureTopInside = (this->top + this->velocity.y <= entity->bottom + entity->velocity.y) &&
                            (this->top + this->velocity.y >= entity-> top + entity->velocity.y);
    // Will the bottom side of the obejct beinside the 'y' range of the second object in the next frame?
    bool futureBottomInside = (this->bottom + this->velocity.y <= entity->bottom + entity->velocity.y) &&
                               (this->bottom + this->velocity.y >= entity-> top + entity->velocity.y);

    return topInside || bottomInside || futureTopInside || futureBottomInside;
}
