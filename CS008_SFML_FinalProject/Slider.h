//
// Created by Adam G. on 4/27/22.
//

#ifndef CS008_SFML_FINALPROJECT_SLIDER_H
#define CS008_SFML_FINALPROJECT_SLIDER_H

#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "Label.h"

class Slider : public GUIComponent {
private:
    float value = 0;
    Label label;
    sf::RectangleShape box;
    sf::CircleShape dot;
public:
    Slider();

    float getValue() const;
    void setValue(float val);

    virtual void setSize(sf::Vector2f size);
    virtual void onMouseMoved(sf::Vector2f pos);
    virtual void onMousePressed(sf::Mouse::Button button, sf::Vector2f pos);
    virtual void onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos);
    virtual void onKeyPressed(const sf::Event::KeyEvent& key);

    virtual Snapshot getSnapshot() {};
    virtual void applySnapshot(const Snapshot& snapshot) {};

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
};


#endif //CS008_SFML_FINALPROJECT_SLIDER_H
