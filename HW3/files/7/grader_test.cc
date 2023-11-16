#include <climits>
#include <iostream>
#include <string>

#include "q.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
using ::testing::ElementsAreArray;
using ::testing::IsEmpty;
using ::testing::UnorderedElementsAre;
template <class T> void PrintVector(std::vector<T> input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size())
      std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(KClosestMemoryUsagesTest, BasicTest) {
  std::vector<int> memoryUsages = {20, 5, 3, 8, 15, 30};
  int k = 3;
  int x = 10;
  std::vector<int> result = kClosestMemoryUsages(memoryUsages, k, x);
  std::vector<int> expected = {5, 8, 15};
  ASSERT_EQ(result, expected);
}

TEST(KClosestMemoryUsagesTest, EdgeCaseAllEqual) {
  std::vector<int> memoryUsages = {10, 10, 10, 10, 10};
  int k = 3;
  int x = 10;
  std::vector<int> result = kClosestMemoryUsages(memoryUsages, k, x);
  std::vector<int> expected = {10, 10, 10};
  ASSERT_EQ(result, expected);
}

TEST(KClosestMemoryUsagesTest, EdgeCaseEmptyInput) {
  std::vector<int> memoryUsages = {};
  int k = 3;
  int x = 10;
  std::vector<int> result = kClosestMemoryUsages(memoryUsages, k, x);
  std::vector<int> expected = {};
  ASSERT_EQ(result, expected);
}

TEST(KClosestMemoryUsagesTest, RandomInput) {
  std::vector<int> memoryUsages = {1, 9, 4, 3, 8};
  int k = 2;
  int x = 5;
  std::vector<int> result = kClosestMemoryUsages(memoryUsages, k, x);
  std::vector<int> expected = {3, 4};
  ASSERT_EQ(result, expected);
}

TEST(KClosestMemoryUsagesTest, Example1) {
    std::vector<int> memoryUsages = {1,2,3,4,5};
    int k = 4;
    int x = 3;
    std::vector<int> result = kClosestMemoryUsages(memoryUsages, k, x);
    std::vector<int> expected = {1,2,3,4};
    ASSERT_EQ(result, expected);
}

TEST(KClosestMemoryUsagesTest, Example2) {
    std::vector<int> memoryUsages = {1,2,3,4,5};
    int k = 4;
    int x = -1;
    std::vector<int> result = kClosestMemoryUsages(memoryUsages, k, x);
    std::vector<int> expected = {1,2,3,4};
    ASSERT_EQ(result, expected);
}


