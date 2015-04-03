
#ifndef GAME_CONSTANTS_HPP
#define GAME_CONSTANTS_HPP

#include <SFML/Graphics/Color.hpp>
#include <cstring>

const float FPS = 60;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const std::string TITLE_STRING = "P0NG";
const int TITLE_SIZE = 140;
const float TITLE_POS_X = WINDOW_WIDTH / 2;
const float TITLE_POS_Y = WINDOW_HEIGHT / 4;

const int NUMBER_OPTIONS = 2;
const std::string OPTION[] = {"Play", "Quit"};
const int OPTION_SIZE = 100;

const float OPTION_POS_x = WINDOW_WIDTH / 2;
const float OPTION1_POS_Y[] = { WINDOW_HEIGHT * 9 / 16,
                                WINDOW_HEIGHT * 12 / 16};

const std::string GAME_FONT = "2Dumb.ttf";
const sf::Color TEXT_COLOR = sf::Color::White;
const sf::Color TEXT_COLOR_SELECTED = sf::Color::Green;

const float BALL_BASE_SPEED = 5;
const float PADDLE_BASE_SPEED = 5;


#endif // GAME_CONSTANTS_HPP
