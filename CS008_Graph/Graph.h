//
// Created by Adam G. on 4/13/22.
//

#ifndef CS008_GRAPH_GRAPH_H
#define CS008_GRAPH_GRAPH_H

#include <cstdlib>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <map>
#include <limits>

template <class T>
class Graph {
public:
    static const std::size_t MAX = 20;
private:
    bool edges[MAX][MAX];
    std::size_t weights[MAX][MAX];
    std::map<T, std::size_t> labels;
    std::size_t many_vertices = 0;
    int minimumDistance(int distance[], bool marked[], std::size_t target);
    void depth_first(bool marked[], std::size_t vertex) const;
    void remove_edge(const T& source, const T& target);
public:

    Graph();
    std::size_t size() const; // add

    void add_vertex(const T& label); // add
    void add_edge(const T& source, const T& target); // add

    void add_edge(std::size_t source, std::size_t target, std::size_t weight); // add
    bool is_edge(std::size_t source, std::size_t target) const;
    void shortest_path(std::size_t source, std::size_t target);
    std::set<std::size_t> neighbors(std::size_t vertex) const;

    void breadth_first() const;
    void breadth_first(std::size_t vertex) const;

    void depth_first() const;
    void depth_first(std::size_t vertex) const;

    T& operator[](std::size_t vertex);
    const T& operator[](std::size_t vertex) const;

};

#include "Graph.cpp"

#endif //CS008_GRAPH_GRAPH_H
