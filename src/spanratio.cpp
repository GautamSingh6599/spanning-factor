#include "../include/helper.h"
#include "../include/spanratio.h"
#include <vector>

std::vector<double> span_ratio(std::vector<std::vector<double>> &shortestdistance, std::vector<Point> polygon, int n){
    std::vector<double> sr(3, 0);
    for(int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
            if(i != j){
                double k = shortestdistance[i][j] /
                    euclidean_distance(polygon[i], polygon[j]);
                if (sr[0] < k) {
                    sr[0] = k; sr[1] = i; sr[2] = j;
                }
            }
        }
    }
    return sr;
}
