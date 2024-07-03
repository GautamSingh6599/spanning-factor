#include "../include/helper.h"
#include "../include/floydwarshall.h"
#include <limits>
#include <vector>

std::vector<std::vector<double>> floyd_warshall(std::vector<Point> polygon,
                      std::vector<std::vector<std::pair<int, double>>> &adj,
                      int n) {
  std::vector<std::vector<double>> shortestDistance(
      n, std::vector<double>(n, std::numeric_limits<double>::max()));
  for (int i = 0; i < n; i++) {
    for (const auto &j : adj[i]) {
      shortestDistance[i][j.first] = j.second;
    }
  }

  for (int i = 0; i < n; i++) {
    shortestDistance[i][i] = 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        shortestDistance[j][k] =
            std::min(shortestDistance[j][k],
                     shortestDistance[j][i] + shortestDistance[i][k]);
      }
    }
  }

  return shortestDistance;
}
