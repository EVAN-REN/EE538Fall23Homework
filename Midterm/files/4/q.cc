#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

int findInsertionIndex(const std::vector<int>& sortedVector, int n){
    if(sortedVector.empty()){
        return 0;
    }
    int left = 0, right = sortedVector.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(n < sortedVector[mid]){
            right = mid - 1;
        }else if (n > sortedVector[mid])
        {
            left = mid + 1;
        }else{
            return mid;
        }      
    }
    return left;
}

MySet::MySet(std::vector<int>& elements){
    std::sort(elements.begin(), elements.end());
    for(int i = 0; i < elements.size(); i++){
        if(elements_.empty() || elements[i] != elements_.back()){
            elements_.push_back(elements[i]);
        }
    }
}

MySet::MySet(const MySet& rhs) : elements_(rhs.elements_){}

void MySet::insert(int value){
    if(elements_.empty()){
        elements_.push_back(value);
        return;
    }
    int insert_index = findInsertionIndex(elements_, value);
    if(insert_index == elements_.size()){
        elements_.push_back(value);
        return;
    }
    if(elements_[insert_index] == value){
        return;
    }
    elements_.insert(elements_.begin() + insert_index, value);
}

bool MySet::is_in(int item){
    if(elements_.empty()){
        return false;
    }
    int insert_index = findInsertionIndex(elements_, item);
    if(insert_index < elements_.size() && elements_[insert_index] == item){
        return true;
    }else{
        return false;
    }
}

int MySet::size() const{
    return elements_.size();
}

std::vector<int> MySet::ConvertToStdVector(){
    std::vector<int> result = elements_;
    return result;
}