#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(CountCharactersTest, ReturnCount1){
    std::string input = "This is a test";
    std::map<char, int> actual = CountCharacters(input);
    std::map<char, int> expected = {{'T', 1}, {'h', 1}, {'i', 2}, {'s', 3},
         {' ', 3}, {'a', 1}, {'t', 2}, {'e', 1}};
    EXPECT_EQ(actual, expected);
}

TEST(CountCharactersTest, ReturnCount2){
    std::string input = "";
    std::map<char, int> actual = CountCharacters(input);
    std::map<char, int> expected = {};
    EXPECT_EQ(actual, expected);
}

TEST(CountCharactersTest, ReturnCount3){
    std::string input = "   12, ,";
    std::map<char, int> actual = CountCharacters(input);
    std::map<char, int> expected = {{' ', 4}, {'1', 1}, {'2', 1}, {',', 2}};
    EXPECT_EQ(actual, expected);
}