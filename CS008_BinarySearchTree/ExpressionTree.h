//
// Created by Adam G. on 3/16/22.
//

#ifndef CS008_BINARYSEARCHTREE_EXPRESSIONTREE_H
#define CS008_BINARYSEARCHTREE_EXPRESSIONTREE_H

#include "BST.h"
#include <string>
#include <stack>

class ExpressionTree : public BST<char> {
private:
    bool isOperator(char &op);
    void addPostfix(std::string expression);
    void addInfix(std::string expression);
public:
    ExpressionTree();
    ExpressionTree(std::string expression);
    void add(std::string expression);


};


#endif //CS008_BINARYSEARCHTREE_EXPRESSIONTREE_H
