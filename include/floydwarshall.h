#include "point.h"
#include <vector>

#ifndef SPANNING_FACTOR_INCLUDE_FLOYDWARSHALL_H
#define SPANNING_FACTOR_INCLUDE_FLOYDWARSHALL_H

std::vector<std::vector<double>> floyd_warshall(std::vector<Point> polygon,
                      std::vector<std::vector<std::pair<int, double>>> &adj,
                      int n);

#endif
