#include "BTree.h"
#include <iostream>
using namespace std;

BTree::BTree() {
    root = nullptr;
}

BTree::~BTree() {
    // You can implement a destructor to clean up dynamic nodes if needed.
}

void BTree::insertElement(int key) {
    if (root == nullptr) {
        // Tree is empty, create a new root
        root = new BTreeNode(true);
        root->getKey()[0] = key;
        root->setCount(1);
    } else {
        insert(root, key);
    }
}

void BTree::insert(BTreeNode *tree, int key) {
    if (tree->getIsLeaf()) {
        tree->getCount()++;
        int insertIndex = tree->getCount() - 1;

        while (insertIndex > 0 && tree->getKey()[insertIndex - 1] > key) {
            tree->getKey()[insertIndex] = tree->getKey()[insertIndex - 1];
            insertIndex--;
        }

        tree->getKey()[insertIndex] = key;

        insertRepair(tree);
    } else {
        int findIndex = 0;
        while (findIndex < tree->getCount() && tree->getKey()[findIndex] < key) {
            findIndex++;
        }

        insert(tree->getChild()[findIndex], key);
    }

}

void BTree::insertRepair(BTreeNode *tree) {
    if (tree->getCount() <= MAX) {
        return;
    }

    if (tree->getParent() == nullptr) {
        root = splitChild(tree);
        return;
    }

    BTreeNode* newNode = splitChild(tree);
    insertRepair(newNode);

}

void BTree::insertNonFull(BTreeNode *tree, int key) {
    if (tree->getIsLeaf()) {
        tree->getCount()++;
        int insertIndex = tree->getCount() - 1;

        while (insertIndex > 0 && tree->getKey()[insertIndex - 1] > key) {
            tree->getKey()[insertIndex] = tree->getKey()[insertIndex - 1];
            insertIndex--;
        }

        tree->getKey()[insertIndex] = key;
    } else {
        int findIndex = 0;

        while (findIndex < tree->getCount() && tree->getKey()[findIndex] < key) {
            findIndex++;
        }

        if (tree->getChild()[findIndex]->getCount() == MAX) {
            BTreeNode* newTree = splitChild(tree->getChild()[findIndex]);
            insertNonFull(newTree, key);
        } else {
            insertNonFull(tree->getChild()[findIndex], key);
        }
    }
}

void BTree::removeElement(int key) {
    remove(root, key);

    if (root->getCount() == 0) {
        root = root->getChild()[0];
        delete root->getParent();
        root->getParent() = nullptr;
    }
}

void BTree::remove(BTreeNode* tree, int key) {
    if (tree == nullptr) {
        return;
    }

    int i = 0;

    for (; i < tree->getCount() && tree->getKey()[i] < key; i++) {

    }

    if (i == tree->getCount()) {

    }

}

BTreeNode* BTree::search(int key) {
    if (root == nullptr) {
        return nullptr;
    }

    return root->search(key);
}

BTreeNode* BTree::splitChild(BTreeNode* tree) {
    BTreeNode* rightNode = new BTreeNode(true);
    rightNode->setCount(tree->getCount() - MIN - 1);

    int risingNode = tree->getKey()[MIN];

    if (tree->getParent() != nullptr) {
        BTreeNode* currentParent = tree->getParent();
        int parentIndex = 0;
        for (; parentIndex < currentParent->getCount() + 1 && currentParent->getChild()[parentIndex] != tree; parentIndex++) {
        }

        if (parentIndex == currentParent->getCount() + 1) {
            std::cout << "ERROR" << std::endl;
            return nullptr;
        }

        for (int i = currentParent->getCount(); i > parentIndex; i--) {
            currentParent->getChild()[i + 1] = currentParent->getChild()[i];
            currentParent->getKey()[i] = currentParent->getKey()[i - 1];
        }

        currentParent->getCount()++;
        currentParent->getKey()[parentIndex] = risingNode;
        currentParent->getChild()[parentIndex + 1] = rightNode;
        rightNode->getParent() = currentParent;
    }

    for (int i = MIN + 1; i < tree->getCount() + 1; i++) {
        rightNode->getChild()[i - MIN - 1] = tree->getChild()[i];

        if (tree->getChild()[i] != nullptr) {
            rightNode->getIsLeaf() = false;
            tree->getChild()[i]->getParent() = rightNode;
            tree->getChild()[i] = nullptr; // ???
        }
    }

    for (int i = MIN + 1; i < tree->getCount(); i++) {
        rightNode->getKey()[i - MIN - 1] = tree->getKey()[i];
    }

    BTreeNode* leftNode = tree;
    leftNode->setCount(MIN);

    if (tree->getParent() != nullptr) {
        return tree->getParent();
    }

    root = new BTreeNode(false);

    root->getKey()[0] = risingNode;
    root->getCount() = 1;
    root->getChild()[0] = leftNode;
    root->getChild()[1] = rightNode;
    leftNode->getParent() = root;
    rightNode->getParent() = root;

    return root;
}

// Print using an in-order traversal.
void BTree::print() {
    if (root != nullptr) {
        root->print();
        cout << endl;
    } else {
        cout << "The tree is empty." << endl;
    }
}
