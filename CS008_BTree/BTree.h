//
// Created by Adam G. on 3/28/22.
//

#ifndef CS008_BTREE_BTREE_H
#define CS008_BTREE_BTREE_H

#include <ctime>

template<class T>
class BTree {
private:
    static const std::size_t MINIMUM = 2;
    static const std::size_t MAXIMUM = 2 * MINIMUM;
    std::size_t data_count = 0;
    T data[MAXIMUM + 1];
    std::size_t child_count = 0;
    BTree *subset[MAXIMUM + 2];

    bool is_leaf() const;
    bool loose_insert(const T& entry);
    bool loose_erase(const T& target);
    void remove_biggest(T& removed_entry);
    void fix_excess(std::size_t i);
    void fix_shortage(std::size_t i);

public:
    BTree();

    void create();
    void clear();
    bool insert(const T& entry);
    std::size_t erase(const T& target);
    std::size_t count(const T& target);
    bool empty() const;
    void print();
};

#include "BTree.cpp"

#endif //CS008_BTREE_BTREE_H
