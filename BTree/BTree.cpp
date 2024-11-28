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
        if (!tree->getIsLeaf()) {
            remove(tree->getChild()[tree->getCount()], key);
        }
    } else if (tree->getKey()[i] > key && !tree->getIsLeaf()) {
        if (!tree->getIsLeaf()) {
            remove(tree->getChild()[i], key);
        }
    } else {
        if (tree->getIsLeaf()) {
            for (int j = i; j < tree->getCount() - 1; j++) {
                tree->getKey()[j] = tree->getKey()[j + 1];
            }

            tree->getCount()--;
            removeRepair(tree);
        } else {
            BTreeNode* maxNode = tree->getChild()[i];

            while (!maxNode->getIsLeaf()) {
                maxNode = maxNode->getChild()[maxNode->getCount()];
            }

            tree->getKey()[i] = maxNode->getKey()[maxNode->getCount() - 1];
            maxNode->getCount()--;

            removeRepair(maxNode);
        }
    }

}

void BTree::removeRepair(BTreeNode* tree) {
    if (tree == nullptr || tree->getCount() > MIN) {
        return;
    }

    if (tree->getParent() == nullptr) {
        if (tree->getCount() == 0) {
            root = tree->getChild()[0];

            if (root != nullptr && root->getParent() != nullptr) {
                delete root->getParent();
                root->getParent() = nullptr;
            }
        }
    } else {
        BTreeNode* parentNode = tree->getParent();

        int parentIndex = 0;
        for (; parentNode->getChild()[parentIndex] != tree; parentIndex++) {
        }

        if (parentIndex > 0 && parentNode->getChild()[parentIndex - 1]->getCount() > MIN) {
            borrowFromLeft(tree, parentIndex);
        } else if (parentIndex < parentNode->getCount() && parentNode->getChild()[parentIndex + 1]->getCount() > MIN) {
            borrowFromRight(tree, parentIndex);
        } else if (parentIndex == 0) {
            BTreeNode* nextNode = merge(tree);
            removeRepair(nextNode->getParent());
        } else {
            BTreeNode nextNode = merge(parentNode->getChild()[parentIndex - 1]);
            removeRepair(nextNode.getParent());
        }
    }
}

void BTree::borrowFromLeft(BTreeNode* tree, int parentIndex) {
    BTreeNode* parentNode = tree->getParent();
    tree->getCount()++;

    for (int i = tree->getCount() - 1; i > 0; i--) {
        tree->getKey()[i] = tree->getKey()[i - 1];
    }

    BTreeNode* leftSiblingNode = parentNode->getChild()[parentIndex - 1];

    if (!tree->getIsLeaf()) {
        for (int i = tree->getCount(); i > 0; i--) {
            tree->getChild()[i] = tree->getChild()[i - 1];
        }
        tree->getChild()[0] = leftSiblingNode->getChild()[leftSiblingNode->getCount()];

        delete leftSiblingNode->getChild()[leftSiblingNode->getCount()];
        leftSiblingNode->getChild()[leftSiblingNode->getCount()] = nullptr;

        tree->getChild()[0]->getParent() = tree;
    }

    tree->getKey()[0] = parentNode->getKey()[parentIndex - 1];
    parentNode->getKey()[parentIndex - 1] = leftSiblingNode->getKey()[leftSiblingNode->getCount() - 1];
    leftSiblingNode->getCount()--;
}

void BTree::borrowFromRight(BTreeNode* tree, int parentIndex) {
    BTreeNode* parentNode = tree->getParent();
    tree->getCount()++;

    BTreeNode* rightSiblingNode = parentNode->getChild()[parentIndex + 1];

    tree->getKey()[tree->getCount() - 1] = parentNode->getKey()[parentIndex];
    parentNode->getKey()[parentIndex] = rightSiblingNode->getKey()[0];

    if (!tree->getIsLeaf()) {
        tree->getChild()[tree->getCount()] = rightSiblingNode->getChild()[0];
        tree->getChild()[tree->getCount()]->getParent() = tree;

        for (int i = 1; i < rightSiblingNode->getCount() + 1; i++) {
            rightSiblingNode->getChild()[i - 1] = rightSiblingNode->getChild()[i];
        }
    }

    for (int i = 1; i < rightSiblingNode->getCount(); i++) {
        rightSiblingNode->getKey()[i - 1] = rightSiblingNode->getKey()[i];
    }

    rightSiblingNode->getCount()--;
}

BTreeNode* BTree::merge(BTreeNode* tree) {
    BTreeNode* parentNode = tree->getParent();
    int parentIndex = 0;

    for (; parentNode->getChild()[parentIndex] != tree; parentIndex++) {

    }

    BTreeNode* rightSiblingNode = parentNode->getChild()[parentIndex + 1];

    tree->getKey()[tree->getCount()] = parentNode->getKey()[parentIndex];

    for (int i = 0; i < rightSiblingNode->getCount(); i++) {
        tree->getKey()[tree->getCount() + i + 1] = rightSiblingNode->getKey()[i];
    }

    if (!tree->getIsLeaf()) {
        for (int i = 0; i <= rightSiblingNode->getCount(); i++) {
            tree->getChild()[tree->getCount() + i + 1] = rightSiblingNode->getChild()[i];
            tree->getChild()[tree->getCount() + i + 1]->getParent() = tree;
        }
    }

    for (int i = parentIndex + 1; i < parentNode->getCount(); i++) {
        parentNode->getChild()[i] = parentNode->getChild()[i + 1];
        parentNode->getKey()[i - 1] = parentNode->getKey()[i];
    }

    parentNode->getCount()--;
    tree->getCount() += rightSiblingNode->getCount() + 1;

    return tree;
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
