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

    void deleteSubtree(BTreeNode* tree);

    bool getIsPreemptiveSplit();

    void insertElement(int key);
    void insert(BTreeNode* tree, int key);
    void insertNonFull(BTreeNode* tree, int key);
    void insertRepair(BTreeNode* tree);

    void removeElement(int key);
    void remove(BTreeNode* tree, int key);
    void removeNotEmpty(BTreeNode* tree, int key);
    void removeRepair(BTreeNode* tree);

    BTreeNode* search(int key);
    BTreeNode* splitChild(BTreeNode* tree);
    BTreeNode* merge(BTreeNode* tree);
    BTreeNode* borrowFromLeft(BTreeNode* tree, int parentIndex);
    BTreeNode* borrowFromRight(BTreeNode* tree, int parentIndex);

    void print();

};

#endif //BTREE_H
