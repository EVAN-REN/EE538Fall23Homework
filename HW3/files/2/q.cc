#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <stack>

// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

bool CPPLib::CheckValidExpression(const std::string& input){
    std::stack<char> s;
    bool ifValid = true;
    for(int i = 0; i < input.size(); i++){
        char n = input[i];
        if(n == '('){
            s.push(')');
        }else if(n == '['){
            s.push(']');
        }else if(n == '{'){
            s.push('}');
        }else if(n == ')'){
            if(s.empty() || s.top() != ')'){
                ifValid = false;
                break;
            }else{
                s.pop();
            }
        }else if(n == ']'){
            if(s.empty() || s.top() != ']'){
                ifValid = false;
                break;
            }else{
                s.pop();
            }
        }else if(n == '}'){
            if(s.empty() || s.top() != '}'){
                ifValid = false;
                break;
            }else{
                s.pop();
            }
        }
    }
    if(!s.empty()){
        ifValid = false;
    }
    return ifValid;
}

bool CPPLib::IsPalindrome(const std::string& input){
    int front = 0, back = input.size() - 1;
    int isPalindrome = true;
    while(front < back){
        if(input[front] != input[back]){
            isPalindrome = false;
            break;
        }
        front++;
        back--;
    }
    return isPalindrome;
}

int CPPLib::OddChar(const std::string& input){
    char result = 0;
    for(char c : input){
        result ^= c;
    }
    return result;
}