#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFMLBackground.h"
#include "SFMLCard.h"
#include "Deck.h"
#include "CardHand.h"
#include "CardHandScorer.h"
#include "SFMLCardHand.h"
#include "SFMLDrawHandRank.h"
#include "SFMLDrawAllHandRankings.h"

int main() {
    srand(time(0));
    sf::err().rdbuf(NULL);
    sf::Vector2u windowSize(750, 945);

    bool noRoyalFlush = true;
    PokerScore ps;
    int norfCount = 0;

    std::cout << "Time: " << time(0) << std::endl;

    while (noRoyalFlush) {
        Deck deck;
        deck.shuffle();

        std::vector<CardHand> vCH;

        for (int j = 0; j < 5; j++) {
            CardHand ch;
            for (int k = 0; k < 5; k++) {
                ch.addCard(deck.dealCard());
            }
            vCH.push_back(ch);
        }

        PokerScore temp = CardHandScorer::scorePokerHand(vCH[rand() % 5], noRoyalFlush);
        norfCount++;

        if (norfCount == 650000) {
            std::cout << "we passed 650k" << std::endl;
            std::cout << "Time: " << time(0) << std::endl;
        }

        ps += temp;
    }

    std::cout << ps << std::endl;
    std::cout << "Time: " << time(0) << std::endl;

    sf::RenderWindow window({windowSize.x, windowSize.y, 32}, "Poker Analysis");
    window.setFramerateLimit(60);

    SFMLDrawAllHandRankings allHandRankings(ps);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(allHandRankings);
        window.display();
    }

    return 0;
}