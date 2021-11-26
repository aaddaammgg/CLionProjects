//
// Created by Adam G. on 10/31/2021.
//

#include "SFMLDrawHandRank.h"

#include <utility>

SFMLDrawHandRank::SFMLDrawHandRank() {

}

SFMLDrawHandRank::SFMLDrawHandRank(PokerScore::Scores pokerENUM, float odds) : pokerENUM(pokerENUM), odds(odds) {
    CardHand ch;

    BaseCard c1(KING, DIAMONDS);
    BaseCard c2(JACK, DIAMONDS);
    BaseCard c3(TEN, HEARTS);
    BaseCard c4(ACE, DIAMONDS);
    BaseCard c5(QUEEN, DIAMONDS);

    switch (pokerENUM) {
        case PokerScore::Scores::ROYAL_FLUSH:
            c1.setRank(ACE);
            c1.setSuit(HEARTS);
            c2.setRank(KING);
            c2.setSuit(HEARTS);
            c3.setRank(QUEEN);
            c3.setSuit(HEARTS);
            c4.setRank(JACK);
            c4.setSuit(HEARTS);
            c5.setRank(TEN);
            c5.setSuit(HEARTS);
            break;
        case PokerScore::Scores::STRAIGHT_FLUSH:
            c1.setRank(JACK);
            c1.setSuit(CLUBS);
            c2.setRank(TEN);
            c2.setSuit(CLUBS);
            c3.setRank(NINE);
            c3.setSuit(CLUBS);
            c4.setRank(EIGHT);
            c4.setSuit(CLUBS);
            c5.setRank(SEVEN);
            c5.setSuit(CLUBS);
            break;
        case PokerScore::Scores::FOUR_OF_A_KIND:
            c1.setRank(FOUR);
            c1.setSuit(SPADES);
            c2.setRank(FOUR);
            c2.setSuit(HEARTS);
            c3.setRank(FOUR);
            c3.setSuit(CLUBS);
            c4.setRank(FOUR);
            c4.setSuit(DIAMONDS);
            c5.setRank(KING);
            c5.setSuit(SPADES);
            break;
        case PokerScore::Scores::FULL_HOUSE:
            c1.setRank(TEN);
            c1.setSuit(HEARTS);
            c2.setRank(TEN);
            c2.setSuit(SPADES);
            c3.setRank(TEN);
            c3.setSuit(DIAMONDS);
            c4.setRank(TWO);
            c4.setSuit(CLUBS);
            c5.setRank(TWO);
            c5.setSuit(HEARTS);
            break;
        case PokerScore::Scores::FLUSH:
            c1.setRank(KING);
            c1.setSuit(SPADES);
            c2.setRank(NINE);
            c2.setSuit(SPADES);
            c3.setRank(JACK);
            c3.setSuit(SPADES);
            c4.setRank(FIVE);
            c4.setSuit(SPADES);
            c5.setRank(ACE);
            c5.setSuit(SPADES);
            break;
        case PokerScore::Scores::STRAIGHT:
            c1.setRank(JACK);
            c1.setSuit(SPADES);
            c2.setRank(TEN);
            c2.setSuit(HEARTS);
            c3.setRank(NINE);
            c3.setSuit(CLUBS);
            c4.setRank(EIGHT);
            c4.setSuit(DIAMONDS);
            c5.setRank(SEVEN);
            c5.setSuit(SPADES);
            break;
        case PokerScore::Scores::THREE_OF_A_KIND:
            c1.setRank(TWO);
            c1.setSuit(HEARTS);
            c2.setRank(TWO);
            c2.setSuit(CLUBS);
            c3.setRank(TWO);
            c3.setSuit(DIAMONDS);
            c4.setRank(SIX);
            c4.setSuit(SPADES);
            c5.setRank(ACE);
            c5.setSuit(HEARTS);
            break;
        case PokerScore::Scores::TWO_PAIR:
            c1.setRank(EIGHT);
            c1.setSuit(CLUBS);
            c2.setRank(EIGHT);
            c2.setSuit(DIAMONDS);
            c3.setRank(SEVEN);
            c3.setSuit(HEARTS);
            c4.setRank(SEVEN);
            c4.setSuit(CLUBS);
            c5.setRank(QUEEN);
            c5.setSuit(CLUBS);
            break;
        case PokerScore::Scores::ONE_PAIR:
            c1.setRank(FIVE);
            c1.setSuit(SPADES);
            c2.setRank(FIVE);
            c2.setSuit(DIAMONDS);
            c3.setRank(JACK);
            c3.setSuit(CLUBS);
            c4.setRank(TEN);
            c4.setSuit(HEARTS);
            c5.setRank(THREE);
            c5.setSuit(SPADES);
            break;
        case PokerScore::Scores::HIGH_CARD:
            c1.setRank(KING);
            c1.setSuit(HEARTS);
            c2.setRank(TWO);
            c2.setSuit(SPADES);
            c3.setRank(EIGHT);
            c3.setSuit(CLUBS);
            c4.setRank(JACK);
            c4.setSuit(DIAMONDS);
            c5.setRank(SIX);
            c5.setSuit(HEARTS);
            break;
    }

    ch.addCard(c1);
    ch.addCard(c2);
    ch.addCard(c3);
    ch.addCard(c4);
    ch.addCard(c5);

    sfmlCardHand = SFMLCardHand(ch);
    sfmlCardHand.setPosition(10, 10);
    sfmlCardHand.getSFMLCards()[0].setSize({10, 10});
    background.setFillColor(sf::Color::Red);

    handRank.setFont(ResourceHolder::getFont("card_font.ttf"));
    probability.setFont(ResourceHolder::getFont("card_font.ttf"));

    std::string rankingStr = std::to_string((int)pokerENUM + 1) + ") ";
    rankingStr += PokerScore::scoresToString(pokerENUM) + " ";

    std::string probabilityStr = "   ";

    if (pokerENUM == PokerScore::HIGH_CARD) {
        probabilityStr += " ";
    }

    probabilityStr += std::to_string((int)odds) + " : 1";

    handRank.setString(rankingStr);
    probability.setString(probabilityStr);

    handRank.setCharacterSize(24);
    probability.setCharacterSize(24);

}

