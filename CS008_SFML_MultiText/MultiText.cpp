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
    pb.pos.x += pb.bounds.width + pb.bounds.left + 2;
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

int MultiText::getSize() {
    return letters.size();
}

bool MultiText::isEmpty() {
    return letters.empty();
}

void MultiText::removeChar() {
    if (!letters.empty()) {
        letters.pop_back();
    }
}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (auto const& letter : letters) {
        window.draw(letter, states);
    }
}

void MultiText::update() {

}

Letter &MultiText::index(int i) {
    int count = 0;

    for (auto & letter : letters) {
        if (count == i) {
            return letter;
        }
        count++;
    }


    auto *t = new Letter;
    return *t;
}

//Letter &MultiText::cIndex(int i) const {
//    return index(i);
//}

Letter &MultiText::front() {
    return letters.front();
}

Letter &MultiText::back() {
    return letters.back();
}

std::_List_iterator<Letter> MultiText::begin() {
    return letters.begin();
}

std::_List_iterator<Letter> MultiText::end() {
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

//Letter MultiText::operator[](int i) const {
//    return index(i);
//}

Letter &MultiText::operator[](int i) {
    return index(i);
}
