//
// Created by Jacob Li on 11/5/24.
//

#include "BTreeNode.h"

BTreeNode::BTreeNode() : BTreeNode(true) {
}

BTreeNode::BTreeNode(bool leaf) {
    m_isLeaf = leaf;
    m_count = 0;
    for (int i = 0; i < MAX + 1; i++) {
        m_child[i] = nullptr;
    }
}

BTreeNode::~BTreeNode() {
    // You may add destructor logic here, if needed
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

void BTreeNode::setCount(int count) {
    m_count = count;
}


// Splits the child y of this node at index. The node y has MAX keys, and we create a new node z.
void BTreeNode::splitChild(int index, BTreeNode* y) {
    int mid = MAX / 2;  // For MAX=4, mid=2
    BTreeNode* z = new BTreeNode(y->m_isLeaf);
    z->m_count = mid;  // For MAX=4, z->m_count=4-2-1=1

    // Copy the last (MAX - mid - 1) keys from y to z
    for (int i = mid; i < MAX; i++) {
        z->m_key[i - mid] = y->m_key[i];
    }

    // Copy the children from y to z if y is not a leaf
    if (!y->m_isLeaf) {
        for (int i = 0; i <= z->m_count; i++) {
            z->m_child[i] = y->m_child[i + mid + 1];
        }
    }

    // Update the number of keys in y
    y->m_count = mid;  // Left node has mid keys after split

    // Move the child pointers of this node to create space for the new node
    for (int i = m_count; i >= index + 1; i--) {
        m_child[i + 1] = m_child[i];
    }

    // Link the new child to this node
    m_child[index + 1] = z;

    // Shift keys of this node to create space for the median key of y
    for (int i = m_count - 1; i >= index; i--) {
        m_key[i + 1] = m_key[i];
    }

    // The median key of y is moved up to this node
//    m_key[index] = y->m_key[mid];
//    m_count++;
}

// Inserts a new key in this node. This node is assumed to be non-full when this function is called
void BTreeNode::insertNonFull(int key) {
    int i = m_count - 1;

    if (m_isLeaf) {
        // Since this node is a leaf, find the correct position for the new key by moving all greater keys one step ahead
        while (i >= 0 && m_key[i] > key) {
            m_key[i + 1] = m_key[i];
            i--;
        }
        m_key[i + 1] = key;
        m_count++;
    } else {
        // This node is not a leaf, so find the child which will have the new key
        while (i >= 0 && m_key[i] > key) {
            i--;
        }
        i++;

        // If the found child is full, we split it
        if (m_child[i]->m_count == MAX) {
            splitChild(i, m_child[i]);

            // After splitting, the new key might have to go to the right child of the node
            if (m_key[i] < key) {
                i++;
            }
        }
        m_child[i]->insertNonFull(key);
    }
}

// Remove a key 'k' from this subtree rooted node
void BTreeNode::remove(int k) {
    int idx = 0;
    // Find the key in this node, if it exists
    while (idx < m_count && m_key[idx] < k) {
        idx++;
    }

    if (idx < m_count && m_key[idx] == k) {
        // The key to be removed is present in this node
        if (m_isLeaf) {
            removeFromLeaf(idx);
        } else {
            removeFromNonLeaf(idx);
        }
    } else {
        // If the key is not found in this node, it must be in a child node of this node
        if (m_isLeaf) {
            // If this is a leaf node and key is not in this node, then the key is not in the tree
            cout << "The key " << k << " does not exist in the tree.\n";
            return;
        }

        // This key is in a subtree rooted at this node
        bool flag = (idx == m_count);  // True if k is greater than all keys in this node

        // If the child where the key is supposed to exist has fewer than MIN keys, fill it
        if (!flag && m_child[idx]->m_count <= MIN) {
            fill(idx);
        }

        // If the last child was merged, it must have merged with the previous child, thus we check the (idx-1)th child
        if (flag && idx > m_count) {
            m_child[idx - 1]->remove(k);
        } else {
            m_child[idx]->remove(k);
        }
    }
}

// Remove the key at index 'idx' from this node, which is a leaf
void BTreeNode::removeFromLeaf(int idx) {
    // Move all keys after the idx-th position one step to the left
    for (int i = idx + 1; i < m_count; ++i) {
        m_key[i - 1] = m_key[i];
    }
    m_count--;
}

// Remove key from non-leaf node at index 'idx'
void BTreeNode::removeFromNonLeaf(int idx) {
    int k = m_key[idx];

    // We always choose the key from the left subtree (predecessor) to replace the node key
    // If the left child does not have enough keys, fill it first
    if (m_child[idx]->m_count < MIN) {
        fill(idx);
    }

    // After ensuring the left child has enough keys (at least MIN), get the predecessor
    int pred = getPredecessor(idx);
    m_key[idx] = pred;
    m_child[idx]->remove(pred);
}

// Get the predecessor of the key at index 'idx' in this node
int BTreeNode::getPredecessor(int idx) {
    // Move to the rightmost node in the left child to get the predecessor
    BTreeNode* cur = m_child[idx];
    while (!cur->m_isLeaf) {
        cur = cur->m_child[cur->m_count];
    }
    return cur->m_key[cur->m_count - 1];
}

// Get the successor of the key at index 'idx' in this node
int BTreeNode::getSuccessor(int idx) {
    // Move to the leftmost node in the right child to get the successor
    BTreeNode* cur = m_child[idx + 1];
    while (!cur->m_isLeaf) {
        cur = cur->m_child[0];
    }
    return cur->m_key[0];
}

// Fill the child node at index 'idx' which has less than MIN keys
void BTreeNode::fill(int idx) {
    // If the previous child exists and has more than MIN-1 keys, borrow from it
    if (idx != 0 && m_child[idx - 1]->m_count >= MIN) {
        borrowFromPrev(idx);
    }
        // If the next child exists and has more than MIN-1 keys, borrow from it
    else if (idx != m_count && m_child[idx + 1]->m_count >= MIN) {
        borrowFromNext(idx);
    }
        // Merge the child with its sibling
    else {
        if (idx != m_count) {
            merge(idx);
        } else {
            merge(idx - 1);
        }
    }
}

// Borrow a key from the previous child of the node at index 'idx'
void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode* child = m_child[idx];
    BTreeNode* sibling = m_child[idx - 1];

    // Shift all keys in child to the right by one
    for (int i = child->m_count - 1; i >= 0; --i) {
        child->m_key[i + 1] = child->m_key[i];
    }

    // If child is not a leaf, shift its child pointers
    if (!child->m_isLeaf) {
        for (int i = child->m_count; i >= 0; --i) {
            child->m_child[i + 1] = child->m_child[i];
        }
    }

    // Move the key from the parent to the child's first key
    child->m_key[0] = m_key[idx - 1];

    // If sibling is not a leaf, move its last child to child's first child
    if (!child->m_isLeaf) {
        child->m_child[0] = sibling->m_child[sibling->m_count];
        sibling->m_child[sibling->m_count] = nullptr;
    }

    m_key[idx - 1] = sibling->m_key[sibling->m_count - 1];

    child->m_count += 1;
    sibling->m_count -= 1;
}

