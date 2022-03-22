//
// Created by Adam G. on 3/18/22.
//

#ifndef CS008_SFML_TYPING_MULTITEXT_H
#define CS008_SFML_TYPING_MULTITEXT_H

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "Letter.h"

struct PosBounds {
    sf::Vector2f pos;
    sf::FloatRect bounds;
};

class MultiText : public sf::Drawable {
private:
    std::list<Letter> letters;
    PosBounds getLastPos();
    void updatePosition(Letter& l);
    void push(Letter& l);
    static sf::Color randomColor();
    Letter& index(int i);
//    Letter& cIndex(int i) const;
public:
    MultiText();

    void addChar(char c);
    void addChar(const std::string& str);
    void addChar(const sf::Text& text);

    int getSize();
    bool isEmpty();

    void removeChar();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();

    Letter& front();
    Letter& back();

    std::_List_iterator<Letter> begin();
    std::_List_iterator<Letter> end();

    MultiText& operator+=(const char& rhs);
    MultiText& operator+=(const std::string& rhs);
    MultiText& operator+=(const sf::Text& rhs);
    MultiText& operator--();
    MultiText operator--(int);
//    Letter operator[](int i) const;
    Letter& operator[](int i);
};


#endif //CS008_SFML_TYPING_MULTITEXT_H
