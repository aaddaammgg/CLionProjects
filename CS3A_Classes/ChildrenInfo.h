//
// Created by Quantum on 9/30/2021.
//

#ifndef CS3A_CLASSES_CHILDRENINFO_H
#define CS3A_CLASSES_CHILDRENINFO_H

#include <vector>
#include "Child.h"

class ChildrenInfo {
private:
    std::vector<Child> children;
public:
    Child getChild(int num);
    void addChild(Child child);
};

#endif //CS3A_CLASSES_CHILDRENINFO_H
