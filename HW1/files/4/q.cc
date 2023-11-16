#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

std::vector<int> Flatten3DVector(
    std::vector<std::vector<std::vector<int>>> input){
        std::vector<int> result;
        for(auto &layer1 : input ){
            for(auto &layer2 : layer1){
                for(auto &layer3 : layer2){
                    result.push_back(layer3);
                }
            }
        }
        return result;
    }