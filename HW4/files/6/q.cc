#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

void DFS(std::vector<std::vector<char>>& maze, int x, int y){
    maze[x][y] = '0';
    
    if(y + 1 < maze[0].size() && maze[x][y + 1] == '1'){
        DFS(maze, x, y + 1);
    }

    if(x + 1 < maze.size() && maze[x + 1][y] == '1'){
        DFS(maze, x + 1, y);
    }

    if(y - 1 >= 0 && maze[x][y - 1] == '1'){
        DFS(maze, x, y - 1);
    }

    if(x - 1 >= 0 && maze[x - 1][y] == '1'){
        DFS(maze, x - 1, y);
    }
}

int NumConnectedComponents(std::vector<std::vector<char>>& maze){
    int result = 0;
    if(maze.empty()){
        return result;
    }
    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[0].size(); j++){
            if(maze[i][j] == '1'){
                result++;
                DFS(maze, i, j);
            }
        }
    }
    return result;
}

