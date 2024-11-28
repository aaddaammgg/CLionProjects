//
// Created by Jacob Li on 11/5/24.
//

#ifndef BTREENODE_H
#define BTREENODE_H
#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 4; // Maximum number of keys in a node
const int MIN = ceil(MAX / 2.0);

class BTreeNode {
private:
    int m_key[MAX];             // Array of keys
    BTreeNode* m_child[MAX + 1]; // Array of child pointers
    BTreeNode* m_parent;
    bool m_isLeaf;
    int m_count;                // Current number of keys

public:
    BTreeNode();
    BTreeNode(bool leaf);
    ~BTreeNode();

    int* getKey();
    BTreeNode** getChild();
    bool& getIsLeaf();
    BTreeNode*& getParent();
    int& getCount();

    void setCount(int count);

    void splitChild(int index, BTreeNode* old);
    void insertNonFull(int key);

    void remove(int k);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPredecessor(int idx);
    int getSuccessor(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);

    BTreeNode* search(int key);
    void print();

};

#endif //BTREENODE_H
