#include <iostream>
#include <fstream>
#include <map>

struct variable {
    int address;
    int value;
};

int main() {
    std::cout << "Adam Gonzalez (10275803)" << std::endl << std::endl;

    std::ifstream file("mysource.txt");
    std::ofstream dataFile("data.txt");
    std::ofstream codeFile("code.txt");

    if (file.fail()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    const std::map <char, int> ASMA = {
        {'G', 1}, // MOVE: MEMORY --> ACCUM
        {'P', 2}, // MOVE: ACCUM --> MEMORY
        {'A', 3}, // ADD TO ACCUM FROM MEMORY
        {'N', 4}, // COMPLEMENT ACCUM
        {'C', 5}, // COMPARE ACCUM TO MEMORY
        {'J', 6}, // JUMP IF ACCUM IS LESS THAN OR EQUAL TO MEMORY
        {'S', 0}, // STOP PROGRAM
    };

    char command, var;
    int accum;

    std::map <char, variable> memory;
    int memorySize = 0;

    while (!file.eof()) {
        file >> command;

        switch (command) {
            case 'd': {
                file >> var;

                int data;
                file >> data;

                dataFile << data << std::endl;

                memory[var] = {memorySize++, data};

                break;
            }
            case 'G': {
                file >> var;

                codeFile << ASMA.at(command) << ' ';

                if (!memory.contains(var)) {
                    break;
                }

                accum = memory[var].value;
                codeFile << memory[var].address << std::endl;

                break;
            }
            case 'P': {
                file >> var;

                codeFile << ASMA.at(command) << ' ' << memory[var].address << std::endl;

                memory[var].value = accum;

                break;
            }
            case 'A': {
                file >> var;

                codeFile << ASMA.at(command) << ' ' << memory[var].address << std::endl;

                accum += memory[var].value;

                break;
            }
            case 'N': {
                // TODO
                break;
            }
            case 'C': {
                // TODO
                break;
            }
            case 'J': {
                // TODO
                break;
            }
            default: {
                codeFile << "0 0" << std::endl;

                file.close();
                dataFile.close();
                codeFile.close();

                return 0;
            }
        }
    }


    return 0;
}