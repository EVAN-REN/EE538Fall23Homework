#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

Queue::Queue(const Queue& rhs){
    v_ = rhs.v_;
}

Queue& Queue::operator=(const Queue& rhs){
    v_ = rhs.v_;
    return *this;
}

Queue Queue::operator+(const Queue& rhs){
    Queue q;
    q.v_.insert(q.v_.end(), rhs.v_.begin(), rhs.v_.end());
    q.v_.insert(q.v_.end(), v_.begin(), v_.end());
    return q;
}

bool Queue::Enqueue(int value){
    v_.push_back(value);
    return true;
}

bool Queue::Dequeue(){
    if(v_.empty()){
        return false;
    }
    v_.erase(v_.begin());
    return true;
}

bool Queue::IsEmpty(){
    return v_.empty();
}

int Queue::Front(){
    if(v_.empty()){
        return -1;
    }
    return v_.front();
}



