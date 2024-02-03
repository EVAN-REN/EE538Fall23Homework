
#include <vector>

// Imagine you are designing a strategy-based computer game. The game is on a
// two-dimensional grid where each cell contains a certain amount of energy
// points that the player will lose if they pass through that cell. The player
// starts in the top-left corner of the grid and must reach the bottom-right
// corner to complete the level.

// Objective:
// The player's objective is to conserve as much energy as possible throughout
// their journey. The goal is to find the minimum energy it
// would take to reach the bottom-right corner.

// Movement Constraints:
// The player can only move either down or right from their current position on
// the grid.

// Task:
// Design an algorithm that returns the minimum energy it
// would take to reach the bottom-right corner.

// Examples 1:
// Input:
// [1, 3, 1]
// [1, 5, 1]
// [4, 2, 1]
// Expected Output: The minimum energy expenditure is 7.
// The path would be top-left (1) → right (3) → right (1) → down (1) → down (1).

// Examples 2:
// Input:
// [1, 2, 3]
// [4, 5, 6]
// Expected Output: The minimum energy expenditure is 12.
// The path would be top-left (1) → right (2) → right (3) → down (6).

int findMinimumEnergyPath(std::vector<std::vector<int>> &grid);
