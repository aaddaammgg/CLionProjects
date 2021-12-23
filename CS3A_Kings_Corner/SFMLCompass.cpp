//
// Created by NAMEHERE on 12/4/2021.
//

#include "SFMLCompass.h"

SFMLCompass::SFMLCompass() {
//    MouseEvents::setDraggable(true);
}

void SFMLCompass::init() {
    bounds.width = 60;
    bounds.height = 150;
    bounds.left = 0;
    bounds.top = 0;

//    std::cout << compassCards.getDeck() << std::endl;

//    compassCards.shuffleDeck();
    compassCards.newGame();

//    std::cout << compassCards.getDeck() << std::endl;

//    for (int dir = NORTH; dir != WEST + 1; dir++) {
//        compassCards[static_cast<CompassENUM>(dir)].setCardPile(compassCards.getPile(static_cast<CompassENUM>(dir)));
//    }

//    compassCards[NORTH].setPosition(0, 150);
//    compassCards[EAST].setPosition(150, 0);
//    compassCards[SOUTH].setPosition(0, -150);
//    compassCards[WEST].setPosition(-150, 0);

    compassCards.getSFMLGameTurnOrder().setPosition({WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
//    compassCards.getSFMLGameTurnOrder().addPlayer(compassCards.getDeck());

    compassCards[NORTH].setDraggable(true);
    compassCards[EAST].setDraggable(true);
    compassCards[SOUTH].setDraggable(true);
    compassCards[WEST].setDraggable(true);

    compassCards[NORTH].setRotation(180.f);
    compassCards[EAST].setRotation(90.f);
    compassCards[SOUTH].setRotation(0.f);
    compassCards[WEST].setRotation(-90.f);

//    compassCards[NORTHEAST].setPosition(150, 150);
//    compassCards[SOUTHEAST].setPosition(150, -150);
//    compassCards[SOUTHWEST].setPosition(-150, -150);
//    compassCards[NORTHWEST].setPosition(-150, 150);

    compassCards[NORTHEAST].setRotation(135.f);
    compassCards[SOUTHEAST].setRotation(45.f);
    compassCards[SOUTHWEST].setRotation(-45.f);
    compassCards[NORTHWEST].setRotation(-135.f);

}

FoundationCompassCards SFMLCompass::getCompassCardPiles() {
    return compassCards;
}

void SFMLCompass::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = getTransform();

    compassCards.draw(window, states);

    if (drawOrder.empty()) {
        for (int dir = NORTH; dir != LAST_COMPASS; dir++) {
            window.draw(compassCards.at(static_cast<const CompassENUM>(dir)), states);
        }
    } else {
        for (auto const& i : drawOrder) {
            window.draw(compassCards.at(i), states);
        }
    }



//    window.draw(compassCards, states);
}

void SFMLCompass::eventHandler(sf::RenderWindow &window, sf::Event event) {
//    sf::Vector2f newPos;
//
//    MouseEvents::eventHandler(window, event, getTransform().transformRect(bounds), newPos);
//    if (MouseEvents::isDragging()) {
//        setPosition(newPos.x, newPos.y);
//    }

    drawOrder.clear();

    for (int dir = NORTH; dir != LAST_COMPASS; dir++) {
        auto _dir = static_cast<CompassENUM>(dir);
        compassCards[_dir].eventHandler(window, event);

        if (compassCards[_dir].getCardPile().getSize() == 0) {
            compassCards[_dir].setDraggable(false);
            drawOrder.push_front(_dir);
            continue;
        } else if (dir <= WEST) {
//            std::cout << dir << std::endl;
            compassCards[_dir].setDraggable(true);
        }

        if (compassCards[_dir].isDragging()) {
            lastDragged = _dir;
            drawOrder.push_back(_dir);
        } else {
            drawOrder.push_front(_dir);
        }

        if (compassCards[_dir].mouseButtonPressed()) {
            isDropped = false;
        }
//        std::cout << dir << std::endl;

        if (lastDragged != LAST_COMPASS) {
            if (compassCards[lastDragged].getBounds().intersects(compassCards[_dir].getBounds())) {
//                std::cout << piles[_dir].getCardPile().firstCard().getRank().toInt() << std::endl;
            }
        }


        if (!compassCards[_dir].isDragging()) {
            sf::Vector2f pos = getPosition();
            if (_dir == NORTH) {
                compassCards[NORTH].setPosition(pos.x, pos.y + 150);
            } else if (_dir == EAST) {
                compassCards[EAST].setPosition(pos.x + 150, pos.y);
            } else if (_dir == SOUTH) {
                compassCards[SOUTH].setPosition(pos.x, pos.y - 150);
            } else if (_dir == WEST) {
                compassCards[WEST].setPosition(pos.x - 150, pos.y);
            }
        }
    }

    compassCards.eventHandler(window, event);
}

void SFMLCompass::update(sf::RenderWindow& window) {
    for (int dir = NORTH; dir != LAST_COMPASS; dir++) {
        auto _dir = static_cast<CompassENUM>(dir);
        compassCards[_dir].update(window);

//        if (compassCards[_dir].getCardPile().getSize() == 0) continue;

        if (compassCards[_dir].mouseButtonReleased(true) && lastDragged != LAST_COMPASS) {
            mouseReleased = _dir;
        }

        if (compassCards[_dir].isHovering()) {
            curHover = _dir;
        }

        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (compassCards[_dir].getTransform().transformRect(compassCards[_dir].getBounds()).contains(mousePos)) {
            if (lastDragged != LAST_COMPASS && !isDropped) {
//                std::cout << piles[lastDragged].getCardPile().firstCard().getRank().toInt() << std::endl;
//                std::cout << piles[_dir].getCardPile().firstCard().getRank().toInt() << std::endl;
//                lastDragged = LAST_COMPASS;
                dropped = _dir;
            }
        }
    }

//    if (lastDragged != LAST_COMPASS && piles[lastDragged].mouseButtonReleased(true) && !isDropped) {
//        std::cout << "released" << std::endl;
//        std::cout << piles[lastDragged].getCardPile().firstCard().getRank().toInt() << std::endl;
//        std::cout << piles[dropped].getCardPile().firstCard().getRank().toInt() << std::endl;
//
//        if (compassCards.combineCheck(dropped, lastDragged)) {
//            std::cout << "can combine" << std::endl;
//        } else {
//            std::cout << "cant combine" << std::endl;
//        }
//    }

    if (lastDragged != LAST_COMPASS && dropped != LAST_COMPASS && !isDropped && compassCards[lastDragged].mouseButtonReleased(true)) {
//        std::cout << compassCards[lastDragged].getCardPile().firstCard().getRank().toInt() << std::endl;
//        std::cout << compassCards[dropped].getCardPile().firstCard().getRank().toInt() << std::endl;

        if (compassCards.combineCheck(dropped, lastDragged)) {
            compassCards.getPile(dropped) += compassCards[lastDragged].getCardPile();
//            compassCards.getPile(dropped).combinePile(compassCards[lastDragged].getCardPile());
            compassCards[dropped].setCardPile(compassCards.getPile(dropped));
            CardPile temp;
            compassCards[lastDragged].setCardPile(temp);
            lastDragged = LAST_COMPASS;

            std::cout << "can combine" << std::endl;

            std::cout << compassCards.getPile(dropped) << std::endl;
        } else {
            std::cout << "cant combine" << std::endl;
            std::cout << compassCards.getPile(dropped) << std::endl;
        }

        isDropped = true;
//        if (counter > 2) {
//            lastDragged = LAST_COMPASS;
//        }
    }

    compassCards.update(window);

//    std::cout << lastDragged << " " << mouseReleased << " " << curHover << std::endl;
}

void SFMLCompass::setPosition(sf::Vector2f pos) {
    compassCards[NORTH].setPosition(pos.x, pos.y + 150);
    compassCards[EAST].setPosition(pos.x + 150, pos.y);
    compassCards[SOUTH].setPosition(pos.x, pos.y - 150);
    compassCards[WEST].setPosition(pos.x - 150, pos.y);

    compassCards[NORTHEAST].setPosition(pos.x + 150, pos.y + 150);
    compassCards[SOUTHEAST].setPosition(pos.x + 150, pos.y - 150);
    compassCards[SOUTHWEST].setPosition(pos.x - 150, pos.y - 150);
    compassCards[NORTHWEST].setPosition(pos.x - 150, pos.y + 150);

    compassCards.getSFMLDeck().setPosition(pos.x, pos.y);

    sf::Transformable::setPosition(pos);
//    sf::Vector2f newpos = getTransform().transformPoint(0, 0);
}
