//
// Created by Adam G. on 5/2/2022.
//

#ifndef CS008_SFML_FINALPROJECT_DISPLAYLOGO_H
#define CS008_SFML_FINALPROJECT_DISPLAYLOGO_H

#include <SFML/Graphics.hpp>
#include "GUIComponentAdapter.h"

class DisplayLogo : public GUIComponentAdapter {
private:
    sf::RectangleShape box;
    MultiText logo;
public:
    DisplayLogo();

    MultiText& getLogo();

    virtual void setSize(sf::Vector2f size);
    virtual Snapshot getSnapshot() {};
    virtual void applySnapshot(const Snapshot& snapshot) {};

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) override {};
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void update();
};


#endif //CS008_SFML_FINALPROJECT_DISPLAYLOGO_H
