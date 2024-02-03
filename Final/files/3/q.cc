#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

int findMinimumEnergyPath(std::vector<std::vector<int>> &grid){
    if(grid.empty()){
        return 0;
    }
    int x = grid.size();
    int y = grid[0].size();
    // use dynamic programming
    std::vector<std::vector<int>> pathCost(x, std::vector<int>(y));
    // record each point's minimum cost
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(i == 0 && j == 0){
                pathCost[i][j] = grid[i][j];
            }else if(i == 0){
                pathCost[i][j] = pathCost[i][j - 1] + grid[i][j];
            }else if(j == 0){
                pathCost[i][j] = pathCost[i - 1][j] + grid[i][j];
            }else{
                pathCost[i][j] = std::min(pathCost[i][j - 1], pathCost[i - 1][j]) + grid[i][j];
            }
        }
    }
    return pathCost[x - 1][y - 1];
}