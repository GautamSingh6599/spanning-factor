#include "../include/helper.h"
#include "../include/graph.h"
#include <algorithm>

void addEdge(std::vector<std::vector<std::pair<int, double>>> &adj, int i,
             int j, double weight) {
  adj[i].push_back({j, weight});
  adj[j].push_back({i, weight});
}

void create_graph(std::vector<Point> &polygon,
                  std::vector<std::vector<std::pair<int, double>>> &adj, int n,
                  std::vector<std::vector<int>> triangles) {
  for (int i = 0; i < n - 1; i++) {
    addEdge(adj, i, i + 1, euclidean_distance(polygon[i], polygon[i + 1]));
  }
  for (auto &i : triangles) {
    std::sort(i.begin(), i.end());
    addEdge(adj, i[0], i[2], euclidean_distance(polygon[i[0]], polygon[i[2]]));
  }
}
