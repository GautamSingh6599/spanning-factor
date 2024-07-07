#include "../include/output.h"
#include "../include/helper.h"
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

void output(std::vector<std::vector<int>> &triangles,
            std::vector<Point> &polygon, double span_ratio) {
  std::cout << span_ratio << "\n";
  for (const auto &i : triangles) {
    for (auto j : i) {
      std::cout << polygon[j].x << " " << polygon[j].y << " ";
    }
    std::cout << "\n";
  }
}

void print_path(std::vector<int> tree, int end,
    std::vector<Point> polygon){
    if(end == -1){
        return;
    }
    print_path(tree, tree[end], polygon);
    std::cout << polygon[end].x << " " << polygon[end].y << " ";
}

void print_max_span(std::vector<Point> polygon, std::vector<std::vector<std::pair<int, double>>> &adj,
    int n, int src, int end){
    std::vector<std::vector<double>> adjM(n, std::vector<double>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (const auto &j : adj[i]) {
            adjM[i][j.first] = j.second;
        }
    }

    std::vector<double> sD(n, std::numeric_limits<double>::max());
    std::vector<bool> included(n, false);
    std::vector<int> parent(n);
    sD[src] = 0;
    parent[src] = -1;

    for (int i = 1; i < n; i++) {
        int nV = -1;
        double shortD = std::numeric_limits<double>::max();
        for (int j = 0; j < n; j++) {
            if(!included[j] && sD[j] < shortD){
                nV = j;
                shortD = sD[j];
            }
        }

        included[nV] = true;

        for (int j  = 0; j < n; j++) {
            double eD = adjM[nV][j];
            if(eD > 0 && ((shortD + eD) < sD[j])){
                parent[j] = nV;
                sD[j] = shortD + eD;
            }
        }
    }

    print_path(parent, end, polygon);

}
