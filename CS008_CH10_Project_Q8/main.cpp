#include <iostream>
#include <vector>
#include "BST.h"
#include "LinkedList.h"

void fill(BST<int>& tree, int amt);
void doubleData(int& i);
void output(int& i);

//
//void operator delete(void* memory) {
//    std::cout << "Freeing bytes...\n";
//    free(memory);
//}
//
//void operator delete(void* memory, size_t size) noexcept {
//    std::cout << "Freeing " << size << " bytes...\n";
//    free(memory);
//}

int main() {
//    A<int> a(10);
//
//    a.doSomething(aFunction);
//    a.doSomething(anotherFunction);
//    a.doSomething(aFunction);

    srand(time(0));

//    LinkedList<int> b;
    BST<int> tree;

    fill(tree, 10);
    tree.output(INORDER);
    tree.traverse(BREADTH, add);

    for (auto i : b) {
        std::cout << i << " ";
    }


    return 0;
}

void fill(BST<int>& tree, int amt) {
    for (int i = 0; i < amt; ++i) {
        int r = rand() % 100;
//        output(r);
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