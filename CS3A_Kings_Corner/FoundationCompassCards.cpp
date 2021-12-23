//
// Created by NAMEHERE on 12/4/2021.
//

#include "FoundationCompassCards.h"

FoundationCompassCards::FoundationCompassCards() {
//    piles[NORTH].sort();
}

void FoundationCompassCards::newGame() {
//    BaseCard card = deck.getDeck().dealCard();
    deck.getDeck().shuffle();
//    std::cout << getDeck() << std::endl;
    std::cout << "new game" << std::endl;
    for (int dirPile = NORTH; dirPile != WEST + 1; dirPile++) {
//    for (int dirPile = NORTH; dirPile != LAST_COMPASS; dirPile++) {
        CardPile temp;
        temp.addCard(deck.getDeck().dealCard());
        piles[static_cast<CompassENUM>(dirPile)].setCardPile(temp);
    }
    turnOrder.addPlayer(deck.getDeck());
//    turnOrder.addPlayer(deck.getDeck());
    turnOrder.getPlayerAt(turnOrder.addPlayer(deck.getDeck())).setHidden(true);
}

void FoundationCompassCards::shuffleDeck() {
    getDeck().shuffle();
}

SFMLGameTurnOrder &FoundationCompassCards::getSFMLGameTurnOrder() {
    return this->turnOrder;
}

SFMLDeck& FoundationCompassCards::getSFMLDeck() {
    return this->deck;
}

Deck& FoundationCompassCards::getDeck() {
    return this->deck.getDeck();
}

CardPile& FoundationCompassCards::getPile(const CompassENUM& direction) {
    return piles.at(direction).getCardPile();
//    return piles[direction].getCardPile();
}

SFMLCardPile FoundationCompassCards::at(CompassENUM dir) const {
    return piles.at(dir);
}

SFMLCardPile& FoundationCompassCards::operator[](CompassENUM dir) {
    return piles[dir];
}

bool FoundationCompassCards::internalCombineCheck(CompassENUM dropped, CompassENUM lastDragged, int lastDragged_rank_front) {
    int dropped_rank_back = piles[dropped].getCardPile().getPile().getAllCards().back().getRank().toInt();

    SuitsColorENUM dropped_suit_back = piles[dropped].getCardPile().getPile().getAllCards().back().getSuit().getColor();
    SuitsColorENUM lastDragged_suit_front = piles[lastDragged].getCardPile().getPile().getAllCards().front().getSuit().getColor();

    bool order_and_altColor = dropped_rank_back - 1 == lastDragged_rank_front && dropped_suit_back != lastDragged_suit_front;

    std::cout << "rank: " << dropped_rank_back << std::endl;
    std::cout << "rank: " << lastDragged_rank_front << std::endl;

//    std::cout << "cC: rank: " << dropped_rank_back << " " << lastDragged_rank_front << std::endl;
//    std::cout << "cC: color: " << dropped_suit_back << " " << lastDragged_suit_front << std::endl;

    return order_and_altColor;
}

bool FoundationCompassCards::combineCheck(CompassENUM dropped, CompassENUM lastDragged) {

    int lastDragged_rank_front = piles[lastDragged].getCardPile().getPile().getAllCards().front().getRank().toInt();

    if (dropped > WEST) {
        if (piles[dropped].getCardPile().getSize() == 0) {
            if (lastDragged_rank_front == KING) {
                return true;
            }
            return false;
        }
        return internalCombineCheck(dropped, lastDragged, lastDragged_rank_front);
    } else {
        if (piles[dropped].getCardPile().getSize() == 0) {
            return true;
        }
        return internalCombineCheck(dropped, lastDragged, lastDragged_rank_front);
    }
}


void FoundationCompassCards::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(deck);
    window.draw(turnOrder);
}

void FoundationCompassCards::eventHandler(sf::RenderWindow &window, sf::Event event) {
    deck.eventHandler(window, event);
    turnOrder.eventHandler(window, event);
}

void FoundationCompassCards::update(sf::RenderWindow &window) {
    deck.update();
    turnOrder.update(window);
}
