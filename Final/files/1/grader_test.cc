#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "q.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
using testing::UnorderedElementsAre;

TEST(CombinationSumTest, BasicTest) {

  std::vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  auto result = combinationSum(candidates, target);
  EXPECT_THAT(result, UnorderedElementsAre(UnorderedElementsAre(7),
                                           UnorderedElementsAre(2, 2, 3)));
}

TEST(CombinationSumTest, BasicTest2) {

  std::vector<int> candidates = {1, 4, 6};
  int target = 6;
  auto result = combinationSum(candidates, target);
  EXPECT_THAT(result,
              UnorderedElementsAre(UnorderedElementsAre(1, 1, 1, 1, 1, 1),
                                   UnorderedElementsAre(1, 1, 4),
                                   UnorderedElementsAre(6)));
}

TEST(CombinationSumTest, EmptyCandidates) {

  std::vector<int> candidates = {};
  int target = 7;
  auto result = combinationSum(candidates, target);
  EXPECT_TRUE(result.empty());
}

TEST(CombinationSumTest, ZeroTarget) {

  std::vector<int> candidates = {2, 3, 6, 7};
  int target = 0;
  auto result = combinationSum(candidates, target);
  EXPECT_TRUE(result.empty());
}

TEST(CombinationSumTest, Impossible) {

  std::vector<int> candidates = {2, 4, 6, 8};
  int target = 5;
  auto result = combinationSum(candidates, target);
  EXPECT_TRUE(result.empty());
}