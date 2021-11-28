//
// Created by Adam Gonzalez on 11/25/21.
//

#include "SFMLGamePlaying_Scene.h"

SFMLGamePlaying_Scene::SFMLGamePlaying_Scene() {
    this->title.setFont(ResourceHolder::getFont("Roboto-Bold.ttf"));
    this->title.setString(SCENE_GAMEPLAYING_TITLE);
    this->title.setFillColor(sf::Color(SCENE_GAMEPLAYING_TITLE_COLOR));
    this->title.setCharacterSize(SCENE_GAMEPLAYING_TITLE_SIZE);
    sf::FloatRect titleBounds = this->title.getGlobalBounds();
    this->title.setPosition(WINDOW_WIDTH / 2 - titleBounds.width / 2, 0);

    exitButton.setText("<--");
    exitButton.setFillColor(sf::Color(BUTTON_BACKGROUND_COLOR));
    exitButton.setTextColor(sf::Color(BUTTON_TEXT_COLOR));
    exitButton.setCharSize(BUTTON_TEXT_SIZE);
    exitButton.setPosition(15, 15);

    refreshButton.setText("REFRESH");
    refreshButton.setFillColor(sf::Color(BUTTON_BACKGROUND_COLOR));
    refreshButton.setTextColor(sf::Color(BUTTON_TEXT_COLOR));
    refreshButton.setCharSize(BUTTON_TEXT_SIZE);
    refreshButton.setPosition(100, WINDOW_HEIGHT / 2);
}

void SFMLGamePlaying_Scene::eventHandler(sf::RenderWindow &window, sf::Event event, ScenesENUM &scene) {
    exitButton.eventHandler(window, event);
    refreshButton.eventHandler(window, event);

    if (exitButton.isClicked()) {
        scene = MAIN_MENU;
    } else if (refreshButton.isClicked()) {
        deck = Deck();
        deck.shuffle();
        chTest = CardHand();
        for (int k = 0; k < 5; k++) {
            chTest.addCard(deck.dealCard());
        }

        sfmlCardHand = SFMLCardHand(chTest);
        sfmlCardHand.setPosition(100, WINDOW_HEIGHT / 2 + 70);
    }
}

void SFMLGamePlaying_Scene::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(title);
    window.draw(exitButton);
    window.draw(refreshButton);
    window.draw(sfmlCardHand);
}

void SFMLGamePlaying_Scene::update() {
    exitButton.update();
    refreshButton.update();
}
