#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc


int calculate(std::vector<int> v, int n){
    int mul = 1;
    int s = v.size() - 1;
    for(int i = 0; i < n; i++){
        mul *= v[s - i];
    }
    return mul;
}

std::vector<int> ProductOfKHighestNumbers(const std::vector<int> &input, int k){
    std::vector<int> result;
    if(k > input.size()){
        return result;
    }

    std::vector<int> current(input.begin(), input.begin() + k);
    std::sort(current.begin(), current.end());
    result.push_back(calculate(current, k));
    for(int i = k; i < input.size(); i++){
        current.push_back(input[i]);
        std::sort(current.begin(), current.end());
        result.push_back(calculate(current, k));
    }
    return result;
}

