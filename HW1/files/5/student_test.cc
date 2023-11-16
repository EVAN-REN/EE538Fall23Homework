#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(ClimbStairsTest, ReturnWayNumber){
    std::vector<int> input_set = {-3,1,2,3,4,5,6,7,8,13,20};
    std::vector<int> expect_set  = {-1,1,2,4,7,13,24,44,81,1705,121415};

    for(int i = 0; i < input_set.size(); i++){
        int actual = ClimbStairs(input_set[i]);
        int expected = expect_set[i];
        EXPECT_EQ(expected, actual);
    }
}