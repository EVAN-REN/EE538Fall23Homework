#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(Flatten3DVectorTest, Return1DVector){
    std::vector<std::vector<std::vector<std::vector<int>>>> input_set = {
        {{{1, 2}, {3, 4}},
        {{5}, {6}, {}},
        {{7, 8}}},

        {{{1, 2}},
        {{3}, {4}, {5,6}},
        {{7, 8}},
        {{9},{10}},
        {{11}}},

        {{},
        {{1}, {2}, {3,4}},
        {{5, 6}},
        {}},

        {}
    };
    std::vector<std::vector<int>> expect_set = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
        {1, 2, 3, 4, 5, 6},
        {}
    };
    for(int i = 0; i < input_set.size(); i++){
        std::vector<int> actual = Flatten3DVector(input_set[i]);
        std::vector<int> expected =  expect_set[i];
        EXPECT_EQ(expected, actual);
    }
}