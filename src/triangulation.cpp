#include "../include/triangulation.h"
#include <stack>
#include <cstdlib>

std::vector<std::vector<int>>
triangulation_pos(const std::vector<std::vector<int>> &k_store, int i, int j) {
  std::vector<std::vector<int>> triangle;
  std::stack<std::pair<int, int>> s;
  s.push({i, j});
  while (!s.empty()) {
    auto [i, j] = s.top();
    s.pop();
    if (std::abs(i - j) > 1) {
      int k = k_store[i][j];
      triangle.push_back({i, k, j});
      s.push({k, j});
      s.push({i, k});
    }
  }
  return triangle;
}
