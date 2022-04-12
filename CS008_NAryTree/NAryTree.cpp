//
// Created by Adam G. on 4/11/22.
//

#include "NAryTree.h"

NAryTree::NAryTree() {

}

std::vector<std::string> NAryTree::split(std::string str, const std::string& delimiter) {
    std::vector<std::string> splitStrings;
    std::size_t index;
    std::string token;

    while ((index = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, index);
        splitStrings.push_back(token);
        str.erase(0, index + delimiter.length());
    }

    splitStrings.push_back(str);

    return splitStrings;
}

void NAryTree::insert(Node *node, std::string item) {
    Node* n = new Node;
    n->data = item;

    node->children.push_back(n);
}

void NAryTree::insert(std::string path, std::string item) {
    if (root == nullptr) {
        root = new Node;
        root->data = path;

        Node* n = new Node;
        n->data = item;
        root->children.push_back(n);

        return;
    }

    std::vector<std::string> paths = split(path, "/");
    Node* n = find(root, paths[0]);

    for(int i = 1; i < paths.size(); i++) {
        if (n == nullptr) {
            break;
        }
        n = find(n, paths[i]);
    }


    if (n == nullptr) {

    } else {
        insert(n, item);
    }
}

Node *NAryTree::find(Node* node, std::string path) {
    if (node->data == path) {
        return node;
    }

    for (Node* n : node->children) {
        node = find(n, path);
    }

    return node;
}

void NAryTree::print(std::ostream &out, Node *node) const {
    if (node == nullptr) {
        return;
    }

    if (node->children.empty()) {
        out << node->data;
        return;
    }

    out << node->data << '/'; // folder

    for (Node* n : node->children) {
        print(out, n);
    }
}

std::ostream &operator<<(std::ostream &out, const NAryTree &tree) {
    tree.print(out, tree.root);

    return out;
}
