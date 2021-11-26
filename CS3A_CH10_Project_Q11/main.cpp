#include <iostream>

class Movie {
private:
    std::string name;
    std::string rating;
    double avgReview = 0;
    int terrible = 0;
    int bad = 0;
    int ok = 0;
    int good = 0;
    int great = 0;
public:
    Movie();
    Movie(std::string name);
    Movie(std::string name, std::string rating);

    void setName(std::string name);
    void setRating(std::string rating);

    std::string getName();
    std::string getRating();
    double getAverage();

    void addRating(int review);
    void output();

};

int main() {
    Movie godfather("The Godfather", "R");
    godfather.output();
    godfather.addRating(5);
    godfather.output();

    Movie goodfellas("Goodfellas", "R");
    goodfellas.output();
    goodfellas.addRating(5);
    goodfellas.addRating(5);
    goodfellas.output();
    return 0;
}

Movie::Movie() : Movie("Blank", "Blank") {

}

Movie::Movie(std::string name) : Movie(name, "Blank") {

}

Movie::Movie(std::string name, std::string rating) : name(name), rating(rating) {

}

void Movie::setName(std::string name) {
    this->name = name;
}

void Movie::setRating(std::string rating) {
    this->rating = rating;
}

std::string Movie::getName() {
    return name;
}

std::string Movie::getRating() {
    return rating;
}

double Movie::getAverage() {
    avgReview = ( (terrible * 1) + (bad * 2) + (ok * 3) + (good * 4) + (great * 5) ) / 5.00;
    return avgReview;
}

void Movie::addRating(int review) {
    switch (review) {
        case 1:
            terrible++;
            break;
        case 2:
            bad++;
            break;
        case 3:
            ok++;
            break;
        case 4:
            good++;
            break;
        case 5:
            great++;
            break;
        default:
            std::cout << "Error";
            break;
    }
}

void Movie::output() {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Rating: " << getRating() << std::endl;
    std::cout << "Average Review: " << getAverage() << std::endl;
    std::cout << "Terrible: " << terrible << std::endl;
    std::cout << "Bad: " << bad << std::endl;
    std::cout << "OK: " << ok << std::endl;
    std::cout << "Good: " << good << std::endl;
    std::cout << "Great: " << great << std::endl << std::endl;
}
