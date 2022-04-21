//
// Created by Adam G. on 4/13/22.
//

#ifndef CS008_GRAPH_GRAPH_CPP
#define CS008_GRAPH_GRAPH_CPP

#include "Graph.h"

template<class T>
Graph<T>::Graph() {
    for (auto & i : edges) {
        for (bool & edge : i) {
            edge = false;
        }
    }
}

template<class T>
void Graph<T>::remove_edge(const T &source, const T &target) {
    edges[source][target] = false;
}

template<class T>
std::size_t Graph<T>::size() const {
    return many_vertices;
}

template<class T>
void Graph<T>::add_vertex(const T &label) {
    labels[label] = many_vertices++;
}

template<class T>
void Graph<T>::add_edge(const T &source, const T &target) {
    edges[source][target] = true;
}

template<class T>
void Graph<T>::add_edge(std::size_t source, std::size_t target, std::size_t weight) {
    add_edge(source, target);
    weights[source][target] = weight;
}

template<class T>
std::set<std::size_t> Graph<T>::neighbors(std::size_t vertex) const {
    std::set<std::size_t> setNeighbors;
    for (std::size_t i = 0; i < many_vertices; i++) {
        if (edges[vertex][i]) {
            setNeighbors.insert(i);
        }
    }
    // create set
    // for i = 0 in many_vertices
    //  if(edges[vertex][i]
        //  set.insert(i)
    return setNeighbors;
}

template<class T>
bool Graph<T>::is_edge(std::size_t source, std::size_t target) const {
    return edges[source][target];
}

template<class T>
int Graph<T>::minimumDistance(int distance[], bool marked[], std::size_t target) {
    int minimum = std::numeric_limits<int>::max();
    int index;

    for (int i = 0; i < target; i++) {
        if (!marked[i] && distance[i] <= minimum) {
            minimum = distance[i];
            index = i;
        }
    }

    return index;

}

/*
function dijkstra(G, S)
    for each vertex V in G
        dist[V] <- infinite
        prev[V] <- NULL
        If V != S, add V to Priority Queue Q
    dist[S] <- 0

    while Q IS NOT EMPTY
        U <- Extract MIN from Q
        for each unvisited neighbour V of U
            temperoryDist <- dist[U] + edgeWeight(U, V)
            if temperoryDist < dist[V]
                dist[V] <- temperoryDist
                prev[V] <- U
    return dist[], prev[]
 */

template<class T>
void Graph<T>::shortest_path(std::size_t source, std::size_t target) {
    // inf = std::numeric_limits<int>::max()
    int distance[many_vertices];
    int marked[many_vertices];
    std::queue<std::size_t> q;

    q.push(source);

    while (!q.empty()) {

    }

    for (int i = 0; i < target; i++) {
        distance[i] = std::numeric_limits<int>::max();
        marked[i] = false;
    }

    distance[source] = 0;
    distance[source] = true;


//    while (!q.empty()) {
//
//    }
//
//    for (allowedSize = 1; allowedSize < target; ++allowedSize) {
//
//    }

//    int distance[target];
////    int pred[MAX];
//    bool marked[MAX];
////    int count = 1;
//
//
//
//    for (int i = 0; i < target; i++) {
//        distance[i] = std::numeric_limits<int>::max();
//        marked[i] = false;
//    }
//
//    distance[source] = 0;
//
//    for (std::size_t i = 0; i < many_vertices; i++) {
//        int minDistance = minimumDistance(distance, marked, target);
//    }
}

template<class T>
void Graph<T>::breadth_first() const {
    breadth_first(0);
}

template<class T>
void Graph<T>::breadth_first(std::size_t vertex) const {
    bool marked[many_vertices];

    for (int i = 0; i < many_vertices; i++) {
        marked[i] = false;
    }

    std::queue<std::size_t> q;
    q.push(vertex);
    // create a bool marked[verticesSize]
    // marked[vertex] = true
    // create queue and add vertex to it

    while (!q.empty()) {
        for (auto i : neighbors(q.front())) {
            if (!marked[i]) {
                q.push(i);
            }
        }
        marked[q.front()] = true;
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
    // while queue is not empty
    //  add all of queue's top unvisited neighbors to the queue
    //  mark front of queue as visited
    //  pop the queue
}

template<class T>
void Graph<T>::depth_first() const {
    depth_first(0);
}

template<class T>
void Graph<T>::depth_first(std::size_t vertex) const {
    bool marked[many_vertices];
    std::fill(marked, marked+many_vertices,false);

    depth_first(marked, vertex);
    std::cout << std::endl;
}

template<class T>
void Graph<T>::depth_first(bool *marked, std::size_t vertex) const {
    marked[vertex] = true;

    std::cout << vertex << " ";

    for (auto i : neighbors(vertex)) {
        if (!marked[i]) {
            depth_first(marked, i);
        }
    }
}

template<class T>
T &Graph<T>::operator[](std::size_t vertex) {
    assert(vertex < size());
    return labels[vertex];
}

template<class T>
const T &Graph<T>::operator[](std::size_t vertex) const {
    assert(vertex < size());
    return labels[vertex];
}

#endif //CS008_GRAPH_GRAPH_CPP