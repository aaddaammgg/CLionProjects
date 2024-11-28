#ifndef BTREE_H
#define BTREE_H

#include "BTreeNode.h"

class BTree {
private:
    BTreeNode* root;
    bool isPreemptiveSplit;

public:
    BTree(bool preemptiveSplit = true);
    ~BTree();

    bool getIsPreemptiveSplit();

    void insertElement(int key);
    void removeElement(int key);
    BTreeNode* search(int key);
    BTreeNode* splitChild(BTreeNode* old);
    void removeNotEmpty(BTreeNode* tree, int key);
    void remove(BTreeNode* tree, int key);
    void removeRepair(BTreeNode* tree);
    BTreeNode* borrowFromLeft(BTreeNode* tree, int parentIndex);
    BTreeNode* borrowFromRight(BTreeNode* tree, int parentIndex);
    BTreeNode* merge(BTreeNode* tree);
    void insert(BTreeNode* tree, int key);
    void insertRepair(BTreeNode* tree);
    void insertNonFull(BTreeNode* tree, int key);
    void print();

};

#endif //BTREE_H
