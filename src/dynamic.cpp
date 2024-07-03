#include "../include/dynamic.h"

std::vector<std::vector<int>>
minimum_cost_polygon_dp(std::vector<Point> &polygon, int n) {
  if (n < 3) {
    return {{0}};
  }
  std::vector<std::vector<double>> memo_t(n, std::vector<double>(n, -1));
  std::vector<std::vector<int>> k_store(n, std::vector<int>(n, -1));
  for (int gap = 0; gap < n; gap++) {
    for (int i = 0, j = gap; j < n; ++i, ++j) {
      if (j < i + 2) {
        memo_t[i][j] = 0.0;
      } else {
        memo_t[i][j] = std::numeric_limits<double>::max();
        for (int k = i + 1; k < j; ++k) {
          double cost =
              memo_t[i][k] + memo_t[k][j] + perimeter(polygon, i, j, k);
          if (memo_t[i][j] > cost) {
            memo_t[i][j] = cost;
            k_store[i][j] = k;
          }
        }
      }
    }
  }

  return k_store;
}
