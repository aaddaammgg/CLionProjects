//
// Created by Adam G. on 3/16/22.
//

#include "ExpressionTree.h"

ExpressionTree::ExpressionTree() {

}

ExpressionTree::ExpressionTree(std::string expression) {
    add(expression);
}

void ExpressionTree::add(std::string expression) {
    if (isOperator(expression.at(expression.size()-1))) {
        addPostfix(expression);
    } //else {
//        addInfix(expression);
//    }
}

bool ExpressionTree::isOperator(char &op) {
    return op > 41 && op < 48;
}

void ExpressionTree::addPostfix(std::string expression) {
    std::stack<TreeNode<char>*> s;

    for (char c : expression) {
        TreeNode<char>* n = new TreeNode<char>;
        n->data = c;

        if (isOperator(c)) {
            n->right = s.top();
            s.pop();
            n->left = s.top();
            s.pop();
        }
        s.push(n);
    }
    root = s.top();
}

void ExpressionTree::addInfix(std::string expression) {

}
