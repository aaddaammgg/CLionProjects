#include <iostream>
#include "HashTable.h"
#include <vector>

int main() {
    std::vector<int> keys;
    HashTable<std::string> table;

    for (int i = 0; i < 10; i++) {
        int key = rand() % (9001) + 10000;
        keys.push_back(key);
        const std::string val = "string" + std::to_string(i);
        table.insert(key, val);
        std::cout << "key: " << key << ", value: " << val << std::endl;
    }

    std::cout << "####################" << std::endl;

    for (int i : keys) {
        std::cout << "key: " << i << ", value: " << table[i] << std::endl;
    }
    return 0;
}