// Borrow a key from the next child of the node at index 'idx'
void BTreeNode::borrowFromNext(int idx) {
    BTreeNode* child = m_child[idx];
    BTreeNode* sibling = m_child[idx + 1];

    // Insert the parent's key at the end of child
    child->m_key[child->m_count] = m_key[idx];

    // If child is not a leaf, move the sibling's first child to the child's last child
    if (!child->m_isLeaf) {
        child->m_child[child->m_count + 1] = sibling->m_child[0];
        sibling->m_child[0] = nullptr;
    }

    // Move the first key from sibling to parent
    m_key[idx] = sibling->m_key[0];

    // Shift all keys in sibling to the left by one
    for (int i = 1; i < sibling->m_count; ++i) {
        sibling->m_key[i - 1] = sibling->m_key[i];
    }

    // Shift sibling's children if sibling is not a leaf
    if (!sibling->m_isLeaf) {
        for (int i = 1; i <= sibling->m_count; ++i) {
            sibling->m_child[i - 1] = sibling->m_child[i];
        }
        sibling->m_child[sibling->m_count] = nullptr;
    }

    child->m_count += 1;
    sibling->m_count -= 1;
}

// Merge the child at index 'idx' with its sibling
void BTreeNode::merge(int idx) {
    BTreeNode* child = m_child[idx];
    BTreeNode* sibling = m_child[idx + 1];

    // Pull down the key from the current node and insertElement it into child
    child->m_key[MIN - 1] = m_key[idx];

    // Copy the keys from sibling to child
    for (int i = 0; i < sibling->m_count; ++i) {
        child->m_key[i + MIN] = sibling->m_key[i];
    }

    // Copy the children from sibling to child
    if (!child->m_isLeaf) {
        for (int i = 0; i <= sibling->m_count; ++i) {
            child->m_child[i + MIN] = sibling->m_child[i];
        }
    }

    // Move all keys after idx in this node to fill the gap
    for (int i = idx + 1; i < m_count; ++i) {
        m_key[i - 1] = m_key[i];
    }

    // Move child pointers after idx
    for (int i = idx + 2; i <= m_count; ++i) {
        m_child[i - 1] = m_child[i];
    }

    child->m_count += sibling->m_count + 1;
    m_count--;

    delete sibling;
    sibling = nullptr;
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
