#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <stack>
#include <queue>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc


std::vector<int> Graph::DFS(int root){
    std::vector<int> visited;
    std::map<int, bool> marks;
    for(auto it = adjacency_list_.begin(); it != adjacency_list_.end(); it++){
        marks[it->first] = false;
    }

    // std::stack<int> s;
    // s.push(root);
    // marks[root] = true;
    // while(!s.empty()){
    //     int node = s.top();
    //     s.pop();
    //     visited.push_back(node);
    //     std::set<int> st = adjacency_list_[node];
    //     for(auto it = st.rbegin(); it != st.rend(); it++){
    //         if(!marks[*it]){
    //             s.push(*it);
    //             marks[*it] = true;
    //         }
    //     }
    // }

    DFS_helper(root, marks, visited);

    return visited;
}

void Graph::DFS_helper(int root, std::map<int, bool> &marks,
                  std::vector<int> &visited){
    marks[root] = true;
    visited.push_back(root);
    std::set<int> st = adjacency_list_[root];
    for(auto n : st){
        if(!marks[n]){
            DFS_helper(n, marks, visited);
        }
    }
}

std::vector<int> Graph::DFSAll(){
    std::vector<int> visited;
    std::map<int, bool> marks;
    for(auto it = adjacency_list_.begin(); it != adjacency_list_.end(); it++){
        marks[it->first] = false;
    }

    for(auto it = adjacency_list_.begin(); it != adjacency_list_.end(); it++){
        if(!marks[it->first]){
            DFS_helper(it->first, marks, visited);
        }
    }
    return visited;
}

BFSReturnValue Graph::BFS(int root){
    BFSReturnValue brv;
    std::map<int, bool> marks;
    for(auto it = adjacency_list_.begin(); it != adjacency_list_.end(); it++){
        brv.distance.push_back(INT_MAX);
        brv.path[it->first] = {};
    }

    int level = 0;
    int lastL = root;
    std::queue<int> q;
    q.push(root);
    brv.path[root].push_back(root);
    marks[root] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        brv.visited.push_back(node);
        brv.distance[node] = level;
        if(node == lastL){
            level++;
        }
        for(int n : adjacency_list_[node]){
            if(!marks[n]){
                q.push(n);
                brv.path[n].assign(brv.path[node].begin(), brv.path[node].end());
                brv.path[n].push_back(n);
                marks[n] = true;
            }
        }
        if(node == lastL){
            lastL = q.back();
        }   
    }
    return brv;
}

bool Graph::IsPathBetweenNodes(int i, int j){
    std::vector<int> vi = DFS(i);
    if(std::find(vi.begin(), vi.end(), j) != vi.end()){
        return true;
    }
    return false;
}

bool Graph::IsBidirectional(){
    if(adjacency_list_.empty()){
        return true;
    }

    for(auto it = adjacency_list_.begin(); it != adjacency_list_.end(); it++){
        for(int i : it->second){
            bool find = false;
            for(int j : adjacency_list_[i]){
                if(j == it->first){
                    find = true;
                    break;
                }
            }
            if(!find){
                return false;
            }
        }
    }   
    return true; 
}

bool Graph::IsConnected(){
    int size_n = adjacency_list_.size();
    for(auto it = adjacency_list_.begin(); it != adjacency_list_.end(); it++){
        if(DFS(it->first).size() != size_n){
            return false;
        }
    }
    return true;
}

bool Graph::ReachesACycle(int start_node){
    std::map<int, NodeStatus> status;
    for(auto it = adjacency_list_.begin(); it != adjacency_list_.end(); it++){
        status[it->first] = NodeStatus::NotVisited;
    }
    status[start_node] = NodeStatus::Visiting;
    return ReachesACycleHelper(start_node, status);
}

bool Graph::ReachesACycleHelper(int start_node, std::map<int, NodeStatus> &status){
    std::set<int> st = adjacency_list_[start_node];
    for(auto n : st){
        if(status[n] == NodeStatus::NotVisited){
            status[n] = NodeStatus::Visited;
            if(ReachesACycleHelper(n, status)){
                return true;
            }
        }else{
            return true;
        }
    }
    return false;
}

bool Graph::HasCycle(){
    for(auto it = adjacency_list_.begin(); it != adjacency_list_.end(); it++){
        if(ReachesACycle(it->first)){
            return true;
        }
    }    
    return false;
}

