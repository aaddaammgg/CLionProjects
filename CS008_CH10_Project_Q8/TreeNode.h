//
// Created by Adam G. on 2/23/22.
//

#ifndef CS008_BINARYSEARCHTREE_TREENODE_H
#define CS008_BINARYSEARCHTREE_TREENODE_H

template <class T>
struct TreeNode {
    T data;
    TreeNode<T>* left = nullptr;
    TreeNode<T>* right = nullptr;
};

#endif //CS008_BINARYSEARCHTREE_TREENODE_H
