
// Copyright 2004 Gautam Singh
#include <algorithm>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <stack>
#include <utility>
#include <vector>

struct Point {
  double x, y;
};

// Find the Euclidean Distance between two points u, v.
double euclidean_distance(Point u, Point v) {
  return std::sqrt(std::pow(u.x - v.x, 2) + std::pow(u.y - v.y, 2));
}

double perimeter(std::vector<Point> polygon, int i, int j, int k) {
  Point u = polygon[i], v = polygon[j], w = polygon[k];
  return euclidean_distance(u, v) + euclidean_distance(v, w) +
         euclidean_distance(w, u);
}

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

std::vector<double> spanning_ratio(std::vector<Point> polygon,
                      std::vector<std::vector<std::pair<int, double>>> &adj,
                      int n) {
  std::vector<double> res(3, 0);
  double span_ratio = 0;
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

  int maxi = 0;
  int maxj = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        double k = shortestDistance[i][j] / euclidean_distance(polygon[i], polygon[j]);
        if(k > span_ratio){
          span_ratio = k;
          maxi = i;
          maxj = j;
        }
      }
    }
  }

  res[0] = span_ratio;
  res[1] = maxi;
  res[2] = maxj;

  return res;
}

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
                      std::vector<std::vector<std::pair<int, double>>> &adj,
                      int n, double i, double j){
  int src = (int) i;
  int end = (int) j;
  std::cout << n << " " << src << " " << end << "\n";
  std::cout << "[ ";
  for (int i = 0; i < n; ++i) {
    std::cout << "{ " << polygon[i].x << ", " << polygon[i].y << " }, ";
  }
  std::cout << "]";
}

int main() {
  std::vector<Point> polygon = input();
  int n = polygon.size();
  auto triangulation = minimum_cost_polygon_dp(polygon, n);
  std::vector<std::vector<int>> triangles =
      triangulation_pos(triangulation, 0, n - 1);
  std::vector<std::vector<std::pair<int, double>>> adj(n);
  create_graph(polygon, adj, n, triangles);
  std::vector<double> res = spanning_ratio(polygon, adj, n);
  // output(triangles, polygon, res[0]);
  print_max_span(polygon, adj, n, res[1], res[2]);
  return 0;
}
