#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------


TEST(PrimeTest, ReturnIsPrime){
    std::vector<int> input_set = {13, 4, 2, 105, 523, 659};
    std::vector<bool> expect_set = {true, false, true, false, true, true};
    
    for(int i = 0; i < input_set.size(); i++){
        bool actual = IsPrime(input_set[i]);
        bool expected = expect_set[i];
        EXPECT_EQ(expected, actual);
    }
}