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
    DestructBST(root);
}

template<class T>
void BST<T>::DestructBST(TreeNode<T> *node) {
    if (node) {
        DestructBST(node->left);
        DestructBST(node->right);
        delete node;
    }
}

template<class T>
void BST<T>::insert(TreeNode<T> *&node, const T &item) {
    if (node == nullptr) {
        node = createNode(item);
    } else if (item < node->data) {
        insert(node->left, item);
    } else {
        insert(node->right, item);
    }
}

template<class T>
void BST<T>::insert(const T &item) {
    insert(root, item);
}

template<class T>
void BST<T>::remove(TreeNode<T> *&node, const T &item) {

}

template<class T>
void BST<T>::remove(const T &item) {
    remove(root, item);
}

template<class T>
void BST<T>::remove_max(TreeNode<T> *&node, T &item) {

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
void BST<T>::traverse(Traversal traverse, void f(T &)) {
    switch (traverse) {
        case INORDER:
            inorder(root, f);
            return;
        case PREORDER:
            preorder(root, f);
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
bool BST<T>::isEmpty() {
    return root == nullptr;
}

template<class T>
void BST<T>::output(Traversal trav) {
    traverse(trav, output);
    std::cout << std::endl;
}

template<class T>
void BST<T>::output(T& item) {
    std::cout << item << " ";
}

#endif //CS008_BINARYSEARCHTREE_BST_CPP