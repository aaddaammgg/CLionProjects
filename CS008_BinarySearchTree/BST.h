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

    void insert(TreeNode<T>*& node, const T& item);
    void remove(TreeNode<T>*& node, const T& item);
    void remove_max(TreeNode<T>*& node, T& item);
    static void output(T& item);
    TreeNode<T>* createNode(T item);
    void DestructBST(TreeNode<T>* node);

    void inorder(TreeNode<T>* node, void f(T&));
    void preorder(TreeNode<T>* node, void f(T&));
    void postorder(TreeNode<T>* node, void f(T&));
public:
    BST();
    ~BST();
//    BST();

    void insert(const T& item);
    void remove(const T& item);
    void traverse(Traversal traverse, void f(T&));
    void output(Traversal trav);
    bool isEmpty();
};

#include "BST.cpp"

#endif //CS008_BINARYSEARCHTREE_BST_H
