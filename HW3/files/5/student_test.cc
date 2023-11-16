#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(pushTest, ReturnInt){
    DoubleStack ds;
    ds.push(2);
    int actual = ds.top();
    int expected = 2;
    EXPECT_EQ(expected, actual);
}

TEST(popTest, ReturnInt){
    DoubleStack ds;
    ds.push(4);
    ds.push(2);
    ds.pop();
    int actual = ds.top();
    int expected = 4;
    EXPECT_EQ(expected, actual);
}

TEST(sizeTest, ReturnInt){
    DoubleStack ds;
    ds.push(4);
    ds.push(2);
    int actual = ds.size();
    int expected = 2;
    EXPECT_EQ(expected, actual);
}

TEST(emptyTest, ReturnInt){
    DoubleStack ds;
    ds.push(4);
    bool actual = ds.empty();
    bool expected = false;
    EXPECT_EQ(expected, actual);
}
