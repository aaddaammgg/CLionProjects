//
// Created by Adam G. on 11/24/2021.
//

#include "SFMLMainMenu.h"

SFMLMainMenu::SFMLMainMenu() {
    this->title.setFont(ResourceHolder::getFont("Roboto-Bold.ttf"));
    this->title.setString(SCREEN_MAINMENU_TITLE);
    this->title.setFillColor(sf::Color(SCREEN_MAINMENU_TITLE_COLOR));
    this->title.setCharacterSize(SCREEN_MAINMENU_TITLE_SIZE);

    sf::FloatRect titleBounds = this->title.getGlobalBounds();
    this->title.setPosition(WINDOW_WIDTH / 2 - titleBounds.width / 2, 0);

    this->subTitle.setFont(ResourceHolder::getFont("Roboto-Bold.ttf"));
    this->subTitle.setString(SCREEN_MAINMENU_SUBTITLE);
    this->subTitle.setFillColor(sf::Color(SCREEN_MAINMENU_SUBTITLE_COLOR));
    this->subTitle.setCharacterSize(SCREEN_MAINMENU_SUBTITLE_SIZE);
    this->subTitle.rotate(90.f);

    sf::FloatRect subTitleBounds = this->subTitle.getGlobalBounds();
    this->subTitle.setPosition(WINDOW_WIDTH / 2 - subTitleBounds.width / 2 + 80, 70);

    playButton.setText("PLAY");
    playButton.setFillColor(sf::Color(BUTTON_BACKGROUND_COLOR));
    playButton.setTextColor(sf::Color(BUTTON_TEXT_COLOR));
    playButton.setCharSize(BUTTON_TEXT_SIZE);

    quitButton.setText("QUIT");
    quitButton.setFillColor(sf::Color(BUTTON_BACKGROUND_COLOR));
    quitButton.setTextColor(sf::Color(BUTTON_TEXT_COLOR));
    quitButton.setCharSize(BUTTON_TEXT_SIZE);

    sf::FloatRect playBounds = playButton.getGlobalBounds();
    sf::FloatRect quitBounds = quitButton.getGlobalBounds();
    playButton.setPosition((WINDOW_WIDTH / 2) - (playBounds.width / 2), (WINDOW_HEIGHT / 2) - playBounds.height - 15);
    quitButton.setPosition((WINDOW_WIDTH / 2) - (quitBounds.width / 2), (WINDOW_HEIGHT / 2)  + 15);

    playButton.updateBounds();
    quitButton.updateBounds();
}

void SFMLMainMenu::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f mPos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

        if (playButton.getGlobalBounds().contains(mPos)) {
            std::cout << "play button pressed" << std::endl;
        } else if (quitButton.getGlobalBounds().contains(mPos)) {
            exit(0);
        }
    }

    playButton.eventHandler(window, event);
    quitButton.eventHandler(window, event);
}

void SFMLMainMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(title);
    window.draw(subTitle);
    window.draw(playButton);
    window.draw(quitButton);
}

void SFMLMainMenu::update() {
    playButton.update();
    quitButton.update();
}
