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
        root = nullptr;
    }
}

template<class T>
void BST<T>::insert(TreeNode<T> *&node, const T &data) {
    if (node == nullptr) {
        node = createNode(data);
    } else if (data <= node->data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

template<class T>
void BST<T>::insert(const T &data) {
    insert(root, data);
}

template<class T>
void BST<T>::remove(TreeNode<T> *&node, const T &target) {
    if (node != nullptr) {
        if (target > node->data) {
            remove(node->right, target);
        } else if (target < node->data) {
            remove(node->left, target);
        } else {
            if (node->left == nullptr) {
                TreeNode<T>* temp = node; // reserve
                node = node->right;
                delete temp;
            } else {
                remove_max(node->left, node->data);
            }
        }
    }
}

template<class T>
void BST<T>::remove(const T &target) {
    remove(root, target);
}

template<class T>
void BST<T>::remove_max(TreeNode<T> *&node, T &target) {
    if (node != nullptr) {
        if (node->right == nullptr) {
            target = node->data;
            TreeNode<T>* temp = node; // reserve
            node = node->left;
            delete temp;
        } else {
            remove_max(node->right, target);
        }
    }
}

template<class T>
TreeNode<T> *BST<T>::search(TreeNode<T> *node, const T &data) {
    if (node->data == data) {
        return node;
    } else if (node->data < data) {
        search(node->left, data);
    } else if (node->data > data) {
        search(node->right, data);
    } else {
        return nullptr;
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
TreeNode<T> *BST<T>::createNode(T data) {
    TreeNode<T>* n = new TreeNode<T>;
    n->data = data;

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
void BST<T>::output(T& data) {
    std::cout << data << " ";
}

#endif //CS008_BINARYSEARCHTREE_BST_CPP