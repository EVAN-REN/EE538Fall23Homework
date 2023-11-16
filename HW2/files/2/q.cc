#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

SizedMap::SizedMap(int capacity){
    capacity_ = capacity;
}

SizedMap::SizedMap(const SizedMap& other){
    capacity_ = other.capacity_;
    map_ = other.map_;
    keys_ = other.keys_;
}

std::string SizedMap::Get(int key) const {
    if(map_.count(key) > 0){
        return map_.at(key);        
    }
    return "INVALID_KEY";   
}

void SizedMap::Put(int key, std::string value){
    if(map_.count(key) > 0){
        map_[key] = value;
        return;
    }
    if(map_.size() == capacity_){
        map_.erase(keys_.front());
        keys_.pop();
    }
    map_.insert(std::pair(key, value));
    keys_.push(key);
}

int SizedMap::Size() const{
    return map_.size();
}

SizedMap SizedMap::operator+(const SizedMap& sm2){
    SizedMap result(*this);
    result.capacity_ += sm2.capacity_;
    std::queue<int> q = sm2.keys_;
    while(!q.empty()){
        if(result.map_.count(q.front()) > 0){
            result.map_[q.front()] = sm2.map_.at(q.front());
        }else{
            result.map_.insert(std::pair(q.front(), sm2.map_.at(q.front())));
            result.keys_.push(q.front());
        }
        q.pop();
    }
    return result;
}

void SizedMap::Reverse(){
    std::vector<int> s;
    while (!keys_.empty()){
        s.push_back(keys_.front());
        keys_.pop();
    }
    for(int i = s.size() - 1; i >= 0; i--){
        keys_.push(s[i]);
    }
}