
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite
{
public:
    Entity();
    void setPosition(float, float);
    void load(std::string);
    virtual void update();

    void checkCollision(Entity *);

    bool collides(Entity *);

    bool collidesFromAbove(Entity *);
    bool collidesFromBelow(Entity *);
    bool collidesFromLeft(Entity *);
    bool collidesFromRight(Entity *);

    ~Entity();

    float top;
    float bottom;
    float left;
    float right;
protected:
    sf::Texture *texture;
    sf::Vector2f velocity;
    bool moving = true;
};


#endif // ENTITY_HPP
