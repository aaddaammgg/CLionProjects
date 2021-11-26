//
// Created by Adam Gonzalez on 11/25/21.
//

#include "SFMLSceneSwitcher.h"

SFMLSceneSwitcher::SFMLSceneSwitcher() : SFMLSceneSwitcher(MAIN_MENU) {

}

SFMLSceneSwitcher::SFMLSceneSwitcher(ScenesENUM scene) {
    changeScene(scene);
}

void SFMLSceneSwitcher::eventHandler(sf::RenderWindow &window, sf::Event event) {
    ScenesENUM temp = LAST_SCENES;
    switch (getCurrentScene()) {
        case MAIN_MENU:
        default:
            mainMenuScene.eventHandler(window, event, temp);
            break;
        case GAME_PLAYING:
            gamePlayingScene.eventHandler(window, event, temp);
            break;
    }
    if (temp != LAST_SCENES) {
        changeScene(temp);
        sf::Cursor cursor;
        if (cursor.loadFromSystem(sf::Cursor::Arrow))
            window.setMouseCursor(cursor);
    }
}

void SFMLSceneSwitcher::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    switch (getCurrentScene()) {
        case MAIN_MENU:
        default:
            window.draw(mainMenuScene);
            break;
        case GAME_PLAYING:
            window.draw(gamePlayingScene);
            break;
    }
}

void SFMLSceneSwitcher::update() {
    switch (getCurrentScene()) {
        case MAIN_MENU:
        default:
            mainMenuScene.update();
            break;
        case GAME_PLAYING:
            gamePlayingScene.update();
            break;
    }
}
