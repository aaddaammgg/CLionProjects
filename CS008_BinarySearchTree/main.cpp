#include <iostream>
#include <vector>
#include "BST.h"

void fill(BST<int>& tree, int amt);
void doubleData(int& i);
void output(int& i);

void* operator new(size_t size) {
    std::cout << "(" << size << "B)";
    return malloc(size);
}

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

    {
        BST<int> tree;
        std::vector<int> v;
//        int a[10];

        for (int i = 0; i < 10; ++i) {
            int r = rand() % 100;
            output(r);
//            tree.insert(r);
//            v.push_back(r);
        }



        std::cout << std::endl << sizeof(std::vector<int>) + (sizeof(int) * v.size()) << std::endl;

        tree.output(INORDER);
        for (auto i : v) {
            std::cout << "Removing " << i << "..." << std::endl;
            tree.remove(i);
            tree.output(INORDER);
            std::cout << std::endl;
        }

        tree.remove(1);

        for (auto i : v) {
            tree.insert(i);
        }

        tree.output(INORDER);

//        fill(tree, 10);
//        tree.output(INORDER);
//        tree.traverse(INORDER, doubleData);
//        tree.output(INORDER);
    }

    std::cout << "hi" << std::endl;

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