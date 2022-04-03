//
// Created by Adam G. on 3/18/22.
//

#ifndef CS008_SFML_TYPING_LETTER_H
#define CS008_SFML_TYPING_LETTER_H

#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"

class Letter : public sf::Text {
private:
public:
    Letter();
    Letter(const std::string& str);
};


#endif //CS008_SFML_TYPING_LETTER_H
