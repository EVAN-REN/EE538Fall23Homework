#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc


int FindNumberOfUniquePaths(const std::vector<std::vector<int>> &grid,
                            const std::pair<int, int> start,
                            const std::pair<int, int> end){
    if(grid.size() == 0){
        return 0;
    }
    int paths = 0;
    if(start.first == end.first && start.second == end.second){
        return 1;
    }

    if(start.first < end.first && grid[start.first + 1][start.second] != 0){
        std::pair<int, int> nstart(start.first + 1, start.second);
        paths += FindNumberOfUniquePaths(grid, nstart, end);
    }

    if(start.second < end.second && grid[start.first][start.second + 1] != 0){
        std::pair<int, int> nstart(start.first, start.second + 1);
        paths += FindNumberOfUniquePaths(grid, nstart, end);
    }

    return paths;

}