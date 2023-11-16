#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(SwapByPointerTest, ReturnNull){
    float *a = new float();
    float *b = new float();
    *a = 1.0;
    *b = 3.0;
    SwapByPointer(a, b);
    EXPECT_EQ(*a, 3.0);
    EXPECT_EQ(*b, 1.0);
    delete(a);
    delete(b);
}

TEST(SwapByReferenceTest, ReturnNull){
    float a,b;
    a = 1.0;
    b = 3.0;
    SwapByReference(a, b);
    EXPECT_EQ(a, 3);
    EXPECT_EQ(b, 1);
}