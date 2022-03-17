#include <iostream>
#include <ctime>
#include <string>

void playThreeCardMonty();
void displayMsg(const std::string&);
void displayCards(int a, int b, int c);
int getRandInt(int x);
void getCards(int &a, int &b, int &c);
void swapping(int &c1, int &c2);
void swappingMsg(char c1, char c2);
void swapCards(int &a, int &b, int &c);
void askUser(int &userA, int &userB, int &userC);
bool checkCard(int card, int cardInput);
void displayIfChoiceIsCorrect(char card, bool isCorrect);
void displayUserInput(char x, int &y);
void showIfCorrect(int a, int b, int c, int userA, int userB, int userC);
void displayNewCards(int a, int b, int c);
void playAgain();
void newLine();

int main() {
    playThreeCardMonty();

    return 0;
}

void playThreeCardMonty() {
    int a, b, c, userA, userB, userC;
    srand(time(NULL));

    displayMsg("Please memorize the following cards:\n");
    getCards(a, b, c);
    displayCards(a, b, c);
    swapCards(a, b, c);
    askUser(userA, userB, userC);
    showIfCorrect(a, b, c, userA, userB, userC);
    displayNewCards(a, b, c);
    playAgain();
}

void playAgain() {
    char repeat;

    std::cout << std::endl << "Would you like to repeat? Y/N" << std::endl;
    std::cin >> repeat;

    if (repeat == 'Y' || repeat == 'y') {
        newLine();
        newLine();
        playThreeCardMonty();
    }

    std::cout << "Goodbye!" << std::endl;
}

void newLine(){
    std::cout << std::endl;
}

void displayUserInput(char x, int &y) {
    std::cout << "What is card " << x << "?" << std::endl;
    std::cin >> y;
}

void displayIfChoiceIsCorrect(char card, bool isCorrect) {
    std::cout << "Card " << card << " is ";

    if (isCorrect) {
        std::cout << "correct.";
    } else {
        std::cout << "incorrect.";
    }

    newLine();
}

void displayNewCards(int a, int b, int c){
    displayMsg("\nThe new order of cards was:\n");
    displayCards(a, b, c);
}

void askUser(int &userA, int &userB, int &userC){
    newLine();

    displayUserInput('A', userA);
    displayUserInput('B', userB);
    displayUserInput('C', userC);
}

void showIfCorrect(int a, int b, int c, int userA, int userB, int userC){
    newLine();

    displayIfChoiceIsCorrect('A', checkCard(a, userA));
    displayIfChoiceIsCorrect('B', checkCard(b, userB));
    displayIfChoiceIsCorrect('C', checkCard(c, userC));
}

bool checkCard(int card, int cardInput){
    if (card == cardInput){
        return true;
    }

    return false;
}

void displayMsg(const std::string& msg){
    std::cout << msg;
}

void displayCards(int a, int b, int c){
    std::cout
    << "a:" << a
    << " b:" << b
    << " c:" << c
    << std::endl;
}

int getRandInt(int x){
    return rand() % x;
}

void getCards(int &a, int &b, int &c) {
    int x = 10;

    a = getRandInt(x);
    b = getRandInt(x);
    c = getRandInt(x);
}

void swapping(int &c1, int &c2){
    int x = c1;

    c1 = c2;
    c2 = x;
}

void swappingMsg(char c1, char c2) {
    std::cout << "Swapping cards " << c1 << " and " << c2 << "..." << std::endl;
}

void swapCards(int &a, int &b, int &c) {
    int loopAmt = getRandInt(10) + 1;

    newLine();

    for(int i = 0; i < loopAmt; i++) {
        int randomSwitch = getRandInt(3) + 1;

        switch(randomSwitch) {
            case 1:
                swapping(a, b);
                swappingMsg('A', 'B');
                break;
            case 2:
                swapping(a, c);
                swappingMsg('A', 'C');
                break;
            case 3:
                swapping(b, c);
                swappingMsg('B', 'C');
                break;
            default:
                std::cout << "Looks like something broke" << std::endl;
        }

    }
}