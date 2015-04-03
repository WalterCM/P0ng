
#include "main_menu.hpp"
#include "../core/game_constants.hpp"
#include "main_game.hpp"

void MainMenu::init(sf::RenderWindow *window)
{
    font = new sf::Font();
    font->loadFromFile("Content/" + GAME_FONT);

    title = new sf::Text();

    title->setString(TITLE_STRING);
    title->setFont(*font);
    title->setCharacterSize(TITLE_SIZE);

    title->setColor(TEXT_COLOR);
    title->setOrigin(title->getGlobalBounds().width / 2,
                     title->getGlobalBounds().height / 2);
    title->setPosition(TITLE_POS_X, TITLE_POS_Y);

    option = new sf::Text*[NUMBER_OPTIONS];
    for (int i = 0; i < NUMBER_OPTIONS; i++) {
        option[i] = new sf::Text();
        option[i]->setString(OPTION[i]);
        option[i]->setFont(*font);
        option[i]->setCharacterSize(OPTION_SIZE);
        option[i]->setColor(TEXT_COLOR);
        option[i]->setOrigin(   option[i]->getGlobalBounds().width / 2,
                                option[i]->getGlobalBounds().height / 2);

        option[i]->setPosition(OPTION_POS_x, OPTION1_POS_Y[i]);
    }
}

void MainMenu::update(sf::RenderWindow *window)
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !upKey) ||
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && !wKey))
        selected--;
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !downKey) ||
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && !sKey))
        selected++;
    if (selected < 0)
        selected = NUMBER_OPTIONS - 1;
    else if (selected >= NUMBER_OPTIONS)
        selected = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
        switch (selected) {
        case 0:
            coreState.setState(new MainGame());
        break;
        case 1:
            quitGame = true;
        default:
            break;
        }
    }

    upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    wKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
    sKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
}

void MainMenu::draw(sf::RenderWindow *window)
{
    for (int i = 0; i < NUMBER_OPTIONS; i++) {
        option[i]->setColor(TEXT_COLOR);
    }

    option[selected]->setColor(TEXT_COLOR_SELECTED);

    window->draw(*title);
    for (int i = 0; i < NUMBER_OPTIONS; i++)
        window->draw(*option[i]);
}

void MainMenu::destroy(sf::RenderWindow *window)
{
    delete font;
    delete title;
    delete option;
}
