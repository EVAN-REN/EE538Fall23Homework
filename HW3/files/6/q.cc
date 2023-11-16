#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

Tree::~Tree(){
    if(root_ != nullptr){
        DestroySubtree(root_);
    }
}

void Tree::DestroySubtree(TreeNode *root){
    if(root->left != nullptr){
        DestroySubtree(root->left);
    }
    if(root->right != nullptr){
        DestroySubtree(root->right);
    }
    delete(root);
}

bool Tree::IsFull(){
    if(root_ == nullptr){
        return false;
    }
    bool is_full = true;
    IsFull_helper(root_, is_full);
    return is_full;
}

void Tree::IsFull_helper(TreeNode *root, bool &is_full){
    if(root->left != nullptr && root->right == nullptr ){
        is_full = false;
        return;
    }
    if(root->left == nullptr && root->right != nullptr ){
        is_full = false;
        return;
    }
    if(root->left != nullptr){
        IsFull_helper(root->left, is_full);
    }
    if(root->right != nullptr){
        IsFull_helper(root->right, is_full);
    }
}

std::map<char, int> Tree::CreateHistogram(){
    std::map<char, int> histogram = {};
    if(root_ == nullptr){
        return histogram;
    }
    CreateHistogram_helper(root_, histogram);
    return histogram;
}

void Tree::CreateHistogram_helper(TreeNode *root, std::map<char, int> &map){
    if(map.count(root->data) > 0){
        map[root->data]++;
    }else{
        map.insert(std::pair(root->data, 1));
    }
    if(root->left != nullptr){
        CreateHistogram_helper(root->left, map);
    }
    if(root->right != nullptr){
        CreateHistogram_helper(root->right, map);
    }
}

int Tree::CountNodes(){
    if(root_ == nullptr){
        return 0;
    }
    return CountNodesHelper(root_);
}

int Tree::CountNodesHelper(TreeNode *root){
    int nodeCount = 1;
    if(root->left != nullptr){
        nodeCount += CountNodesHelper(root->left);
    }
    if(root->right != nullptr){
        nodeCount += CountNodesHelper(root->right);
    }
    return nodeCount;
}

std::vector<char> Tree::ToVectorPostOrder(){
    std::vector<char> vec;
    if(root_ == nullptr){
        return vec;
    }
    ToVectorPostOrderHelper(root_, vec);
    return vec;
}

void Tree::ToVectorPostOrderHelper(TreeNode *root, std::vector<char> &vec){
    if(root->left != nullptr){
        ToVectorPostOrderHelper(root->left, vec);
    }
    if(root->right != nullptr){
        ToVectorPostOrderHelper(root->right, vec);
    }
    vec.push_back(root->data);
}

void Tree::Insert(char data){
    if(root_ == nullptr){
        root_ = new TreeNode(data);
        return;
    }
    Insert_helper(root_, data);
}

void Tree::Insert_helper(TreeNode *&root, char data){
    if(root->data == data){
        return;
    }else if(root->data > data){
        if(root->left == nullptr){
            TreeNode* node = new TreeNode(data);
            root->left = node;
        }else{
            Insert_helper(root->left, data);
        }
    }else{
        if(root->right == nullptr){
            TreeNode* node = new TreeNode(data);
            root->right = node;
        }else{
            Insert_helper(root->right, data);
        }
    }
}

bool Tree::IsLeftSkewed(){
    if(root_ == nullptr){
        return true;
    }
    return IsLeftSkewed_helper(root_);
}

bool Tree::IsLeftSkewed_helper(TreeNode *root){
    if(root->right != nullptr){
        return false;
    }
    if(root->left == nullptr){
        return true;
    }
    return IsLeftSkewed_helper(root->left);
}

