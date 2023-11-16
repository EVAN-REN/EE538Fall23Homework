#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(CalculatorTest, ReturnCalculateResult){
    float input1 = 3.0;
    float input2 = 3.0;
    float actual_sum;
    float actual_difference;
    float actual_product;
    float actual_ratio;
    ErrorCode actual_result = Calculator(input1, input2, actual_sum, actual_difference, actual_product, actual_ratio);
    float expected_sum = 6.0;
    float expected_difference = 0.0;
    float expected_product = 9.0;
    float expected_ratio = 1.0;
    ErrorCode expected_result = ErrorCode::kNoError;
    EXPECT_FLOAT_EQ(expected_sum, actual_sum);
    EXPECT_FLOAT_EQ(expected_difference, actual_difference);
    EXPECT_FLOAT_EQ(expected_product, actual_product);
    EXPECT_FLOAT_EQ(expected_ratio, actual_ratio);
    EXPECT_EQ(expected_result, actual_result);

}