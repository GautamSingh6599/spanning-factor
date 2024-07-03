#include "../include/input.h"
#include <vector>
#include <iostream>

std::vector<Point> input() {
 std::vector<Point> polygon;
 int n;
 std::cin >> n;
 for (int i = 0; i < n; i++) {
   double x, y;
   std::cin >> x >> y;
   polygon.push_back({x, y});
 }
 return polygon;
}
