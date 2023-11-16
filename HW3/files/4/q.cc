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

SinglyLinkedList::SinglyLinkedList(const std::vector<int> &v){
    size_ = 0;
    if(v.empty()){
        head_ = nullptr;
        return;
    }
    ListNode *ln;
    ln = new ListNode(v[0]);
    head_ = ln;
    for(int i = 1; i < v.size(); i++){
        ln->next = new ListNode(v[i]);
        ln = ln->next;
    }
    size_ += v.size();
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList &rhs){
    size_ = rhs.size_;

    if(size_ == 0){
        head_ = nullptr;
        return;
    }
    ListNode *ln, *rln;
    rln = rhs.head_;
    ln = new ListNode(rln->val);
    head_ = ln;
    rln = rln->next;
    while(rln != nullptr){
        ln->next = new ListNode(rln->val);
        ln = ln->next;
        rln = rln->next;
    }
}

SinglyLinkedList::~SinglyLinkedList(){
    ListNode *nextLN, *currentLN;
    currentLN = head_;
    while(currentLN != nullptr){
        nextLN = currentLN->next;
        delete(currentLN);
        currentLN = nextLN;
    }
}

bool SinglyLinkedList::empty(){
    if(size_ == 0){
        return true;
    }
    return false;
}

int SinglyLinkedList::size(){
    return size_;
}

ListNode* SinglyLinkedList::head(){
    return head_;
}

void SinglyLinkedList::push_back(int i){
    if(size_ == 0){
        head_ = new ListNode(i);
        size_++;
        return;
    }
    ListNode *ln;
    ln = head_;
    while(ln != nullptr){
        if(ln->next == nullptr){
            ln->next = new ListNode(i);
            size_++;
            return;
        }
        ln = ln->next;
    }
}

bool SinglyLinkedList::pop_back(){
    if(size_ == 0){
        return false;
    }else if(size_ == 1){
        delete(head_);
        head_ = nullptr;
        size_--;
        return true;
    }
    ListNode *ln;
    ln = head_;
    while(ln != nullptr){
        if(ln->next->next == nullptr){
            ListNode *nln = ln->next;
            delete(nln);
            ln->next = nullptr;
            size_--;
            return true;
        }
        ln = ln->next;
    }
    return false;
}

int SinglyLinkedList::back(){
    if(size_ == 0){
        return minusOne_;
    }
    ListNode *ln;
    ln = head_;
    while(ln != nullptr){
        if(ln->next == nullptr){
            return ln->val;
        }
        ln = ln->next;
    }
    return minusOne_;
}

ListNode* SinglyLinkedList::GetBackPointer(){
    if(size_ == 0){
        return head_;
    }
    ListNode *ln;
    ln = head_;
    while(ln != nullptr){
        if(ln->next == nullptr){
            return ln;
        }
        ln = ln->next;
    }
    return nullptr;
}

ListNode* SinglyLinkedList::GetIthPointer(int i){
    if(i < 0 ){
        return nullptr;
    }
    ListNode *ln;
    ln = head_;
    while(i > 0 && ln != nullptr){
        ln = ln->next;
        i--;
    }
    return ln;
}

int &SinglyLinkedList::operator[](int i){
    if(i < 0 ){
        return minusOne_;
    }
    ListNode *ln;
    ln = head_;
    while(i > 0 && ln != nullptr){
        ln = ln->next;
        i--;
    }
    if(ln == nullptr){
        return minusOne_;
    }else{
        return ln->val;
    }
}

void SinglyLinkedList::print(){
    if(size_ == 0){
        return;
    }
    ListNode *ln;
    ln = head_;
    while(ln != nullptr){
        std::cout << ln->val << std::endl;
        ln = ln->next;
    }
}

std::vector<int> SinglyLinkedList::convert_to_vector(){
    std::vector<int> result;
    if(size_ == 0){
        return result;
    }
    ListNode *ln;
    ln = head_;
    while(ln != nullptr){
        result.push_back(ln->val);
        ln = ln->next;
    }
    return result;
}

ListNode* SinglyLinkedList::erase(int i){
    if(i < 0){
        return nullptr;
    }
    ListNode* resultLN, *pln;
    resultLN = head_;
    for(int n = i; n > 0 && resultLN != nullptr; n--){
        pln = resultLN;
        resultLN = resultLN->next;
    }
    if(resultLN == nullptr){
        return nullptr;
    }
    if(i == 0){
        head_ = resultLN->next;
        size_--;
        return nullptr;
    }
    pln->next = resultLN->next;
    delete(resultLN);
    size_--;
    return pln;
}

ListNode* SinglyLinkedList::erase(ListNode *p){
    if(p == nullptr){
        return nullptr;
    }
    ListNode* resultLN, *pln;
    resultLN = head_;
    while(resultLN != nullptr){
        if(resultLN == p){
            break;
        }
        pln = resultLN;
        resultLN = resultLN->next;
    }
    if(resultLN == nullptr){
        return nullptr;
    }
    if(p == head_){
        head_ = head_->next;
        delete(resultLN);
        size_--;
        return nullptr;     
    }
    pln->next = resultLN->next;
    delete(resultLN);
    size_--;
    return pln;
}

ListNode* SinglyLinkedList::GetPrevious(ListNode *p){
    if(p == nullptr){
        return nullptr;
    }
    if(p == head_){
        return nullptr;
    }
    ListNode* resultLN, *pln;
    resultLN = head_;
    while(resultLN != nullptr){
        if(resultLN == p){
            return pln;
        }
        pln = resultLN;
        resultLN = resultLN->next;
    }
    return nullptr;
}

void SinglyLinkedList::remove_duplicates(){
    if(size_ <= 1){
        return;
    }
    std::vector<int> lnv;
    ListNode *cln, *pln;
    cln = head_->next;
    pln = head_;
    lnv.push_back(pln->val);
    while(cln != nullptr){
        if(std::find(lnv.begin(), lnv.end(), cln->val) != lnv.end()){
            pln->next = cln->next;
            delete(cln);
            size_--;
            cln = pln->next;
            continue;
        }else{
            lnv.push_back(cln->val);        
        }
        pln = cln;
        cln = cln->next;
    }
}

void SinglyLinkedList::reverse(){
    ListNode *prev, *cur, *next;
    prev = nullptr;
    cur = head_;
    next = nullptr;
    while(cur != nullptr){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head_ = prev;
}



