#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

std::vector<int> Reverse(std::vector<int> input) {
    int size = input.size();
    for(int i = 0; i < (size / 2); i++){
        int temp = input.at(i);
        input[i] = input[size - i -1];
        input[size - i - 1] = temp;
    }
    return input;
}

std::vector<int> PlusOne(std::vector<int> input){
    int rear = input.size() - 1;
    bool carry = true;
    std::vector<int>::iterator it = input.begin();
    for(; rear >= 0; rear--){
        if(input[rear] < 0 || input[rear] > 9){
            return std::vector<int>{-1};
        }
        if(carry){
            if(input[rear] == 9){
                input[rear] = 0;
                if(rear == 0){
                    input.insert(it, 1);
                }
            }else{
                input[rear]++;
                carry = false;
            }
        }
    }
    return input;
}
