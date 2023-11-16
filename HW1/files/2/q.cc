#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

bool IsPrime(int number){
    if(number <= 1){
        return false;
    }
    if(number <= 3){
        return true;
    }
    if(number % 2 == 0 || number % 3 == 0){
        return false;
    }
    for(int i = 5; i * i <= number; i+=6){
        if(number % i == 0 || number % (i + 2) == 0){
            return false;
        }
    }
    return true;
}
