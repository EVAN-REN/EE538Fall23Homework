#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

DoubleStack::DoubleStack(){}

void DoubleStack::push(int num){
    if(num % 2 == 1){
        oddVec_.push_back(num);
    }else{
        evenVec_.push_back(num);
    }
}

 void DoubleStack::pop(){
    if(!oddVec_.empty() && evenVec_.empty()){
        oddVec_.pop_back();
    }else if(oddVec_.empty() && !evenVec_.empty()){
        evenVec_.pop_back();
    }else if(!oddVec_.empty() && !evenVec_.empty()){
        if(oddVec_.back() < evenVec_.back()){
            evenVec_.pop_back();
        }else{
            oddVec_.pop_back();
        }
    }
 }

 int DoubleStack::top(){
    if(!oddVec_.empty() && evenVec_.empty()){
        return oddVec_.back();
    }else if(oddVec_.empty() && !evenVec_.empty()){
        return evenVec_.back();
    }else if(!oddVec_.empty() && !evenVec_.empty()){
        if(oddVec_.back() < evenVec_.back()){
            return evenVec_.back();
        }else{
            return oddVec_.back();
        }
    }else{
        return -1;
    }
 }

 int DoubleStack::size(){
    return oddVec_.size() + evenVec_.size();
 }

 bool DoubleStack::empty(){
    if(oddVec_.empty() && evenVec_.empty()){
        return true;
    }else{
        return false;
    }
 }