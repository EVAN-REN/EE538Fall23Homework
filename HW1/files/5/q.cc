#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

int ClimbStairs(int n){
    // std::vector<int> dp(n + 1, 0);
    // dp[0] = 1;
    // for(int i = 1; i < n; i++){
    //     if((i - 1) >= 0){
    //         dp[i] += dp[i - 1];
    //     }
    //     if((i - 2) >= 0){
    //         dp[i] += dp[i - 2];
    //     }
    //     if((i - 3) >= 0){
    //         dp[i] += dp[i - 3];
    //     }
    // }
    // return dp[n];

    int way = 0;
    if(n < 0){
        return -1;
    }
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    if(n == 3){
        return 4;
    }
    if(n - 1 > 0){
        way += ClimbStairs(n - 1);
    }
    if(n - 2 > 0){
        way += ClimbStairs(n - 2);
    }
    if(n - 3 > 0){
        way += ClimbStairs(n - 3);
    }
    return way;
}