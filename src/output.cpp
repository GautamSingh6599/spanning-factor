#include "../include/output.h"
#include <iostream>
#include <vector>

void output(std::vector<std::vector<int>> &triangles,
            std::vector<Point> &polygon, double span_ratio) {
  std::cout << span_ratio << "\n";
  std::cout << triangles.size() << "\n";
  for (const auto &i : triangles) {
    for (auto j : i) {
      std::cout << polygon[j].x << " " << polygon[j].y << " ";
    }
    std::cout << "\n";
  }
}

void print_max_span(std::vector<Point> polygon,
                      std::vector<int> shortest_path){
  int n = shortest_path.size();
  for (int i = 0; i < n; ++i) {
      std::cout << polygon[i].x << " " << polygon[i].y << " ";
  }
}
