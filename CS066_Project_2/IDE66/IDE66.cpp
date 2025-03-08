#include <iostream>
#include <fstream>
#include <map>

struct variable {
    int address;
    int value;
};

int main() {
    std::cout << "Adam Gonzalez (10275803)" << std::endl << std::endl;

    std::string sourceFileName = "mysource.txt";
    std::string dataFileName = "data.txt";
    std::string codeFileName = "code.txt";

    std::ifstream file(sourceFileName);
    std::ofstream dataWriteFile(dataFileName);
    std::ofstream codeWriteFile(codeFileName);

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

    std::map <char, variable> symbolTable;
    int symbolSize = 0;

    while (!file.eof()) {
        file >> command;

        switch (command) {
            case 'd': {
                file >> var;

                int data;
                file >> data;

                dataWriteFile << data << std::endl;

                symbolTable[var] = {symbolSize++, data};

                break;
            }
            case 'G': {
                file >> var;

                codeWriteFile << ASMA.at(command) << ' ';

                if (!symbolTable.contains(var)) {
                    break;
                }

                accum = symbolTable[var].value;
                codeWriteFile << symbolTable[var].address << std::endl;

                break;
            }
            case 'P': {
                file >> var;

                codeWriteFile << ASMA.at(command) << ' ' << symbolTable[var].address << std::endl;

                symbolTable[var].value = accum;

                break;
            }
            case 'A': {
                file >> var;

                codeWriteFile << ASMA.at(command) << ' ' << symbolTable[var].address << std::endl;

                accum += symbolTable[var].value;

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
                codeWriteFile << "0 0" << std::endl;

                file.close();
                dataWriteFile.close();
                codeWriteFile.close();
            }
        }
    }

    std::ifstream dataReadFile(dataFileName);
    std::ifstream codeReadFile(codeFileName);

    if (dataReadFile.fail() || codeReadFile.fail()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    int num;
    int dataSize = 0;

    while (dataReadFile >> num) {
        dataSize++;
    }

    dataReadFile.close();

    int* memory = new int[dataSize];

    dataReadFile.open(dataFileName);

    int i = 0;
    while (dataReadFile >> num) {
        memory[i++] = num;
    }

    dataReadFile.close();

    int instruction, address;
    accum = 0;

    bool isFirstTime = true;

    while (!codeReadFile.eof()) {
        codeReadFile >> instruction;

        std::cout << "Register " << (isFirstTime ? "?" : std::to_string(accum)) << " Memory ";

        for (int i = 0; i < dataSize; i++) {
            std::cout << memory[i] << ' ';
        }

        for (int i = 0; i < 10 - dataSize; i++) {
            std::cout << "? ";
        }

        std::cout << std::endl;

        switch (instruction) {
            case 1: { // GET
                codeReadFile >> address;
                accum = memory[address];
                isFirstTime = false;

                break;
            }
            case 2: { // PUT
                codeReadFile >> address;
                memory[address] = accum;

                break;
            }
            case 3: { // ADD
                codeReadFile >> address;
                accum += memory[address];
                isFirstTime = false;

                break;
            }
            case 4: { // COMPLIMENT
                // TODO
                break;
            }
            case 5: { // COMPARE
                // TODO
                break;
            }
            case 6: { // JUMP
                // TODO
                break;
            }
            default: { // STOP
                dataReadFile.close();
                codeReadFile.close();

                delete memory;

                return 0;
            }
        }
    }

    delete memory;

    return 0;
}