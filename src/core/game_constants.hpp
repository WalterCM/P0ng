
#ifndef GAME_CONSTANTS_HPP
#define GAME_CONSTANTS_HPP

#include <SFML/Graphics/Color.hpp>
#include <cstring>

const float FPS = 120;                          // Frames per second

const int WINDOW_WIDTH = 800;                   // Width on the window
const int WINDOW_HEIGHT = 600;                  // Height of the window

const std::string TITLE_STRING = "P0NG";        // Title of the game
const int TITLE_SIZE = 140;                     // Size of the title

// Position of the title
const float TITLE_POS_X = WINDOW_WIDTH / 2;
const float TITLE_POS_Y = WINDOW_HEIGHT / 4;

const int NUMBER_OPTIONS = 2;                   // Number of optiosn in the menu
const std::string OPTION[] = {"Play", "Quit"};  // Options' strings
const int OPTION_SIZE = 100;                    // Size of the options

// Position of each option
const float OPTION_POS_x = WINDOW_WIDTH / 2;
const float OPTION1_POS_Y[] = { WINDOW_HEIGHT * 9 / 16,
                                WINDOW_HEIGHT * 12 / 16};

const std::string GAME_FONT = "2Dumb.ttf";      // Font used in all the game
const sf::Color TEXT_COLOR = sf::Color::White;  // Color of the non selected option
// Color of selected option
const sf::Color TEXT_COLOR_SELECTED = sf::Color::Green;

const float BALL_BASE_SPEED = 3;                // Base speed for the ball
const float PADDLE_BASE_SPEED = 3;              // Base speed of the paddle.


#endif // GAME_CONSTANTS_HPP
