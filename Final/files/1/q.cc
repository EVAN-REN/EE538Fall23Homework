#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

void DFS_backtrack(std::vector<int> &candidates, int target, std::vector<std::vector<int>> &result, std::vector<int> &current, int curCost){
    
    bool noAdd = true;
    // Loop to see if there are any dishes you can add
    for(int cost : candidates){
        if(cost <= target - curCost){
            current.push_back(cost);
            DFS_backtrack(candidates, target, result, current, curCost + cost);
            current.pop_back();
            noAdd = false;
        }
    }
    // Records collections where it has been determined that no dishes can be added
    if(noAdd){
        if(curCost == target && !current.empty()){
            // keep unique
            std::sort(current.begin(), current.end());
            if(std::find(result.begin(), result.end(), current) == result.end()){
               result.push_back(current);
            }   
        }       
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target){
    std::vector<std::vector<int>> result;
    if(candidates.empty()){
        return result;
    }
    std::vector<int> current;
    std::vector<std::vector<int>> record;
    DFS_backtrack(candidates, target, result, current, 0);
    return result;
}