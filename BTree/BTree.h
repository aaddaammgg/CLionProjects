#ifndef BTREE_H
#define BTREE_H

#include "BTreeNode.h"

class BTree {
private:
    BTreeNode* root;

public:
    BTree();
    ~BTree();

    void insertElement(int key);
    void removeElement(int key);
    BTreeNode* search(int key);
    BTreeNode* splitChild(BTreeNode* old);
    void remove(BTreeNode* tree, int key);
    void removeRepair(BTreeNode* tree);
    void borrowFromLeft(BTreeNode* tree, int parentIndex);
    void borrowFromRight(BTreeNode* tree, int parentIndex);
    BTreeNode* merge(BTreeNode* tree);
    void insert(BTreeNode* tree, int key);
    void insertRepair(BTreeNode* tree);
    void insertNonFull(BTreeNode* tree, int key);
    void print();

};

#endif //BTREE_H
