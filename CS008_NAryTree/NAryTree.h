//
// Created by Adam G. on 4/11/22.
//

#ifndef CS008_NARYTREE_NARYTREE_H
#define CS008_NARYTREE_NARYTREE_H

#include <iostream>
#include "Node.h"

class NAryTree {
private:
    Node* root = nullptr;

    void insert(Node* node, std::string item);
    Node* find(Node* node, std::string path);
    void print(std::ostream& out, Node* node) const;
    std::vector<std::string> split(std::string str, const std::string& delimiter);
public:

    NAryTree();
    void insert(std::string path, std::string item);

    friend std::ostream& operator<<(std::ostream& out, const NAryTree& tree);
};


#endif //CS008_NARYTREE_NARYTREE_H
