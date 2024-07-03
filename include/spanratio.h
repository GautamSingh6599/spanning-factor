#include "point.h"
#include <vector>

#ifndef SPANNING_FACTOR_INCLUDE_SPANRATIO_H
#define SPANNING_FACTOR_INCLUDE_SPANRATIO_H

    std::vector<double> span_ratio(std::vector<std::vector<double>> &shortestdistance,
        std::vector<Point> polygon, int n);

#endif
