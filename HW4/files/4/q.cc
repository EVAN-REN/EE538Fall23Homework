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


StudentMaxHeap::StudentMaxHeap(std::vector<Student>& input){
    for(int i = 0; i < input.size(); i++){
        push(input[i]);
    }
}

Student StudentMaxHeap::GetParent(int i){
    if(i <= 0 || i >= data_.size()){
        return Student();
    }
    return data_[(i + 1) / 2];
}

Student StudentMaxHeap::GetLeft(int i){
    if(i < 0 || i >= data_.size()){
        return Student();
    }
    int il = 2 * i + 1;
    if(il >= data_.size()){
        return Student();
    }
    return data_[il];
}

Student StudentMaxHeap::GetRight(int i){
    if(i < 0 || i >= data_.size()){
        return Student();
    }
    int il = 2 * i + 2;
    if(il >= data_.size()){
        return Student();
    }
    return data_[il];
}

int StudentMaxHeap::GetParentIndex(int i){
    if(i <= 0 || i >= data_.size()){
        return INT_MAX;
    }
    return (i - 1) / 2;
}

int StudentMaxHeap::GetLeftIndex(int i){
    if(i < 0 || i >= data_.size()){
        return INT_MAX;
    }
    int il = 2 * i + 1;
    if(il >= data_.size()){
        return INT_MAX;
    }
    return il;
}

int StudentMaxHeap::GetRightIndex(int i){
    if(i < 0 || i >= data_.size()){
        return INT_MAX;
    }
    int il = 2 * i + 2;
    if(il >= data_.size()){
        return INT_MAX;
    }
    return il;
}

int StudentMaxHeap::GetLargestChildIndex(int i){
    if(i < 0 || i >= data_.size()){
        return INT_MAX;
    }
    int il = GetLeftIndex(i);
    int ir = GetRightIndex(i);
    if(il == INT_MAX){
        return INT_MAX;
    }else if(il != INT_MAX && ir == INT_MAX){
        return il;
    }else{
        if(data_[ir] > data_[il]){
            return ir;
        }else{
            return il;
        }
    }
}

Student StudentMaxHeap::top(){
    if(data_.empty()){
        return Student();
    }
    return data_[0];
}

void StudentMaxHeap::push(const Student& student){
    int index = data_.size();
    data_.push_back(student);
    TrickleUp(index);
}

bool StudentMaxHeap::pop(){
    if(data_.empty()){
        return false;
    }
    data_[0] = data_[data_.size() - 1];
    data_.pop_back();
    TrickleDown(0);
    return true;
}

void StudentMaxHeap::TrickleUp(int i){
    while(i != 0){
        int parent = GetParentIndex(i);
        if(data_[parent] < data_[i]){
            Student tmp = data_[parent];
            data_[parent] = data_[i];
            data_[i] = tmp;
        }
        i = parent;
    }
}

void StudentMaxHeap::TrickleDown(int i){
    int index = i;
    int maxc = GetLargestChildIndex(index);
    while(maxc != INT_MAX){
        if(data_[index] < data_[maxc]){
            Student tmp = data_[index];
            data_[index] = data_[maxc];
            data_[maxc] = tmp;
        }else{
            return;
        }
        index = maxc;
        maxc = GetLargestChildIndex(index);
    }
}

void StudentMaxHeap::ConvertToHeap(const std::vector<Student>& input){
    int size = input.size();
    if(size == 0){
        return;
    }
    data_ = input;
    for(int i = size / 2 - 1; i >= 0; i--){
        TrickleDown(i);
    }
}

void HeapSort(std::vector<Student>& input){
    if(input.empty()){
        return;
    }
    StudentMaxHeap smh(input);
    for(Student i : smh.GetData()){
        std::cout << i.grade << std::endl;
    }
    std::stack<Student> s;
    while(!smh.empty()){
        s.push(smh.top());
        smh.pop();
    }
    input.clear();
    while(!s.empty()){
        input.push_back(s.top());
        s.pop();
    }
}


