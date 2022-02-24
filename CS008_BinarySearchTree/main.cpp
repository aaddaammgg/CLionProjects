#include <iostream>
#include "A.h"
#include "BST.h"

void aFunction(int& i);
void anotherFunction(int& i);

void output(int& i);

int main() {
//    A<int> a(10);
//
//    a.doSomething(aFunction);
//    a.doSomething(anotherFunction);
//    a.doSomething(aFunction);

    BST<int> bst;

    bst.insert(1);
    bst.insert(10);
    bst.insert(3);
    bst.insert(90);
    bst.insert(100);

    bst.traverse(INORDER, output);

    return 0;
}

void output(int& i) {
    std::cout << i << " ";
}

void aFunction(int& i) {
    std::cout << "A Function: " << i << std::endl;
}
void anotherFunction(int& i) {
    i *= 2;
    std::cout << "Another Function: " << i << std::endl;
}