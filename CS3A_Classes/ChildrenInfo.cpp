//
// Created by Quantum on 9/30/2021.
//

#include "ChildrenInfo.h"

Child ChildrenInfo::getChild(int num) {
    return children[num];
}

void ChildrenInfo::addChild(Child child) {
    children.push_back(child);
}