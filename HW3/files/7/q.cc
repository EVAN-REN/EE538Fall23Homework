#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

std::vector<int> kClosestMemoryUsages(const std::vector<int> &memoryUsages, int k, int x){
    std::vector<int> result;
    if(memoryUsages.empty()){
        return result;
    }
    if(memoryUsages.size() < k){
        return memoryUsages;
    }
    std::vector<int> select = memoryUsages;
    for(int i = 0; i < k; i++){
        int index = 0;
        int minDiff = std::abs(select[0] - x);
        for(int j = 0; j < select.size(); j++){
            int diff = std::abs(select[j] - x);
            if(diff < minDiff || (diff == minDiff && select[j] < select[index])){
                minDiff = diff;
                index = j;
            }
        }
        result.push_back(select[index]);
        select.erase(select.begin() + index);
    }
    std::sort(result.begin(), result.end());
    return result;
}