#include <algorithm>
#include <iostream>
#include <vector>

// Given an unsorted vector of numbers showing how much memory different
// programs use. You need to pick `k` programs whose memory usage is closest to
// a given number `x`. The result should be a sorted vector.

// A process with memory usage `a` is closer to x than a process with memory
// usage `b` if: |a - x| < |b - x|, or |a - x| == |b - x| and a < b.

// Constraints:
// 1. You cannot use binary search.
// 2. You cannot use sort the input `memoryUsages` vector.

// Example 1:

// Input: memoryUsages = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]

// Example 2:

// Input: memoryUsages = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]

std::vector<int> kClosestMemoryUsages(const std::vector<int> &memoryUsages,
                                      int k, int x);
