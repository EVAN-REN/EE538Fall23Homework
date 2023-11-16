#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
void UniqueVectorNotBySet(std::vector<int> &input){
    std::vector<int> tempVec;
    for(int i = 0; i < input.size(); i++){
        bool find = false;
        for(int j = 0; j < tempVec.size(); j++){
            if(tempVec[j] == input[i]){
                find = true;
                break;
            }
        }
        if(!find){
            tempVec.push_back(input[i]);
        }    
    }
    input = tempVec;
}

void UniqueVectorBySet(std::vector<int> &input){
    std::set<int> tempSet(input.begin(), input.end());
    input.assign(tempSet.begin(), tempSet.end());
}

std::vector<int> IntersectVectors(const std::vector<int> &input1, const std::vector<int> &input2){
    std::vector<int> result;
    std::set<int> set_input1(input1.begin(), input1.end());
    std::set<int> set_input2(input2.begin(), input2.end());
    for(int element1 : set_input1){
        bool find = false;
        for(int element2 : set_input2){
            if(element1 == element2){
                find = true;
                break;
            }
        }
        if(find){
            result.push_back(element1);
        }   
    }
    return result;
}

std::set<int> DiffVectors(const std::vector<int> &input1, const std::vector<int> &input2){
    std::set<int> result;
    std::set<int> set_input1(input1.begin(), input1.end());
    std::vector<int> intersectvec = IntersectVectors(input1, input2);
    for(int element1 : set_input1){
        bool find = false;
        for(int element2 : intersectvec){
            if(element1 == element2){
                find = true;
                break;
            }
        }
        if(!find){
            result.insert(element1);
        }   
    }
    return result;
}