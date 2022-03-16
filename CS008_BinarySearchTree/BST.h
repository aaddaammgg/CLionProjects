//
// Created by Adam G. on 2/23/22.
//

#ifndef CS008_BINARYSEARCHTREE_BST_H
#define CS008_BINARYSEARCHTREE_BST_H

#include "TreeNode.h"
#include "Traversal.h"
#include <iostream>

template <class T>
class BST {
private:
    TreeNode<T>* root = nullptr;

    void insert(TreeNode<T>*& node, const T& data);
    void remove(TreeNode<T>*& node, const T& target);
    void remove_max(TreeNode<T>*& node, T& target);
    TreeNode<T>* search(TreeNode<T> *node, const T& data);
    static void output(T& data);
    TreeNode<T>* createNode(T data);
    void DestructBST(TreeNode<T>* node);

    void inorder(TreeNode<T>* node, void f(T&));
    void preorder(TreeNode<T>* node, void f(T&));
    void postorder(TreeNode<T>* node, void f(T&));
public:
    BST();
    ~BST();
//    BST();

    void insert(const T& data);
    void add(const T& data);
    void remove(const T& target);
    void traverse(Traversal traverse, void f(T&));
    void output(Traversal trav);
    bool isEmpty();

    BST<T>& operator+=(const T& rhs);
};

#include "BST.cpp"

#endif //CS008_BINARYSEARCHTREE_BST_H
