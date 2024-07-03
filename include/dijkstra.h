#include "point.h"
#include <vector>

#ifndef SPANNING_FACTOR_INCLUDE_DIJKSTRA_H
#define SPANNING_FACTOR_INCLUDE_DIJKSTRA_H

    std::vector<int> dijkstra(std::vector<Point> polygon,
        std::vector<std::vector<std::pair<int, double>>> &adj,
            int src, int end, int n);
#endif
