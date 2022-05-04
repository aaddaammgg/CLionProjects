//
// Created by Adam G. on 5/3/22.
//

#ifndef CS008_SFML_FINALPROJECT_COLORPICKER_H
#define CS008_SFML_FINALPROJECT_COLORPICKER_H

#include <SFML/Graphics.hpp>
#include <functional>
#include "GUIComponentAdapter.h"

class ColorPicker : public GUIComponentAdapter {
public:
    typedef enum {
        RED,
        GREEN,
        BLUE,
        YELLOW,
        ORANGE,
        BROWN,
        PURPLE,
        PINK,
        WHITE,
        BLACK,

        LAST_COLORS
    } COLOR;
private:
    sf::RectangleShape colors[LAST_COLORS];
    MultiText label;

    COLOR selected = RED;
    float boxSize = 28;
    static sf::Color getColor(COLOR c);
    void updateSize();
public:
    ColorPicker();

    sf::Color getColor();

    std::function<void(const sf::Color&)> callBack;
    void setCallBack(std::function<void(const sf::Color&)> cb);

    void setLabel(const std::string& str);
    void setLabelSize(unsigned int s);

    virtual void setSize(sf::Vector2f size);
    virtual void setPosition(sf::Vector2f pos);
    virtual Snapshot getSnapshot() {};
    virtual void applySnapshot(const Snapshot& snapshot) {};

    virtual void onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos);

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) override;
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void update();
};


#endif //CS008_SFML_FINALPROJECT_COLORPICKER_H
