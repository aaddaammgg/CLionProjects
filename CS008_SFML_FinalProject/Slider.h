//
// Created by Adam G. on 4/27/22.
//

#ifndef CS008_SFML_FINALPROJECT_SLIDER_H
#define CS008_SFML_FINALPROJECT_SLIDER_H

#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "MultiText.h"

class Slider : public GUIComponent {
private:
    float value = 0;
    MultiText label;
    MultiText labelValue;
    sf::RectangleShape box;
    sf::RectangleShape progressBox;
    sf::CircleShape dot;
public:
    Slider();
    Slider(std::string str, float initialValue = 0);

    float getValue() const;
    void setValue(float val);

    void setLabel(std::string str);

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
