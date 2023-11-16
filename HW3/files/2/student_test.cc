#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(CheckValidExpressionTest1,ReturnBool){
    CPPLib cl;
    std::string input = "";
    bool actual = cl.CheckValidExpression(input);
    bool expected = true;
    EXPECT_EQ(expected, actual);
}

TEST(CheckValidExpressionTest2,ReturnBool){
    CPPLib cl;
    std::string input = " }";
    bool actual = cl.CheckValidExpression(input);
    bool expected = false;
    EXPECT_EQ(expected, actual);
}

TEST(CheckValidExpressionTest3,ReturnBool){
    CPPLib cl;
    std::string input = " ({(())})";
    bool actual = cl.CheckValidExpression(input);
    bool expected = true;
    EXPECT_EQ(expected, actual);
}

TEST(CheckValidExpressionTest4, ReturnBool){
    CPPLib cl;
    std::string input = "}dddd{";
    bool actual = cl.CheckValidExpression(input);
    bool expected = false;
    EXPECT_EQ(expected, actual);
}

TEST(IsPalindromeTest1, ReturnBool){
    CPPLib cl;
    std::string input = "";
    bool actual = cl.IsPalindrome(input);
    bool expected = true;
    EXPECT_EQ(expected, actual);
}

TEST(IsPalindromeTest2, ReturnBool){
    CPPLib cl;
    std::string input = "a";
    bool actual = cl.IsPalindrome(input);
    bool expected = true;
    EXPECT_EQ(expected, actual);
}

TEST(IsPalindromeTest3, ReturnBool){
    CPPLib cl;
    std::string input = "abbbba";
    bool actual = cl.IsPalindrome(input);
    bool expected = true;
    EXPECT_EQ(expected, actual);
}

TEST(IsPalindromeTest4, ReturnBool){
    CPPLib cl;
    std::string input = "abcba";
    bool actual = cl.IsPalindrome(input);
    bool expected = true;
    EXPECT_EQ(expected, actual);
}

TEST(IsPalindromeTest5,ReturnBool){
    CPPLib cl;
    std::string input = "abcca";
    bool actual = cl.IsPalindrome(input);
    bool expected = false;
    EXPECT_EQ(expected, actual);
}

TEST(OddCharTest1,ReturnInt){
    CPPLib cl;
    std::string input = "a";
    int actual = cl.OddChar(input);
    char expected = (int)'a';
    EXPECT_EQ(expected, actual);
}

TEST(OddCharTest2,ReturnInt){
    CPPLib cl;
    std::string input = "abbbb";
    int actual = cl.OddChar(input);
    char expected = (int)'a';
    EXPECT_EQ(expected, actual);
}

TEST(OddCharTest3, ReturnInt){
    CPPLib cl;
    std::string input = "bcbdaddcdbb";
    int actual = cl.OddChar(input);
    int expected = (int)'a';
    EXPECT_EQ(expected, actual);
}