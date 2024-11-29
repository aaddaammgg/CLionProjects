//
// Created by Adam G. on 11/28/24.
//

#include "BTree.h"

BTree::BTree() {
    root = nullptr;
}

BTree::~BTree() {
    deleteTree(root);
}

void BTree::deleteTree(BTreeNode *tree) {
    if (tree == nullptr) {
        return;
    }

    if (!tree->isLeaf()) {
        for (int i = 0; i < tree->getCount() + 1; i++) {
            deleteTree(tree->getChild()[i]);
        }
    }

    delete tree;
}

void BTree::insertElement(int key) {
    if (root == nullptr) {
        root = new BTreeNode;
        root->getKey()[0] = key;
        root->setCount(1);
    } else {
        if (root->getCount() == MAX) {
            splitChild(root);
        }

        insertNonFull(root, key);
    }
}

void BTree::insertNonFull(BTreeNode *tree, int key) {
    if (tree->isLeaf()) {
        tree->incCount();

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

void BTree::remove(BTreeNode *tree, int key) {
    if (tree == nullptr) {
        return;
    }

    int i = 0;

    while (i < tree->getCount() && tree->getKey()[i] < key) {
        i++;
    }

    if (i == tree->getCount()) {
        if (!tree->isLeaf()) {
            remove(tree->getChild()[tree->getCount()], key);
        }
    } else if (tree->getKey()[i] > key && !tree->isLeaf()) {
        if (!tree->isLeaf()) {
            remove(tree->getChild()[i], key);
        }
    } else {
        if (tree->isLeaf()) {
            for (int j = i; j < tree->getCount() - 1; j++) {
                tree->getKey()[j] = tree->getKey()[j + 1];
            }

            tree->decCount();
            removeRepair(tree);
        } else {
            BTreeNode* maxNode = tree->getChild()[i];

            while (!maxNode->isLeaf()) {
                maxNode = maxNode->getChild()[maxNode->getCount()];
            }

            tree->getKey()[i] = maxNode->getKey()[maxNode->getCount() - 1];
            maxNode->decCount();

            removeRepair(maxNode);
        }
    }
}

void BTree::removeRepair(BTreeNode *tree) {
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

        while (parentNode->getChild()[parentIndex] != tree) {
            parentIndex++;
        }

        if (parentIndex > 0 && parentNode->getChild()[parentIndex - 1]->getCount() > MIN) {
            borrowFromLeft(tree, parentIndex);
        } else if (parentIndex < parentNode->getCount() && parentNode->getChild()[parentIndex + 1]->getCount() > MIN) {
            borrowFromRight(tree, parentIndex);
        } else if (parentIndex == 0) {
            BTreeNode* nextNode = merge(tree);
            removeRepair(nextNode->getParent());
        } else {
            BTreeNode* nextNode = merge(parentNode->getChild()[parentIndex - 1]);
            removeRepair(nextNode->getParent());
        }
    }
}

BTreeNode* BTree::splitChild(BTreeNode *tree) {
    BTreeNode* rightNode = new BTreeNode;
    rightNode->setCount(tree->getCount() - MIN - 1);

    int risingNode = tree->getKey()[MIN];

    if (tree->getParent() != nullptr) {
        BTreeNode* currentParent = tree->getParent();
        int parentIndex = 0;

        while (parentIndex < currentParent->getCount() + 1 && currentParent->getChild()[parentIndex] != tree) {
            parentIndex++;
        }

        if (parentIndex == currentParent->getCount() + 1) {
            std::cout << "ERROR Could not find child" << std::endl;
            return nullptr;
        }

        for (int i = currentParent->getCount(); i > parentIndex; i--) {
            currentParent->getChild()[i + 1] = currentParent->getChild()[i];
            currentParent->getKey()[i] = currentParent->getKey()[i - 1];
        }

        currentParent->incCount();
        currentParent->getKey()[parentIndex] = risingNode;
        currentParent->getChild()[parentIndex + 1] = rightNode;

        rightNode->getParent() = currentParent;
    }

    for (int i = MIN + 1; i < tree->getCount() + 1; i++) {
        rightNode->getChild()[i - MIN - 1] = tree->getChild()[i];

        if (tree->getChild()[i] != nullptr) {
            rightNode->setLeaf(false);

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

    root = new BTreeNode;

    root->setLeaf(false);
    root->setCount(1);

    root->getKey()[0] = risingNode;

    root->getChild()[0] = leftNode;
    root->getChild()[1] = rightNode;

    leftNode->getParent() = root;
    rightNode->getParent() = root;

    return root;
}

void BTree::borrowFromLeft(BTreeNode *tree, int parentIndex) {
    BTreeNode* parentNode = tree->getParent();
    tree->incCount();

    for (int i = tree->getCount() - 1; i > 0; i--) {
        tree->getKey()[i] = tree->getKey()[i - 1];
    }

    BTreeNode* leftSiblingNode = parentNode->getChild()[parentIndex - 1];

    if (!tree->isLeaf()) {
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
    leftSiblingNode->decCount();
}

void BTree::borrowFromRight(BTreeNode *tree, int parentIndex) {
    BTreeNode* parentNode = tree->getParent();
    tree->incCount();

    BTreeNode* rightSiblingNode = parentNode->getChild()[parentIndex + 1];

    tree->getKey()[tree->getCount() - 1] = parentNode->getKey()[parentIndex];
    parentNode->getKey()[parentIndex] = rightSiblingNode->getKey()[0];

    if (!tree->isLeaf()) {
        tree->getChild()[tree->getCount()] = rightSiblingNode->getChild()[0];
        tree->getChild()[tree->getCount()]->getParent() = tree;

        for (int i = 1; i < rightSiblingNode->getCount() + 1; i++) {
            rightSiblingNode->getChild()[i - 1] = rightSiblingNode->getChild()[i];
        }
    }

    for (int i = 1; i < rightSiblingNode->getCount(); i++) {
        rightSiblingNode->getKey()[i - 1] = rightSiblingNode->getKey()[i];
    }

    rightSiblingNode->decCount();
}

BTreeNode* BTree::merge(BTreeNode *tree) {
    BTreeNode* parentNode = tree->getParent();
    int parentIndex = 0;

    while (parentNode->getChild()[parentIndex] != tree) {
        parentIndex++;
    }

    BTreeNode* rightSiblingNode = parentNode->getChild()[parentIndex + 1];

    tree->getKey()[tree->getCount()] = parentNode->getKey()[parentIndex];

    for (int i = 0; i < rightSiblingNode->getCount(); i++) {
        tree->getKey()[tree->getCount() + i + 1] = rightSiblingNode->getKey()[i];
    }

    if (!tree->isLeaf()) {
        for (int i = 0; i <= rightSiblingNode->getCount(); i++) {
            tree->getChild()[tree->getCount() + i + 1] = rightSiblingNode->getChild()[i];
            tree->getChild()[tree->getCount() + i + 1]->getParent() = tree;
        }
    }

    for (int i = parentIndex + 1; i < parentNode->getCount(); i++) {
        parentNode->getChild()[i] = parentNode->getChild()[i + 1];
        parentNode->getKey()[i - 1] = parentNode->getKey()[i];
    }

    parentNode->decCount();
    tree->setCount(tree->getCount() + rightSiblingNode->getCount() + 1);

    return tree;
}

void BTree::print() {
    if (root == nullptr) {
        return;
    }

    root->print();
    cout << endl;
}
