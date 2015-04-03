
#include "game.hpp"
#include "game_constants.hpp"
#include "../states/main_menu.hpp"

StateManager coreState;
bool quitGame = false;

void Game::run()
{
    // Starts the window with the info in game_constants.hpp
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE_STRING);

    // Starts the state manager and gives it the window already created
    coreState.setWindow(window);
    // Starts the first state, the main menu
    coreState.setState(new MainMenu());

    // Starts the clock
    sf::Clock clock;

    while (window->isOpen()) {
        // Saves the elapsed time and events in the event queue
        sf::Time elapsed = clock.getElapsedTime();
        sf::Event event;

        // If user clicks on the X, close the window
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Each seconds, it runs "FPS" times
        if (elapsed.asSeconds() >= 1.0 / FPS) {
            window->clear(sf::Color::Black);

            // Update and draw the current state
            coreState.update();
            coreState.draw();

            window->display();

            // Restart the clock to use in the next frame
            clock.restart();
        }

        // Quits the game
        if (quitGame) {
            window->close();
        }
    }
}
