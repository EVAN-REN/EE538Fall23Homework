#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "q.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(MinimumEnergyPathTest, SmallGrid) {
  std::vector<std::vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  EXPECT_EQ(findMinimumEnergyPath(grid), 7);
}

TEST(MinimumEnergyPathTest, AnotherSmallGrid) {
  std::vector<std::vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
  EXPECT_EQ(findMinimumEnergyPath(grid), 12);
}

TEST(MinimumEnergyPathTest, SingleRowGrid) {
  std::vector<std::vector<int>> grid = {{1, 2, 3, 4}};
  EXPECT_EQ(findMinimumEnergyPath(grid), 10);
}

TEST(MinimumEnergyPathTest, SingleColumnGrid) {
  std::vector<std::vector<int>> grid = {{1}, {2}, {3}, {4}};
  EXPECT_EQ(findMinimumEnergyPath(grid), 10);
}

TEST(MinimumEnergyPathTest, EmptyGrid) {
  std::vector<std::vector<int>> grid = {};
  EXPECT_EQ(findMinimumEnergyPath(grid), 0);
}

TEST(MinimumEnergyPathTest, LargeGrid) {
  std::vector<std::vector<int>> grid(100, std::vector<int>(100, 1));
  EXPECT_EQ(findMinimumEnergyPath(grid), 199);
}

TEST(MinimumEnergyPathTest, AllZeros) {
  std::vector<std::vector<int>> grid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  EXPECT_EQ(findMinimumEnergyPath(grid), 0);
}

TEST(MinimumEnergyPathTest, NegativeValues) {
  std::vector<std::vector<int>> grid = {//
                                        {-1, -3, -1},
                                        {-1, -5, -1},
                                        {-4, -2, -1}};
  EXPECT_EQ(findMinimumEnergyPath(grid), -12);
}