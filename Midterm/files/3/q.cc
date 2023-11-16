#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

int *Concatenate(int *array_1, int size_1, int *array_2, int size_2){
    int* con_arr = new int[size_1 + size_2];
    for(int i = 0; i < size_1; i++){
        con_arr[i] = array_1[i];
    }
    for(int i = 0; i < size_2; i++){
        con_arr[size_1 + i] = array_2[i];
    }
    return con_arr;
}

std::vector<int> Concatenate(std::vector<int> &vector_1,
                             std::vector<int> &vector_2){
    std::vector<int> con_vec;
    con_vec.insert(con_vec.end(), vector_1.begin(), vector_1.end());
    con_vec.insert(con_vec.end(), vector_2.begin(), vector_2.end());
    return con_vec;
}