//
// Created by Adam G. on 2/26/2022.
//

#ifndef CS008_SFML_TYPING_TYPING_H
#define CS008_SFML_TYPING_TYPING_H

#include <SFML/Graphics.hpp>
#include "GUIComponentAdapter.h"
#include "ResourceHolder.h"
#include "MultiText.h"
#include "SyntaxHighlighter.h"

class Typing : public GUIComponentAdapter {
private:
    MultiText mt;
public:
    Typing();

    MultiText& getMultiText();

    virtual Snapshot getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

    virtual void onTextEntered(sf::Uint32 unicode);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //CS008_SFML_TYPING_TYPING_H