void SFMLDrawHandRank::setPosition(float x, float y) {
    this->drawHandPos.x = x;
    this->drawHandPos.y = y;
    sfmlCardHand.setPosition(x, y);

    sf::Vector2f cardSize = sfmlCardHand.getSFMLCards()[0].getSize();
    sf::Vector2f cardHandPos = sfmlCardHand.getPosition();

    cardHandPos.y += cardSize.y + 10;

    background.setPosition({cardHandPos});
    background.setSize({(cardSize.x * 5) + (10 * 4), 60});

    handRank.setPosition({cardHandPos});
    cardHandPos.y += 30;
    probability.setPosition({cardHandPos});
}

SFMLCardHand SFMLDrawHandRank::getSFMLCardHand() {
    return sfmlCardHand;
}

PokerScore::Scores SFMLDrawHandRank::getPokerENUM() {
    return pokerENUM;
}

float SFMLDrawHandRank::getOdds() {
    return odds;
}

void SFMLDrawHandRank::setOdds(float odds) {
    this->odds = odds;
}

//PokerScore SFMLDrawHandRank::getPokerScore() {
//    return pokerScore;
//}

void SFMLDrawHandRank::setSFMLCardHand(SFMLCardHand sfmlCardHand) {
    this->sfmlCardHand;
}

void SFMLDrawHandRank::setPokerENUM(PokerScore::Scores pokerENUM) {
    this->pokerENUM;
}

//void SFMLDrawHandRank::setPokerScore(PokerScore pokerScore) {
//    this->pokerScore;
//}

void SFMLDrawHandRank::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states = getTransform();
    window.draw(sfmlCardHand);
    window.draw(background);
    window.draw(handRank);
    window.draw(probability);
}
