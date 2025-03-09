#include <iostream>
#include <fstream>
#include <map>

struct variable {
    int address;
    int value;
};

struct instruction {
    char command;
    int address; // IF COMMAND IS JUMP THEN ADDRESS IS INSTRUCTION LOCATION, OTHERWISE IT IS DATA LOCATION
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

    bool running = true;
    char command, var;

    std::map <char, int> labelLocation;
    std::map <char, variable> symbolTable;
    int accum, symbolSize = 0;

    std::string line;
    int codeCount = 0;

    while (getline(file, line)) {
        if (line[0] == 'd' || line.empty()) {
            continue;
        }

        codeCount++;
    }

    instruction* inst = new instruction[codeCount];

    file.close();

    file.open(sourceFileName);

    if (file.fail()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    int actualCodeCount = 0;

    while (!file.eof() && running) {
        file >> command;

        if (file.peek() == '\n') {
            break;
        }

        if (command == ':') {
            char label;
            file >> label;

            labelLocation[label] = actualCodeCount;
            continue;
        }

        switch (command) {
            case 'd': {
                file >> var;

                int data;
                file >> data;

                dataWriteFile << data << std::endl;
                symbolTable[var] = {symbolSize++, data};

                actualCodeCount--;

                break;
            }
            case 'G':
            case 'P':
            case 'A':
            case 'C':
            case 'J': {
                file >> var;

                inst[actualCodeCount] = {command, var};
                break;
            }
            case 'N': {
                inst[actualCodeCount] = {command, 0};
                break;
            }
            default: {
                running = false;
                inst[actualCodeCount] = {'S', 0};
            }
        }

        actualCodeCount++;
    }

    file.close();

    bool compare;

    for (int i = 0; i < codeCount - 1; i++) {

        if (inst[i].command != 'C' && inst[i].command != 'J') {
            codeWriteFile << ASMA.at(inst[i].command) << ' ';

            if (inst[i].command == 'N') {
                codeWriteFile << 0;
            } else {
                codeWriteFile << symbolTable[inst[i].address].address;
            }

            codeWriteFile << std::endl;
        }

        switch (inst[i].command) {
            case 'G': {
                accum = symbolTable[(char)inst[i].address].value;
                break;
            }
            case 'P': {
                symbolTable[(char)inst[i].address].value = accum;
                break;
            }
            case 'A': {
                accum += symbolTable[(char)inst[i].address].value;
                break;
            }
            case 'N': {
                accum = ~accum;
                break;
            }
            case 'C': {
                compare = accum <= symbolTable[(char)inst[i].address].value;
                break;
            }
            case 'J': {
                if (compare) {
                    i = labelLocation[(char)inst[i].address] - 1;
                }
                break;
            }
            default: {
                i = codeCount;
            }
        }
    }

    codeWriteFile << "0 0" << std::endl;

    dataWriteFile.close();
    codeWriteFile.close();

    delete[] inst;

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

    int rawCommand = 0, address = 0;
    accum = 0;
    bool isFirstTime = true;
    running = true;

    while (!codeReadFile.eof() && running) {
        codeReadFile >> rawCommand;

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

        switch (rawCommand) {
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