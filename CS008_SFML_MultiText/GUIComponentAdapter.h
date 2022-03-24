//
// Created by Adam G. on 3/23/22.
//

#ifndef CS008_SFML_TYPING_GUICOMPONENTADAPTER_H
#define CS008_SFML_TYPING_GUICOMPONENTADAPTER_H

#include "GUIComponent.h"

class GUIComponentAdapter : public GUIComponent {
public:
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
};


#endif //CS008_SFML_TYPING_GUICOMPONENTADAPTER_H
