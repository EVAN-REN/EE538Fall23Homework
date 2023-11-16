#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(ReverseTest, ReturnReverse){
    std::vector<std::vector<int>> input_set = {{1,2,3},{4, 5, 6, 7},{2,2,2,2},{100,0,1,100,2}};
    std::vector<std::vector<int>> expect_set = {{3,2,1},{7, 6, 5, 4},{2,2,2,2},{2,100,1,0,100}};
    for(int i = 0; i < input_set.size(); i++){
        std::vector<int> actual = Reverse(input_set[i]);
        std::vector<int> expected = expect_set[i];
        EXPECT_EQ(expected, actual);
    }
}

TEST(PlusOneTest, ReturnPlusOne){
    std::vector<std::vector<int>> input_set = {{1,9},{9, 9, 9},{12},{1, 5, 8, 2, 3}};
    std::vector<std::vector<int>> expect_set = {{2,0},{1, 0, 0, 0},{-1},{1, 5, 8, 2, 4}};
    for(int i = 0; i < input_set.size(); i++){
        std::vector<int> actual = PlusOne(input_set[i]);
        std::vector<int> expected = expect_set[i];
        EXPECT_EQ(expected, actual);
    }
}