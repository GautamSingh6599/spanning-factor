#include "../include/helper.h"
#include <cmath>

double euclidean_distance(Point u, Point v){
    return std::sqrt(std::pow(u.x - v.x, 2) + std::pow(u.y - v.y, 2));
}

double perimeter(std::vector<Point> polygon, int i, int j, int k) {
  Point u = polygon[i], v = polygon[j], w = polygon[k];
  return euclidean_distance(u, v) + euclidean_distance(v, w) +
         euclidean_distance(w, u);
}
