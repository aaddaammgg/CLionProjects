#include <iostream>
#include <fstream>

#include "Book.h"

#include "ChildrenBook.h"
#include "ComputerBook.h"
#include "Novel.h"

int countLines(const std::string& fileName);
void readBooks(const std::string& fileName, Book**& books, int& size);
void printBooks(const Book**& books, const int& size);

int main() {
    Book** books = nullptr;
    int bookSize;

    readBooks("book.txt", books, bookSize);

    Novel* book = (Novel*)books[0];

    std::cout << book->getPublishDate() << std::endl;
    return 0;
}

int countLines(const std::string& fileName) {
    int count = 0;
    std::string line;

    std::ifstream file(fileName);

    if (file.fail()) {
        std::cout << "Failed to load fail: " << fileName << std::endl;
        exit(1);
    }

    while (std::getline(file, line)) {
        if (!line.empty()) {
            count++;
        }
    }

    return count;
}

void readBooks(const std::string& fileName, Book**& books, int& size) {
    size = countLines(fileName);

    books = new Book*[size];

    for (int i = 0; i < size; ++i) {
        books[i] = new Book();
    }

    std::ifstream file(fileName);

    if (file.fail()) {
        std::cout << "Failed to load fail: " << fileName << std::endl;
        exit(1);
    }

    int count = 0;

    while (!file.eof()) {
        int code;
        std::string title;
        int available;
        int rent;

        file >> code >> title;

        if (code >= 1001 && code <= 2000) {
            int age;

            file >> age >> available >> rent;

            ChildrenBook* book = new ChildrenBook;
            book->setCode(code);
            book->setTitle(title);
            book->setAge(age);
            book->setAvailable(available);
            book->setRented(rent);

            books[count] = book;
        } else if (code >= 2001 && code <= 3000) {
            std::string publisher;

            file >> publisher >> available >> rent;

            ComputerBook* book = new ComputerBook;
            book->setCode(code);
            book->setTitle(title);
            book->setPublisher(publisher);
            book->setAvailable(available);
            book->setRented(rent);

            books[count] = book;
        } else if (code >= 3001 && code <= 4000) {
            int publish_date;

            file >> publish_date >> available >> rent;

            Novel* book = new Novel;
            book->setCode(code);
            book->setTitle(title);
            book->setPublishDate(publish_date);
            book->setAvailable(available);
            book->setRented(rent);

            books[count] = book;
        }

        count++;
    }
}

void printBooks(const Book**& books, const int& size) {
    for (int i = 0; i < size; ++i) {
        const Book* book = books[i];


    }
}