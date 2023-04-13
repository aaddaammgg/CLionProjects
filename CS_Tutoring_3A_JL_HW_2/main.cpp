#include <iostream>
#include <fstream>

#include "Book.h"

#include "ChildrenBook.h"
#include "ComputerBook.h"
#include "Novel.h"

int countLines(const std::string& fileName);
void readBooks(const std::string& fileName, Book**& books, int& size);
void printBooks(Book**& books, const int& size);

int main() {
    Book** books = nullptr;
    int bookSize;

    readBooks("book.txt", books, bookSize);

    Novel* book = (Novel*)books[0];

    printBooks(books, bookSize);

    for (int i = 0; i < bookSize; i++) {
        Book* b = books[i];

        if (b->getCategory() == CATEGORY::CHILDREN_BOOK) {
            delete (ChildrenBook*)books[i];
        } else if (b->getCategory() == CATEGORY::COMPUTER_BOOK) {
            delete (ComputerBook*)books[i];
        } else {
            delete (Novel*)books[i];
        }
    }

    delete[] books;

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

    file.close();
}

void printBooks(Book**& books, const int& size) {
    for (int i = 0; i < size; ++i) {
        Book* book = books[i];

        std::cout << book->getTitle() << '(' << book->getCode() << ")" << std::endl
                  << "Category: " << book->getCategoryStr() << std::endl << std::endl;
    }
}