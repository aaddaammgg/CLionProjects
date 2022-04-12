#include <iostream>
#include "NAryTree.h"

int main() {
    NAryTree tree;

    std::string path = "folder 0";

    for (int i = 0; i < 3; i++) {
        tree.insert(path, "folder " + std::to_string(i + 1));
        path += "/folder " + std::to_string(i + 1);
        std::cout << "path: " << path << std::endl;
    }

//    tree.insert("Folder 1", "File 1");
//    tree.insert("File 1", "File 2");
//    tree.insert("Folder 1", "File 2");
//    tree.insert("Folder 1", "File 3");
//    tree.insert("File 3", "File 4");

    std::cout << tree << std::endl;
    return 0;
}
