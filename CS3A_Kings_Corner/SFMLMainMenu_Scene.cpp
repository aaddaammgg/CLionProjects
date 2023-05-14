//
// Created by NAMEHERE on 11/24/2021.
//

#include "SFMLMainMenu_Scene.h"

sf::Color hsv(int hue, float sat, float val)
{
    hue %= 360;
    while (hue<0) hue += 360;

    if (sat<0.f) sat = 0.f;
    if (sat>1.f) sat = 1.f;

    if (val<0.f) val = 0.f;
    if (val>1.f) val = 1.f;

    int h = hue / 60;
    float f = float(hue) / 60 - h;
    float p = val*(1.f - sat);
    float q = val*(1.f - sat*f);
    float t = val*(1.f - sat*(1 - f));

    switch (h)
    {
        default:
        case 0:
        case 6: return sf::Color(val * 255, t * 255, p * 255);
        case 1: return sf::Color(q * 255, val * 255, p * 255);
        case 2: return sf::Color(p * 255, val * 255, t * 255);
        case 3: return sf::Color(p * 255, q * 255, val * 255);
        case 4: return sf::Color(t * 255, p * 255, val * 255);
        case 5: return sf::Color(val * 255, p * 255, q * 255);
    }
}

SFMLMainMenu_Scene::SFMLMainMenu_Scene() {
    this->title.setFont(ResourceHolder::getFont("resources/fonts/Roboto-Bold.ttf"));
    this->title.setString(SCENE_MAINMENU_TITLE);
    this->title.setFillColor(sf::Color(SCENE_MAINMENU_TITLE_COLOR));
    this->title.setCharacterSize(SCENE_MAINMENU_TITLE_SIZE);

    sf::FloatRect titleBounds = this->title.getGlobalBounds();
    this->title.setPosition(WINDOW_WIDTH / 2 - titleBounds.width / 2, 210);

    this->subTitle.setFont(ResourceHolder::getFont("resources/fonts/Roboto-Bold.ttf"));
    this->subTitle.setString(SCENE_MAINMENU_SUBTITLE);
    this->subTitle.setFillColor(sf::Color(SCENE_MAINMENU_SUBTITLE_COLOR));
    this->subTitle.setCharacterSize(SCENE_MAINMENU_SUBTITLE_SIZE);
    this->subTitle.rotate(90.f);

    sf::FloatRect subTitleBounds = this->subTitle.getGlobalBounds();
    this->subTitle.setPosition(WINDOW_WIDTH / 2 - subTitleBounds.width / 2 + 80, 280);

    this->credits.setFont(ResourceHolder::getFont("resources/fonts/Roboto-Bold.ttf"));
    this->credits.setString(SCENE_MAINMENU_CREDITS);
    this->credits.setFillColor(sf::Color(SCENE_MAINMENU_CREDITS_COLOR));
    this->credits.setCharacterSize(SCENE_MAINMENU_CREDITS_SIZE);

    sf::FloatRect creditsBounds = this->credits.getLocalBounds();
    this->credits.setOrigin(0, creditsBounds.height + creditsBounds.top);
    this->credits.setPosition(5, WINDOW_HEIGHT - 5);

    crown.setTexture(ResourceHolder::getTexture("resources/images/crown_sparkle.gif"));
    crown.setOrigin(crown.getLocalBounds().width / 2, 0);
    crown.setPosition(WINDOW_WIDTH / 2, 0);
    crown.setScale(.75, .75);

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
    playButton.setPosition((WINDOW_WIDTH / 2) - (playBounds.width / 2), (WINDOW_HEIGHT / 2 + 50) - playBounds.height - 15 + 100);
    quitButton.setPosition((WINDOW_WIDTH / 2) - (quitBounds.width / 2), (WINDOW_HEIGHT / 2 + 50)  + 15 + 100);

    this->spinningKings.setPosition(WINDOW_WIDTH / 2, (WINDOW_HEIGHT / 2) + playBounds.height + 100);

//    playButton.updateBounds();
//    quitButton.updateBounds();
}

void SFMLMainMenu_Scene::eventHandler(sf::RenderWindow &window, sf::Event event, ScenesENUM &scene) {
    playButton.eventHandler(window, event);
    quitButton.eventHandler(window, event);

    if (playButton.isClicked()) {
        scene = GAME_PLAYING;
    } else if (quitButton.isClicked()) {
        window.close();
    }
}

void SFMLMainMenu_Scene::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(crown);
    window.draw(title);
    window.draw(subTitle);

    window.draw(credits);

    window.draw(playButton);
    window.draw(quitButton);

    window.draw(spinningKings);
}

void SFMLMainMenu_Scene::update() {
    playButton.update();
    quitButton.update();
    spinningKings.update();

//    this->credits.setFillColor(sf::Color((time(nullptr) * 500) % 255, (time(nullptr) * 500) % 255, (time(nullptr) * 500) % 255));
//    this->credits.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    this->credits.setFillColor(hsv((time(nullptr) * 100) % 360, 1 , 1));
}
