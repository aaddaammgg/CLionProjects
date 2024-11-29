//
// Created by Adam G. on 11/28/24.
//

#include "BTreeNode.h"

BTreeNode::BTreeNode() {
    m_isLeaf = true;
    m_count = 0;
    m_parent = nullptr;

    for (auto & i : m_key) {
        i = 0;
    }

    for (auto & i : m_child) {
        i = nullptr;
    }
}

int* BTreeNode::getKey() {
    return m_key;
}

BTreeNode** BTreeNode::getChild() {
    return m_child;
}

BTreeNode*& BTreeNode::getParent() {
    return m_parent;
}

int BTreeNode::getCount() {
    return m_count;
}

bool BTreeNode::isLeaf() {
    return m_isLeaf;
}

void BTreeNode::setCount(int count) {
    m_count = count;
}

void BTreeNode::setLeaf(bool leaf) {
    m_isLeaf = leaf;
}

void BTreeNode::incCount() {
    m_count++;
}

void BTreeNode::decCount() {
    m_count--;
}

void BTreeNode::print() {
    if (m_isLeaf) {
        for (int i = 0; i < m_count; i++) {
            cout << m_key[i];

            if (i < m_count - 1){
                cout << " ";
            }
        }
        cout << endl;
    } else {
        for (int i = 0; i < m_count; i++) {
            if (m_child[i] != nullptr) {
                m_child[i]->print();
            }

            cout << m_key[i] << endl;
        }

        if (m_child[m_count] != nullptr){
            m_child[m_count]->print();
        }
    }
}
