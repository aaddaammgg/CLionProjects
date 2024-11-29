//
// Created by Adam G. on 11/28/24.
//

#ifndef BTREE_H
#define BTREE_H

#include "BTreeNode.h"

class BTree {
private:
    BTreeNode* root;
public:
    BTree();
    ~BTree();

    void deleteTree(BTreeNode* tree);

    void insertElement(int key);
    void insertNonFull(BTreeNode* tree, int key);

    void removeElement(int key);
    void remove(BTreeNode* tree, int key);
    void removeRepair(BTreeNode* tree);

    BTreeNode* splitChild(BTreeNode* tree);
    BTreeNode* merge(BTreeNode* tree);
    void borrowFromLeft(BTreeNode* tree, int parentIndex);
    void borrowFromRight(BTreeNode* tree, int parentIndex);

    void print();
};



#endif //BTREE_H
