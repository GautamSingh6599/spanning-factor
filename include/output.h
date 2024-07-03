#include "point.h"
#include <vector>

#ifndef SPANNING_FACTOR_INCLUDE_OUTPUT_H
#define SPANNING_FACTOR_INCLUDE_OUTPUT_H

    void output(std::vector<std::vector<int>> &triangles,
                std::vector<Point> &polygon, double span_ratio);
    void print_max_span(std::vector<Point> polygon,
                          std::vector<std::vector<std::pair<int, double>>> &adj,
                          int n, double i, double j);

#endif