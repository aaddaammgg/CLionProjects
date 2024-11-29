//
// Created by Jacob Li on 11/5/24.
//

#include "BTreeNode.h"

BTreeNode::BTreeNode() : BTreeNode(true) {
}

BTreeNode::BTreeNode(bool leaf) {
    m_isLeaf = leaf;
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

BTreeNode *&BTreeNode::getParent() {
    return m_parent;
}

BTreeNode** BTreeNode::getChild() {
    return m_child;
}

bool& BTreeNode::getIsLeaf() {
    return m_isLeaf;
}

int& BTreeNode::getCount() {
    return m_count;
}

// Search key in the subtree rooted with this node
BTreeNode* BTreeNode::search(int key) {
    int i = 0;
    while (i < m_count && key > m_key[i]) {
        i++;
    }

    if (i < m_count && m_key[i] == key) {
        return this;
    }

    if (m_isLeaf) {
        return nullptr;
    }

    return m_child[i]->search(key);
}

// Print the subtree rooted with this node
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
