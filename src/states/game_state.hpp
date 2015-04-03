#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

class GameState
{
public:
    GameState() {}

    virtual void init(sf::RenderWindow *window) {}
    virtual void update(sf::RenderWindow *window) {}
    virtual void draw(sf::RenderWindow *window) {}
    virtual void destroy(sf::RenderWindow *window) {}
};

class StateManager
{
public:
    StateManager() { this->state = NULL; }

    void setWindow(sf::RenderWindow *window)
    {
        this->window = window;
    }

    void setState(GameState *state)
    {
        if (this->state != NULL)
            this->state->destroy(this->window);
        this->state = state;
        if (this->state != NULL)
            this->state->init(this->window);
    }

    void update()
    {
        if (this->state != NULL)
            this->state->update(this->window);
    }

    void draw()
    {
        if (this->state != NULL)
            this->state->draw(this->window);
    }

    ~StateManager()
    {
        this->state->destroy(this->window);
    }

    void test()
    {
        std::cout << "test";
    }
protected:
private:
    GameState *state;
    sf::RenderWindow *window;
};

extern StateManager coreState;
extern bool quitGame;

#endif // GAME_STATE_HPP

