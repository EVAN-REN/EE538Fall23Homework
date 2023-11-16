#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
bool CheckValidExpression(const std::string& input){
    std::stack<char> sta;
    for(int i =0; i < input.size(); i++){
        switch (input.at(i))
        {
        case '(':
            sta.push('(');
            break;
        case '[':
            sta.push('[');
            break;
        case '{':
            sta.push('{');
            break;
        case ')':
            if(sta.empty() || sta.top() != '('){
                return false;
            }else{
                sta.pop();
            }
            break;
        case ']':
            if(sta.empty() || sta.top() != '['){
                return false;
            }else{
                sta.pop();
            }
            break;
        case '}':
            if(sta.empty() || sta.top() != '{'){
                return false;
            }else{
                sta.pop();
            }
            break;
        default:
            break;
        }
    }
    return sta.empty();
}