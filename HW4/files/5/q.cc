#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

bool findPath(std::vector<std::vector<int>>& maze, std::vector<std::vector<int>> &result){
    int x = result.back()[0];
    int y = result.back()[1];

    if(x == maze.size() - 1 && y == maze[0].size() - 1){
        return true;
    }

    if(y + 1 < maze[0].size() && maze[x][y + 1] != 1){
        result.push_back({x, y + 1});
        maze[x][y + 1] = 1;
        if(findPath(maze, result)){
            return true;
        }else{
            result.pop_back();
        }
    }

    if(x + 1 < maze.size() && maze[x + 1][y] != 1){
        result.push_back({x + 1, y});
        maze[x + 1][y] = 1;
        if(findPath(maze, result)){
            return true;
        }else{
            result.pop_back();
        }
    }

    if(y - 1 >= 0 && maze[x][y - 1] != 1){
        result.push_back({x, y - 1});
        maze[x][y - 1] = 1;
        if(findPath(maze, result)){
            return true;
        }else{
            result.pop_back();
        }
    }

    if(x - 1 >= 0 && maze[x - 1][y] != 1){
        result.push_back({x - 1, y});
        maze[x - 1][y] = 1;
        if(findPath(maze, result)){
            return true;
        }else{
            result.pop_back();
        }
    }

    return false;
}

std::vector<std::vector<int>> HikerPath(std::vector<std::vector<int>>& maze){
    std::vector<std::vector<int>> result;
    if(maze.empty() || maze[0][0] == 1){
        result.push_back({-1,-1});
        return result;
    }
    result.push_back({0,0});
    if(!findPath(maze, result)){
        result.pop_back();
        result.push_back({-1,-1});
    }
    return result;
}