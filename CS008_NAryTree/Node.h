//
// Created by Adam G. on 4/11/22.
//

#ifndef CS008_NARYTREE_NODE_H
#define CS008_NARYTREE_NODE_H

#include <string>
#include <vector>

struct Node {
    std::string data;
    std::vector<Node*> children;
};

#endif //CS008_NARYTREE_NODE_H
