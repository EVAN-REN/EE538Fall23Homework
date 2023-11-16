#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

MyVector::MyVector() : size_(0){
    error_ = ErrorCode::kNoError;
}

MyVector::MyVector(int size) : size_(size){
    error_ = ErrorCode::kNoError;
}

MyVector::MyVector(const MyVector& rhs) : size_(rhs.size_), data_(rhs.data_), error_(rhs.error_){
}

MyVector::~MyVector(){
    //delete the memory of vector
    if(size_ != 0){
        delete[] data_;
        size_ = 0;
    }
    data_ = nullptr;
}

void MyVector::push_back(int value){
    //Create a new dynamic array
    int* new_data = new int[size_ + 1];
    //Copy from the old array
    for(int i = 0; i < size_; i++){
        new_data[i] = data_[i];
    }
    // insert value
    new_data[size_] = value;
    //DELETE the array.
    if(size_ != 0){
        delete[] data_;
    }
    // return the pointer inside the new dynamic array.
    data_ = new_data;
    size_++;
    error_ = ErrorCode::kNoError;
}

int MyVector::pop_back(){
    //if PopFromEmptyVector
    if(size_ == 0){
        error_ = ErrorCode::kPopFromEmptyVector;
        return 0;
    }else{
        error_ = ErrorCode::kNoError;
    }
    //Create a new dynamic array
    int* new_data = new int[size_ - 1];
    //Copy from the old array
    for(int i = 0; i < size_ - 1; i++){
        new_data[i] = data_[i];
    }
    // record value
    int data = data_[size_ - 1];
    //DELETE the array.
    delete[] data_;
    // return the pointer inside the new dynamic array.
    data_ = new_data;
    size_--;
    return data;
}

void MyVector::push_front(int value){   
    //Create a new dynamic array
    int* new_data = new int[size_ + 1];
    // insert value
    new_data[0] = value;
    //Copy from the old array
    for(int i = 1; i <= size_; i++){
        new_data[i] = data_[i - 1];
    }
    //DELETE the array.
    if(size_ != 0){
        delete[] data_;
    }
    // return the pointer inside the new dynamic array.
    data_ = new_data;
    size_++;
    error_ = ErrorCode::kNoError;
}

int MyVector::pop_front(){
    //if PopFromEmptyVector
    if(size_ == 0){
        error_ = ErrorCode::kPopFromEmptyVector;
        return 0;
    }else{
        error_ = ErrorCode::kNoError;
    }
    //Create a new dynamic array
    int* new_data = new int[size_ - 1];
    //Copy from the old array
    for(int i = 0; i < size_ - 1; i++){
        new_data[i] = data_[i + 1];
    }
    // record value
    int data = data_[0];
    //DELETE the array.
    delete[] data_;
    // return the pointer inside the new dynamic array.
    data_ = new_data;
    size_--;
    return data;
}

void MyVector::insert(int value, int index){
    //if IndexError
    if(index >= size_){
        error_ = ErrorCode::kIndexError;
        return;
    }else{
        error_ = ErrorCode::kNoError;
    }
    //Create a new dynamic array
    int* new_data = new int[size_ + 1];
    int i = 0;
    //Copy from the old array until index
    for(; i <= index; i++){
        new_data[i] = data_[i];
    }
    // insert value
    new_data[i] = value;
    i++;
    //Copy the rest from the old array.
    for(; i <= size_; i++){
        new_data[i] = data_[i - 1];
    }
    //DELETE the array.
    if(size_ != 0){
        delete[] data_;
    }
    // return the pointer inside the new dynamic array.
    data_ = new_data;
    size_++;
}

int MyVector::at(int index){
    //if IndexError
    if(index >= size_){
        error_ = ErrorCode::kIndexError;
        return -1;
    }else{
        error_ = ErrorCode::kNoError;
    }
    return data_[index];
}

int MyVector::find(int item){
    int index = -1;
    //find the item
    for(int i = 0; i < size_; i++){
        if(data_[i] == item){
            index = i;
            break;
        }
    }
    //if found
    if(index == -1){
        error_ = ErrorCode::kNotFound;
    }else{
        error_ = ErrorCode::kNoError;
    }
    return index;
}

ErrorCode MyVector::get_error() const{
    return error_;
}

int MyVector::size() const{
    return size_;
}

std::vector<int> MyVector::ConvertToStdVector(){
    std::vector<int> result;
    for(int i = 0; i < size_; i++){
        result.push_back(data_[i]);
    }
    error_ = ErrorCode::kNoError;
    return result;
}