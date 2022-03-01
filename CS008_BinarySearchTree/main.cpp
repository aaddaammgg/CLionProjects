#include <iostream>
#include <vector>
#include "BST.h"

void fill(BST<int>& tree, int amt);
void doubleData(int& i);
void output(int& i);

int main() {
//    A<int> a(10);
//
//    a.doSomething(aFunction);
//    a.doSomething(anotherFunction);
//    a.doSomething(aFunction);

    BST<int> bst;

    fill(bst, 10);
    bst.output(INORDER);
    bst.traverse(INORDER, doubleData);
    bst.output(INORDER);

    return 0;
}

void fill(BST<int>& tree, int amt) {
    for (int i = 0; i < amt; ++i) {
        int r = rand() % 100;
        output(r);
        tree.insert(r);
    }
    std::cout << std::endl;
}

void doubleData(int& i) {
    i *= 2;
}

void output(int& i) {
    std::cout << i << " ";
}