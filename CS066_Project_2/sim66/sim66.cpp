#include <iostream>
#include <fstream>

int main() {
    std::cout << "Adam Gonzalez (10275803)" << std::endl << std::endl;

    std::string dataFileName = "data.txt";
    std::string codeFileName = "code.txt";

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

    for (int i = 0; i < dataSize; i++) {
        dataReadFile >> memory[i];
    }

    dataReadFile.close();

    int command = 0, address = 0, accum = 0;
    bool isFirstTime = true, running = true;

    while (!codeReadFile.eof() && running) {
        codeReadFile >> command;

        if (codeReadFile.peek() == '\n') {
            break;
        }

        std::cout << "Register " << (isFirstTime ? "?" : std::to_string(accum)) << " Memory ";

        for (int i = 0; i < dataSize; i++) {
            std::cout << memory[i] << ' ';
        }

        for (int i = 0; i < 10 - dataSize; i++) {
            std::cout << "? ";
        }

        std::cout << std::endl;

        switch (command) {
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
                accum = ~accum;

                break;
            }
            default: { // STOP
                running = false;
            }
        }
    }

    codeReadFile.close();

    delete[] memory;

    return 0;
}