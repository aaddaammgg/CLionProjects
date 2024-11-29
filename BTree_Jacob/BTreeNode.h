//
// Created by Adam G. on 11/28/24.
//

#ifndef BTREENODE_H
#define BTREENODE_H

#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 4;
const int MIN = ceil(MAX / 2.0);

class BTreeNode {
private:
    int m_key[MAX];
    BTreeNode* m_child[MAX + 1];
    BTreeNode* m_parent;
    bool m_isLeaf;
    int m_count;

public:
    BTreeNode();

    int* getKey();
    BTreeNode** getChild();
    BTreeNode*& getParent();
    int getCount();
    bool isLeaf();

    void setCount(int count);
    void setLeaf(bool leaf);

    void incCount();
    void decCount();

    void print();

};



#endif //BTREENODE_H
