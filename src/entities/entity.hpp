
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite
{
public:
    Entity();                           // Creates a new texture
    void setPosition(float, float);     // Sets the position and saves position varaible
    void load(std::string);             // Loads a texture and sets it for the entity
    virtual void update();              // Updates the position and bounces if outside the window

    void bounce(Entity *);              // Bounce against another entity

    bool collides(Entity *);            // Returns true if it collides with another entity

    bool collidesFromAbove(Entity *);   // Is it above and will collide next frame?
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

private:
    bool insideXCoordinates(Entity *entity);
    bool insideYCoordinates(Entity *entity);
};

#endif // ENTITY_HPP
