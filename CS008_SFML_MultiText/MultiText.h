//
// Created by Adam G. on 3/18/22.
//

#ifndef CS008_SFML_TYPING_MULTITEXT_H
#define CS008_SFML_TYPING_MULTITEXT_H

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include "Letter.h"

class MultiText : public sf::Drawable {
public:
    typedef struct PosBounds {
        sf::Vector2f pos;
        sf::FloatRect bounds;
    } PosBounds;

    typedef std::list<Letter>::iterator iterator;

    typedef struct iteratorsBE {
        MultiText::iterator begin;
        MultiText::iterator end;
    } iteratorsBE;

private:
    std::list<Letter> letters;
    PosBounds getLastPos();
    void updatePosition(Letter& l);
    void push(Letter& l);
    static sf::Color randomColor();

    unsigned int characterSize = 30;

public:
    MultiText();

    void addChar(char c);
    void addChar(const std::string& str);
    void addChar(const sf::Text& text);

    std::string getString();
    std::string getString(MultiText::iterator begin, MultiText::iterator end);

    std::list<iteratorsBE> split(char c);
    iteratorsBE find(std::string str, MultiText::iterator startPos, bool& found);

//    MultiText::iteratorsBE getBeginEnd;

    unsigned int getCharacterSize() const;
    void setCharacterSize(unsigned int size);

    int getSize();
    bool isEmpty();

    void removeChar();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();

    Letter& front();
    Letter& back();

    MultiText::iterator begin(); // begin iterator
    MultiText::iterator end(); // end iterator

    MultiText& operator+=(const char& rhs);
    MultiText& operator+=(const std::string& rhs);
    MultiText& operator+=(const sf::Text& rhs);
    MultiText& operator--();
    MultiText operator--(int)&;
};


#endif //CS008_SFML_TYPING_MULTITEXT_H
