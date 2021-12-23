//
// Created by Adam G. on 12/7/2021.
//

#include "SFMLGameTurnOrder.h"

SFMLGameTurnOrder::SFMLGameTurnOrder() {
    setOrigin(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
}

SFMLPlayerHand& SFMLGameTurnOrder::getPlayerAt(int index) {
    return players[index];
}

int SFMLGameTurnOrder::getCurPlayer() const {
    return curPlayer;
}

void SFMLGameTurnOrder::deal7Cards(int index, Deck& deck) {
    CardPile cp;

    for (int i = 0; i < 7; i++) {
        cp.addCard(deck.dealCard());
    }

    players[index].setCardPile(cp);
}

int SFMLGameTurnOrder::addPlayer(Deck& deck) {
    if (players.empty()) {
        deal7Cards(1, deck);
        players[1].setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 150);
    } else {
        deal7Cards(2, deck);
        players[2].setPosition(WINDOW_WIDTH / 2, 150);
    }

    return players.size();
}

void SFMLGameTurnOrder::nextPlayer() {
    curPlayer++;
    if (curPlayer > players.size()) {
        curPlayer = 1;
    }
}

void SFMLGameTurnOrder::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = getTransform();

    for (const auto& ply : players) {
        window.draw(ply.second, states);
    }
}

void SFMLGameTurnOrder::eventHandler(sf::RenderWindow &window, sf::Event event) {
    for (auto ply : players) {
        ply.second.eventHandler(window, event);
    }
}

void SFMLGameTurnOrder::update(sf::RenderWindow &window) {
    for (auto ply : players) {
        ply.second.update(window);
    }
}
