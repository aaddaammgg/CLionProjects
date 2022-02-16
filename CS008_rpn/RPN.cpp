//
// Created by Adam G. on 2/9/22.
//

#include "RPN.h"

std::string RPN::infixToPostFix(std::string expression) {
    std::stack<char> operation;
    std::string output;
    std::string::iterator it = expression.begin();

    do {
        if (*it == '(') {
            operation.push(*it);
//            ++it;
        } else if (isdigit(*it) || isalpha(*it)) {
            output += *it;
//            ++it;
        } else if (isOperator(*it)) {
//            operation.push(*it);
            do {
                if (!operation.empty() && operation.top() != '(') {
                    output += operation.top();
                    operation.pop();
                }
            } while (
                    !operation.empty() &&
                    operation.top() != '(' &&
                    !lessPrecedence(operation.top(), *it) // added !
                    );
            // this may need to be swapped
            operation.push(*it);
//            ++it;
        } else {
            while (!operation.empty() && operation.top() != '(') {
                output += operation.top();
                operation.pop();
                if (operation.empty()) {
                    assert(operation.empty());
                }
            }
            if (!operation.empty()) {
                operation.pop();
            }
        }
        ++it;
    } while (it != expression.end());

    while (!operation.empty()) {
        output += operation.top();
        operation.pop();
    }

    return output;
}

int RPN::solvePostFix(std::string expression) {
    std::stack<int> numbers;
    std::string::iterator it = expression.begin();

    do {
        if (isOperator(*it)) {
            int left, right;

            right = numbers.top();
            numbers.pop();
            left = numbers.top();
            numbers.pop();

            numbers.push(solveOperation(*it, left, right));
        } else if (isdigit(*it)) {
            numbers.push(*it - '0'); // converts ascii number to int by subtracting 48
        }
        ++it;
    } while (it != expression.end());

    return numbers.top();
}

int RPN::solveOperation(char c, int left, int right) {
    switch (c) {
        case '^':
            return std::pow(left, right);
        case '*':
            return left * right;
        case '/':
            return left / right;
        case '+':
            return left + right;
        case '-':
            return left - right;
        default:
            assert(1);
    }

    return 0; // this should never be reached
}

bool RPN::isOperator(char c) {
    switch (c) {
        case '^':
        case '*':
        case '/':
        case '+':
        case '-': return true;
        default: return false;
    }
}

bool RPN::lessPrecedence(char top, char input) {
    return convert(top) < convert(input);
}

int RPN::convert(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}