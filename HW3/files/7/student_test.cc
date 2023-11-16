#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(kClosestMemoryUsagesTest1, ReturnBool){
    std::vector<int> vec = {1,2,3,4,5};
    int k ,x;
    k = 4;
    x = 3;
    std::vector<int> actual = kClosestMemoryUsages(vec, k, x);
    std::vector<int> expected = {1,2,3,4};
    EXPECT_EQ(actual, expected);
}

TEST(kClosestMemoryUsagesTest2, ReturnBool){
    std::vector<int> vec = {1,2,3,4,5};
    int k ,x;
    k = 4;
    x = -1;
    std::vector<int> actual = kClosestMemoryUsages(vec, k, x);
    std::vector<int> expected = {1,2,3,4};
    EXPECT_EQ(actual, expected);
}