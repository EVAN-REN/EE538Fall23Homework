#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(CanBecomeTest, ReturnIfCanBecome){

    std::vector<std::vector<std::string>> input_set = {{"abcde","cdeab"},{"abcde","abced"},
        {"abcde","cdea"},{"aaaa","aaaa"},{"",""}};
    std::vector<bool> expect_set  = {true, false, false, true, true};

    for(int i = 0; i < input_set.size(); i++){
        bool actual = CanBecome(input_set[i][0], input_set[i][1]);
        int expected = expect_set[i];
        EXPECT_EQ(expected, actual);
    }
}