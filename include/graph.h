#include "point.h"
#include <vector>

#ifndef SPANNING_FACTOR_INCLUDE_GRAPH_H
#define SPANNING_FACTOR_INCLUDE_GRAPH_H

    void addEdge(std::vector<std::vector<std::pair<int, double>>> &adj, int i,
                 int j, double weight);
    void create_graph(std::vector<Point> &polygon,
                      std::vector<std::vector<std::pair<int, double>>> &adj, int n,
                      std::vector<std::vector<int>> triangles);

#endif
