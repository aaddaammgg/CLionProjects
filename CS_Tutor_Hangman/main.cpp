#include <iostream>

bool checkLetter(const std::string& word, std::string& dashedWord, const char& letter);
std::string lowerString(std::string text);

int main() {

    std::string word = "Bedddde"; // the picked word
    std::string dashedWord = "-------"; // create dashes from picked word length

    int counter = 0; // the current state of hangman
    bool didWin = false; // set win status to false

    do {
        char letter;

        std::cout << "Lives left: " << 6 - counter << std::endl; // display life counter for debugging purposes
        std::cout << dashedWord << std::endl << std::endl; // display our dashed letters
        std::cout << "Enter letter: ";
        std::cin >> letter; // get user input for the letter
        std::cout << std::endl;

        // call checkLetter(...) and check if word == dashedWord
        // this works because dashedWord is call by reference
        // in the first part of the if statement it will modify 'dashedWord' if the letter is correct
        // then afterwards it will check if word is equal to dashedWord
        if (checkLetter(word, dashedWord, letter) && word == dashedWord) {
            didWin = true;
            break;
        } else {
            std::cout << "Incorrect!" << std::endl;
            counter++; // incorrect letter increase counter
        }
    } while (counter < 6); // once counter reaches 6 it will end the game

    if (didWin) {
        std::cout << "Winner! Word: " << word << std::endl;
    } else {
        std::cout << "Loser! Word: " << word << std::endl;
    }

    return 0;
}

bool checkLetter(const std::string& word, std::string& dashedWord, const char& letter) {
    std::string loweredWord = lowerString(word); // convert picked word to all lowercase
    char loweredLetter = tolower(letter); // convert letter to lowercase
    int letterPos = loweredWord.find(loweredLetter); // find first index of loweredLetter in loweredWord

    // if letterPos is -1 then we did not find a letter
    // return false to exit the scope of the function
    if (letterPos == -1) {
        return false;
    }

    // at this point we know there is a valid index and it is not -1
    // we will keep looping until we hit a -1
    while (letterPos != -1) {
        // change letter at index to the correct letter
        dashedWord[letterPos] = word[letterPos];

        // find new letterPos if available using the second parameter
        letterPos = loweredWord.find(loweredLetter, letterPos + 1);
    }

    // at this point the user found a correct letter and we will return true
    return true;
}

std::string lowerString(std::string text) {
    for (char& c : text) {
        c = tolower(c);
    }

    return text;
}