#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(CountNumberOfSpacesTest, ReturnNumberOfSpaces){
    std::vector<std::string> input_set = {"EE538 HW1","  EE538 HW1","EE538 HW1  ","EE  538 HW1 "};
    std::vector<int> expect_set  = {1,3,3,4};

    for(int i = 0; i < input_set.size(); i++){
        int actual = CountNumberOfSpaces(input_set[i]);
        int expected = expect_set[i];
        EXPECT_EQ(expected, actual);
    }
}