//
// Created by Adam G. on 2/9/22.
//

#ifndef RPN_RPN_H
#define RPN_RPN_H

#include <stack>
#include <string>
#include <cassert>
#include <iostream>
#include <cmath>

class RPN {
public:
    static std::string infixToPostFix(std::string expression);
    static int solvePostFix(std::string expression);
    static int solveOperation(char c, int left, int right);
    static bool isOperator(char c);
    static bool lessPrecedence(char top, char input);
    static int convert(char op);
};


#endif //RPN_RPN_H
