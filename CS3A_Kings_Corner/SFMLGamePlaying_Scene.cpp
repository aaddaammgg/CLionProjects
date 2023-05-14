//
// Created by NAMEHERE on 11/25/21.
//

#include "SFMLGamePlaying_Scene.h"

SFMLGamePlaying_Scene::SFMLGamePlaying_Scene() {
    this->title.setFont(ResourceHolder::getFont("resources/fonts/Roboto-Bold.ttf"));
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

    newGameButton.setText("RESTART");
    newGameButton.setFillColor(sf::Color(BUTTON_BACKGROUND_COLOR));
    newGameButton.setTextColor(sf::Color(BUTTON_TEXT_COLOR));
    newGameButton.setCharSize(BUTTON_TEXT_SIZE);

    sf::FloatRect newGameBounds = newGameButton.getGlobalBounds();

//    std::cout << "width : " << newGameBounds.width << std::endl;

    newGameButton.setPosition(WINDOW_WIDTH - 252 - 15, 15);

    compass = SFMLCompass();
    compass.init();
    compass.setPosition({WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});

//    turnOrder = SFMLGameTurnOrder();
//    turnOrder.setPosition({WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
//    turnOrder.addPlayer(compass.getCompassCardPiles().getDeck());
}

void SFMLGamePlaying_Scene::eventHandler(sf::RenderWindow &window, sf::Event event, ScenesENUM &scene) {
    exitButton.eventHandler(window, event);
    newGameButton.eventHandler(window, event);
    compass.eventHandler(window, event);
//    turnOrder.eventHandler(window, event);
//    sfmlCardPile.eventHandler(window, event);


    if (exitButton.isClicked()) {
        scene = MAIN_MENU;
    } else if (newGameButton.isClicked()) {
        compass = SFMLCompass();
        compass.init();
        compass.setPosition({WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});

//        turnOrder = SFMLGameTurnOrder();
//        turnOrder.setPosition({WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
//        turnOrder.addPlayer(compass.getCompassCardPiles().getDeck());

//        compass.getCompassCardPiles().get

//        deck = Deck();
//        deck.shuffle();
//        cpTest = CardPile();
//
//        for (int k = 0; k < 5; k++) {
//            cpTest.addCard(deck.dealCard());
//        }
//
//        cpTest.sort();
//
//        std::cout << cpTest << std::endl;
//
//        sfmlCardPile = SFMLCardPile(cpTest);
//        sfmlCardPile.setOrigin({sfmlCardPile.getBounds().width / 2, sfmlCardPile.getBounds().height / 2});
//
//        sfmlCardPile.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
//        sfmlCardPile.setRotation(45.f);
    }
//    else if (sfmlCardPile.mouseButtonReleased(false)) {
//        std::cout << "test" << std::endl;
////        sfmlCardPile.rotate(45.f);
//    }
}

void SFMLGamePlaying_Scene::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(title);
    window.draw(exitButton);
    window.draw(newGameButton);
    window.draw(compass);
//    window.draw(turnOrder);
//    window.draw(sfmlCardPile);
}

void SFMLGamePlaying_Scene::update(sf::RenderWindow& window) {
    exitButton.update();
    newGameButton.update();
    compass.update(window);
//    turnOrder.update(window);
//    compass.rotate(0.5);
//    sfmlCardPile.update(window);
}
