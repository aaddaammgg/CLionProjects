//
// Created by Adam G. on 3/18/22.
//

#include "MultiText.h"

MultiText::MultiText() {

}

PosBounds MultiText::getLastPos() {
    return {letters.back().getPosition(), letters.back().getLocalBounds() };
}

void MultiText::updatePosition(Letter &l) {
    PosBounds pb = getLastPos();
    pb.pos.x += pb.bounds.width + pb.bounds.left + 1;
    l.setPosition(pb.pos);
}

void MultiText::push(Letter &l) {
    l.setFillColor(randomColor());
    updatePosition(l);
    letters.push_back(l);
}

sf::Color MultiText::randomColor() {
    return {static_cast<sf::Uint8>((rand() % 255)), static_cast<sf::Uint8>((rand() % 255)), static_cast<sf::Uint8>((rand() % 255))};
}

void MultiText::addChar(char c) {
    Letter l(std::string(1, c));
    push(l);
}

void MultiText::addChar(const std::string& str) {
    Letter l(str);
    push(l);
}

void MultiText::addChar(const sf::Text &text) {
    Letter l = (Letter &&) text;
    push(l);
}

void MultiText::removeChar() {
    if (!letters.empty()) {
        letters.pop_back();
    }
}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (auto const& letter : letters) {
        window.draw(letter);
    }
}

void MultiText::update() {

}

const std::list<Letter>::iterator &MultiText::begin() {
    return letters.begin();
}

const std::list<Letter>::iterator &MultiText::end() {
    return letters.end();
}

MultiText &MultiText::operator+=(const char &rhs) {
    this->addChar(rhs);
    return *this;
}

MultiText &MultiText::operator+=(const std::string &rhs) {
    this->addChar(rhs);
    return *this;
}

MultiText &MultiText::operator+=(const sf::Text &rhs) {
    this->addChar(rhs);
    return *this;
}

MultiText &MultiText::operator--() {
    this->removeChar();
    return *this;
}

MultiText MultiText::operator--(int) {
    MultiText tmp(*this);
    operator--();
    return tmp;
}
