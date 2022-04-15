#include <iostream>
#include "Graph.h"

int main() {
    Graph<int> g;
    g.add_vertex(0);
    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);
    g.add_vertex(4);

    g.add_edge(0,1);
    g.add_edge(0,4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(4, 2);
    g.add_edge(2, 3);

    g.breadth_first();
    g.depth_first();
    return 0;
}
