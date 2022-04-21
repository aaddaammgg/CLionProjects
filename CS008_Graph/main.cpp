#include <iostream>
#include "Graph.h"

int main() {
    Graph<int> g;

    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);
    g.add_vertex(5);
    g.add_vertex(6);
    g.add_vertex(7);
    g.add_vertex(8);

    g.add_edge(0,1, 1);
    g.add_edge(0,6, 1);
    g.add_edge(1, 2, 3);
    g.add_edge(1, 8, 2);
    g.add_edge(2, 8, 1);
    g.add_edge(3, 2, 1);
    g.add_edge(4, 3, 5);
    g.add_edge(5, 4, 2);
    g.add_edge(5, 6, 1);
    g.add_edge(6, 7, 2);
    g.add_edge(7, 4, 1);
    g.add_edge(8, 0, 0);
    g.add_edge(8, 3, 1);
    g.add_edge(8, 7, 4);

    g.breadth_first();
    g.depth_first();
    return 0;
}
