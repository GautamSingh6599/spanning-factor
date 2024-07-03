#include "../include/point.h"
#include "../include/helper.h"
#include "../include/dynamic.h"
#include "../include/triangulation.h"
#include "../include/input.h"
#include "../include/dijkstra.h"
#include "../include/floydwarshall.h"
#include "../include/graph.h"
#include "../include/output.h"
#include "../include/spanratio.h"
#include <vector>

int main() {
  std::vector<Point> polygon = input();
  int n = polygon.size();
  auto triangulation = minimum_cost_polygon_dp(polygon, n);
  std::vector<std::vector<int>> triangles =
      triangulation_pos(triangulation, 0, n - 1);
  std::vector<std::vector<std::pair<int, double>>> adj(n);
  create_graph(polygon, adj, n, triangles);
  std::vector<std::vector<double>> shortest = floyd_warshall(polygon, adj, n);
  std::vector<double> span = span_ratio(shortest, polygon, n);
  output(triangles, polygon, span[0]);
  return 0;
}
