#include <iostream>

bool checkLetter(const std::string &word, std::string &dashedWord,const char &letter);
std::string lowerString(std::string text);
std::string convertToDashes(const std::string &word);

int main() {

    std::string word = "Communication"; // the picked word
    std::string dashedWord = convertToDashes(word); // create dashes from picked word length

    int counter = 0;     // the current state of hangman
    bool didWin = false; // set win status to false

    do {
        std::string letter;

        // display life counter for debugging purposes
        std::cout << "Lives left: " << 6 - counter << std::endl;
        // display our dashed word
        std::cout << dashedWord << std::endl << std::endl;
        std::cout << "Enter letter: ";
        std::cin >> letter; // get user input for the letter
        std::cout << std::endl;

        std::string loweredWord = lowerString(word);
        std::string loweredGuess = lowerString(letter);

        if (loweredGuess.size() > 1 && loweredGuess == loweredWord) {
            didWin = true;
            break;
        }

        bool isLetterCorrect = checkLetter(word, dashedWord, loweredGuess[0]);

        if (word == dashedWord) {
            // player won the game, break out of while loop
            didWin = true;
            break;
        }

        if (!isLetterCorrect) {
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

bool checkLetter(const std::string &word, std::string &dashedWord,
                 const char &letter) {
    // convert picked word to all lowercase
    std::string loweredWord = lowerString(word);

    char loweredLetter = tolower(letter);

    // find first index of loweredLetter in loweredWord
    int letterPos = loweredWord.find(loweredLetter);

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
    for (char &c: text) {
        c = tolower(c);
    }

    return text;
}

std::string convertToDashes(const std::string &word) {
    std::string dashedWord;

    for (int i = 0; i < word.size(); i++) {
        dashedWord += '-';
    }

    return dashedWord;
}