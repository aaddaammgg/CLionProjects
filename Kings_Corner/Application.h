//
// Created by Quantum on 5/14/2023.
//

#ifndef KINGS_CORNER_APPLICATION_H
#define KINGS_CORNER_APPLICATION_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "_DEFINITIONS.h"
#include "GUIAdapter.h"
#include "MouseEvents.h"

#include "GUI_Circle.h"
#include "Deck.h"
#include "CardHand.h"
#include "SFMLCard.h"
#include "SFMLDeck.h"

class Application {
public:
    Application() = default;

    static void run();
};


#endif //KINGS_CORNER_APPLICATION_H
