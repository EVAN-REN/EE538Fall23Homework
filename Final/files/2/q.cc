#include "q.h"

#include <cmath>
#include <chrono>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// recursion solution
int FindMaxTotalCost_Helper(std::vector<int> &costs, int index){
    if(index < 0){
        return 0;
    }

    int paintCurrent = costs[index] + FindMaxTotalCost_Helper(costs, index - 2);
    if(index - 1 < 0){
        return paintCurrent;
    }
    int paintNext =  costs[index - 1] + FindMaxTotalCost_Helper(costs, index - 3);

    return std::max(paintCurrent, paintNext);
}

int FindMaxTotalCost(std::vector<int> &costs){
    if(costs.empty()){
        return 0;
    }
    return FindMaxTotalCost_Helper(costs, costs.size() - 1);
}


// Memoization solution
int FindMaxTotalCostMemo_Helper(std::vector<int> &costs, int n, std::vector<int> &memo){
    if(n < 0){
        return 0;
    }
    // If saved it before, output it directly
    if(memo[n] != -1){
        return memo[n];
    }

    int paintCurrent = costs[n] + FindMaxTotalCostMemo_Helper(costs, n - 2, memo);
    if(n - 1 < 0){
        memo[n] = paintCurrent;
        return paintCurrent;
    }
    int paintNext =  costs[n - 1] + FindMaxTotalCostMemo_Helper(costs, n - 3, memo);
    // store the data
    memo[n] = std::max(paintCurrent, paintNext);

    return memo[n];
}

int FindMaxTotalCostMemo(std::vector<int> &costs){
    if(costs.empty()){
        return 0;
    }
    std::vector<int> memo(costs.size(), -1);
    return FindMaxTotalCostMemo_Helper(costs, costs.size() - 1, memo);
}


// Tabulation solution
int FindMaxTotalCostTabulation(std::vector<int> &costs){
    if(costs.empty()){
        return 0;
    }

    int n = costs.size();
    // Create a table to store the maximum cost at each house
    std::vector<int> dp(n, 0);
    // Base cases
    dp[0] = costs[0];
    if(n > 1){
        dp[1] = std::max(costs[0], costs[1]);
    }
    // Fill the table using tabulation
    for(int i = 2; i < n; i++){
        dp[i] = std::max(dp[i - 1], dp[i - 2] + costs[i]);
    }

    return dp[n - 1];
}


// measure runtime
std::vector<ResultTimesInMicroSeconds> MeasureRunTimes(std::vector<std::vector<int>> inputs){
    std::vector<ResultTimesInMicroSeconds> results;

    for (std::vector<int> &i : inputs) {
        ResultTimesInMicroSeconds result;

        // Measure recursive solution runtime
        auto start_time = std::chrono::high_resolution_clock::now();
        FindMaxTotalCost(i);
        auto end_time = std::chrono::high_resolution_clock::now();
        result.recursive_time_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

        // Measure memoization solution runtime
        start_time = std::chrono::high_resolution_clock::now();
        FindMaxTotalCostMemo(i);
        end_time = std::chrono::high_resolution_clock::now();
        result.memoization_time_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

        // Measure tabulation solution runtime
        start_time = std::chrono::high_resolution_clock::now();
        FindMaxTotalCostTabulation(i);
        end_time = std::chrono::high_resolution_clock::now();
        result.tabulation_time_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

        results.push_back(result);
    }

    return results;
}