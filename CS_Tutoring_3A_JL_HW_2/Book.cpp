//
// Created by Quantum on 4/11/2023.
//

#include "Book.h"

int Book::getCode() {
    return code;
}

std::string Book::getTitle() {
    return title;
}

int Book::getAvailable() {
    return available;
}

int Book::getRented() {
    return rented;
}

void Book::setCode(int code) {
    Book::code = code;
}

void Book::setTitle(const std::string &title) {
    Book::title = title;
}

void Book::setAvailable(int available) {
    Book::available = available;
}

void Book::setRented(int rented) {
    Book::rented = rented;
}

std::string Book::getCategoryStr() {
    std::string categories[] = {"Children", "Computer", "Novel"};
    return categories[static_cast<int>(getCategory())];
}
