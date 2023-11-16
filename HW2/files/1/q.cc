#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
std::map<char, int> CountCharacters(std::string &input){
    std::map<char, int> result;
    std::map<char, int>::iterator it;
    for(int i = 0; i < input.size(); i ++){
        it = result.find(input.at(i));
        if(it != result.end()){
            it->second++;
        }else{
            result.insert(std::pair<char, int>(input.at(i), 1));
        }
    }
    return result;
}