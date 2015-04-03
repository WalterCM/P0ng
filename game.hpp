#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "game_constants.hpp"
#include "game_state.hpp"
#include "main_menu.hpp"

StateManager coreState;
bool quitGame = false;

class Game
{
public:
    Game() {}

    void run()
    {
        window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Title");
        coreState.setWindow(window);
        coreState.setState(new MainMenu());

        sf::Clock clock;

        while (window->isOpen()) {

            sf::Time elapsed = clock.getElapsedTime();
            sf::Event event;
            while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window->close();
            }

            if (elapsed.asSeconds() >= 1.0 / FPS) {
                window->clear(sf::Color::Black);

                coreState.update();
                coreState.draw();

                window->display();

                clock.restart();
            }

            if (quitGame) {
                window->close();
            }
        }
    }
    ~Game() { delete this->window; }


private:

    sf::RenderWindow *window;

};

#endif // GAME_HPP



