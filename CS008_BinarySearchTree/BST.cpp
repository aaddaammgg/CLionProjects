//
// Created by Adam G. on 2/23/22.
//

#ifndef CS008_BINARYSEARCHTREE_BST_CPP
#define CS008_BINARYSEARCHTREE_BST_CPP

#include "BST.h"

template<class T>
BST<T>::BST() {

}

template<class T>
BST<T>::~BST() {

}

template<class T>
void BST<T>::insert(TreeNode<T> *&node, const T &item) {
    if (isEmpty()) {
        addFirstNode(item);
    } else if (item >= node->data) {
        if (node->right == nullptr) {
            node->right = createNode(item);
        } else {
            insert(node->right, item);
        }
    } else if (item < node->data) {
        if (node->left == nullptr) {
            node->left = createNode(item);
        } else {
            insert(node->left, item);
        }
    }
}

template<class T>
void BST<T>::inorder(TreeNode<T> *node, void f(T &)) {
    if (node != nullptr) {
        inorder(node->left, f);
        f(node->data);
        inorder(node->right, f);
    }
}

template<class T>
void BST<T>::preorder(TreeNode<T> *node, void f(T &)) {
    if (node != nullptr) {
        f(node->data);
        preorder(node->left, f);
        preorder(node->right, f);
    }
}

template<class T>
void BST<T>::postorder(TreeNode<T> *node, void f(T &)) {
    if (node != nullptr) {
        postorder(node->left, f);
        postorder(node->right, f);
        f(node->data);
    }
}

template<class T>
void BST<T>::insert(const T &item) {
    insert(root, item);
}

template<class T>
void BST<T>::traverse(Traversal traverse, void f(T &)) {
    switch (traverse) {
        case PREORDER:
            preorder(root, f);
            return;
        case INORDER:
            inorder(root, f);
            return;
        case POSTORDER:
            postorder(root, f);
            return;
    }
}

template<class T>
TreeNode<T> *BST<T>::createNode(T item) {
    TreeNode<T>* n = new TreeNode<T>;
    n->data = item;

    return n;
}

template<class T>
void BST<T>::addFirstNode(T item) {
    root = createNode(item);
}

template<class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

template<class T>
void BST<T>::output() {

}

#endif //CS008_BINARYSEARCHTREE_BST_CPP