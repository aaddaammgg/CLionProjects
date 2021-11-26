//
// Created by Adam G. on 11/24/2021.
//

#include "SFMLMainMenu_Scene.h"

SFMLMainMenu_Scene::SFMLMainMenu_Scene() {
    this->title.setFont(ResourceHolder::getFont("Roboto-Bold.ttf"));
    this->title.setString(SCENE_MAINMENU_TITLE);
    this->title.setFillColor(sf::Color(SCENE_MAINMENU_TITLE_COLOR));
    this->title.setCharacterSize(SCENE_MAINMENU_TITLE_SIZE);

    sf::FloatRect titleBounds = this->title.getGlobalBounds();
    this->title.setPosition(WINDOW_WIDTH / 2 - titleBounds.width / 2, 0);

    this->subTitle.setFont(ResourceHolder::getFont("Roboto-Bold.ttf"));
    this->subTitle.setString(SCENE_MAINMENU_SUBTITLE);
    this->subTitle.setFillColor(sf::Color(SCENE_MAINMENU_SUBTITLE_COLOR));
    this->subTitle.setCharacterSize(SCENE_MAINMENU_SUBTITLE_SIZE);
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

//    playButton.updateBounds();
//    quitButton.updateBounds();
}

void SFMLMainMenu_Scene::eventHandler(sf::RenderWindow &window, sf::Event event, ScenesENUM &scene) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2f mPos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

        if (playButton.getGlobalBounds().contains(mPos)) {
            scene = GAME_PLAYING;
        } else if (quitButton.getGlobalBounds().contains(mPos)) {
            window.close();
        }
    }

    playButton.eventHandler(window, event);
    quitButton.eventHandler(window, event);
}

void SFMLMainMenu_Scene::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(title);
    window.draw(subTitle);
    window.draw(playButton);
    window.draw(quitButton);
}

void SFMLMainMenu_Scene::update() {
    playButton.update();
    quitButton.update();
}
