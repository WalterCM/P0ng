#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "../states/game_state.hpp"

/*
 *  Principal class for the game
 *  It controls the main flow of the game and their states
*/
class Game
{
public:

    //Default constructor
    Game() {}

    // Runs the pong clone game starting from a menu
    void run();

    // Destructor. deletes the current window
    ~Game() { delete this->window; }

private:
    sf::RenderWindow *window;   // Main window for the GUI

};

#endif // GAME_HPP



