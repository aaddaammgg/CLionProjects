#include "BTree.h"
#include <iostream>
using namespace std;

BTree::BTree(bool preemptiveSplit) {
    isPreemptiveSplit = preemptiveSplit;
    root = nullptr;
}

BTree::~BTree() {
    deleteSubtree(root);
}

void BTree::deleteSubtree(BTreeNode* tree) {
    if (tree == nullptr) return;

    if (!tree->getIsLeaf()) {
        int numChildren = tree->getCount() + 1;
        for (int i = 0; i < numChildren; i++) {
            deleteSubtree(tree->getChild()[i]);
        }
    }

    delete tree;
}

bool BTree::getIsPreemptiveSplit() {
    return isPreemptiveSplit;
}

void BTree::insertElement(int key) {
    if (root == nullptr) {
        // Tree is empty, create a new root
        root = new BTreeNode(true);
        root->getKey()[0] = key;
        root->setCount(1);
    } else {
        if (getIsPreemptiveSplit()) {
            if (root->getCount() == MAX) {
                splitChild(root);
            }

            insertNonFull(root, key);
        } else {
            insert(root, key);
        }
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
    if (getIsPreemptiveSplit() && (MAX + 1) % 2 == 0) {
        removeNotEmpty(root, key);
    } else {
        remove(root, key);
    }

    if (root->getCount() == 0) {
        root = root->getChild()[0];
        delete root->getParent();
        root->getParent() = nullptr;
    }
}

void BTree::removeNotEmpty(BTreeNode* tree, int key) {
    if (tree == nullptr) {
        return;
    }

    int i = 0;

    for (; i < tree->getCount() && tree->getKey()[i] < key; i++) {

    }

    BTreeNode* nextNode;

    if (i == tree->getCount()) {
        if (!tree->getIsLeaf()) {
            if (tree->getChild()[tree->getCount()]->getCount() == MIN) {

                if (tree->getChild()[tree->getCount() - 1]->getCount() > MIN) {
                    nextNode = borrowFromLeft(tree->getChild()[tree->getCount()], tree->getCount());
                    removeNotEmpty(nextNode, key);
                } else {
                    nextNode = merge(tree->getChild()[tree->getCount() - 1]);
                    removeNotEmpty(nextNode, key);
                }
            } else {
                removeNotEmpty(tree->getChild()[tree->getCount()], key);
            }
        }
    } else if (tree->getKey()[i] > key) {
        if (!tree->getIsLeaf()) {
            if (tree->getChild()[i]->getCount() > MIN) {
                removeNotEmpty(tree->getChild()[i], key);
            } else {
                if (tree->getChild()[i + 1]->getCount() > MIN) {
                    nextNode = borrowFromRight(tree->getChild()[i], i);
                    removeNotEmpty(nextNode, key);
                } else {
                    nextNode = merge(tree->getChild()[i]);
                    removeNotEmpty(nextNode, key);
                }
            }
        }
    } else {
        if (tree->getIsLeaf()) {
            for (int j = i; j < tree->getCount() - 1; j++) {
                tree->getKey()[j] = tree->getKey()[j + 1];
            }

            tree->getCount()--;
        } else {
            BTreeNode* maxNode = tree->getChild()[i];

            if (tree->getChild()[i]->getCount() == MIN) {
                if (tree->getChild()[i + 1]->getCount() == MIN) {
                    nextNode = merge(tree->getChild()[i]);
                    removeNotEmpty(nextNode, key);

                    return;
                } else {
                    BTreeNode* minNode = tree->getChild()[i + 1];

                    while (!minNode->getIsLeaf()) {
                        if (minNode->getChild()[0]->getCount() == MIN) {
                            if (minNode->getChild()[1]->getCount() == MIN) {
                                minNode = merge(minNode->getChild()[0]);
                            } else {
                                minNode = borrowFromRight(minNode->getChild()[0], 0);
                            }
                        } else {
                            minNode = minNode->getChild()[0];
                        }
                    }

                    tree->getKey()[i] = minNode->getKey()[0];

                    for (i = 1; i < minNode->getCount(); i++) {
                        minNode->getKey()[i - 1] = minNode->getKey()[i];
                    }

                    minNode->getCount()--;
                }
            } else {
                while (!maxNode->getIsLeaf()) {
                    if (maxNode->getChild()[maxNode->getCount()]->getCount() == MIN) {
                        if (maxNode->getChild()[maxNode->getCount() - 1]->getCount() > MIN) {
                            maxNode = borrowFromLeft(maxNode->getChild()[maxNode->getCount()], maxNode->getCount());
                        } else {
                            maxNode = merge(maxNode->getChild()[maxNode->getCount() - 1]);
                        }
                    } else {
                        maxNode = maxNode->getChild()[maxNode->getCount()];
                    }
                }

                tree->getKey()[i] = maxNode->getKey()[maxNode->getCount() - 1];
                maxNode->getCount()--;
            }
        }
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

BTreeNode* BTree::borrowFromLeft(BTreeNode* tree, int parentIndex) {
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

    return tree;
}

BTreeNode* BTree::borrowFromRight(BTreeNode* tree, int parentIndex) {
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

    return tree;
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
