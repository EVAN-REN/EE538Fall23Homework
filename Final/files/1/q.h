#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <thread>
#include <unordered_set>
#include <vector>

// Imagine you are planning a menu for a party and have a list of distinct
// dishes, each with a certain cost. Your goal is to find all unique
// combinations of dishes that together cost exactly your budget.

// Each dish can be selected multiple times.
// Two combinations are considered unique if they differ in the number of times
// at least one dish is chosen.

// Example 1:

// Dishes and Costs: [Pizza = 2, Burger = 3, Salad = 5]
// Budget: 8
//  Your output should be a two-dimensional vector:
// [[2,2,2,2], [2, 2, 3], [2, 3, 3], [3, 5]].

// Explanation:
// 4 Pizzas (2+2+2+2).
// 2 Pizzas + 1 Burger (2+2+3)
// 1 Pizza + 2 Burgers (2+3+3)
// 1 Burger + 1 Salad (3+5)

// Example 2:

// Dishes and Costs: [Pasta = 1, Sandwich = 4, Sushi = 6]
// Budget: 6

//  Your output should be a two-dimensional vector:
// [[1, 1, 1, 1, 1, 1], [1, 1, 4], [6]].
// Possible Combinations:

// 6 Pastas (1+1+1+1+1+1)
// 2 Pasta + 1 Sandwich (1+1+4)
// 1 Sushi (6)

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                             int target);
