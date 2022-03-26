//
// Created by Adam G. on 3/21/2022.
//

#ifndef CS008_SFML_TYPING_CURSORBLINK_H
#define CS008_SFML_TYPING_CURSORBLINK_H

#include <SFML/Graphics.hpp>
#include "GUIComponent.h"

class CursorBlink : public GUIComponent {
private:
    sf::RectangleShape line;
    sf::Clock blinkFrequency;
    int index = 0;
public:
    CursorBlink();

    int getIndex() const;
    void setIndex(int index);

    void setSize(sf::Vector2f size);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event) {};
    void update();
};


#endif //CS008_SFML_TYPING_CURSORBLINK_H
