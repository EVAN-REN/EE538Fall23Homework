#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(CheckValidExpressionTest1, ReturnBool){
    std::string input = "(a+b)";
    bool actual = CheckValidExpression(input);
    bool expected = true;
    EXPECT_EQ(actual, expected);
}

TEST(CheckValidExpressionTest2, ReturnBool){
    std::string input = "(a+b)[c*d]{5g+h}";
    bool actual = CheckValidExpression(input);
    bool expected = true;
    EXPECT_EQ(actual, expected);
}

TEST(CheckValidExpressionTest3, ReturnBool){
    std::string input = "(a+b]";
    bool actual = CheckValidExpression(input);
    bool expected = false;
    EXPECT_EQ(actual, expected);
}

TEST(CheckValidExpressionTest4, ReturnBool){
    std::string input = "(7h+[5c)+7]";
    bool actual = CheckValidExpression(input);
    bool expected = false;
    EXPECT_EQ(actual, expected);
}

TEST(CheckValidExpressionTest5, ReturnBool){
    std::string input = "{2k+[5j]}";
    bool actual = CheckValidExpression(input);
    bool expected = true;
    EXPECT_EQ(actual, expected);
}

TEST(CheckValidExpressionTest6, ReturnBool){
    std::string input = "{2k++[5--*j]}";
    bool actual = CheckValidExpression(input);
    bool expected = true;
    EXPECT_EQ(actual, expected);
}

TEST(CheckValidExpressionTest7, ReturnBool){
    std::string input = "123";
    bool actual = CheckValidExpression(input);
    bool expected = true;
    EXPECT_EQ(actual, expected);
}