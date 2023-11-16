#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(CopyConstructorTest, ReturnNull){
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    Queue q2 = q1;
    int actual = q2.Front();
    int expected = 1;
    EXPECT_EQ(expected, actual);
}

TEST(EqualTest, ReturnNull){
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    Queue q2;
    q2 = q1;
    int actual = q2.Front();
    int expected = 1;
    EXPECT_EQ(expected, actual);
}

TEST(AddTest, ReturnNull){
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    Queue q2;
    q2.Enqueue(3);
    q2.Enqueue(4);
    Queue q3 = q1 + q2;
    int actual = q3.Front();
    int expected = 3;
    EXPECT_EQ(expected, actual);
}

TEST(DequeueTest, ReturnBool){
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    q1.Dequeue();
    int actual = q1.Front();
    int expected = 2;
    EXPECT_EQ(expected, actual);
}

TEST(IsEmptyTest, ReturnBool){
    Queue q1;
    q1.Enqueue(1);
    bool actual = q1.IsEmpty();
    bool expected = false;
    EXPECT_EQ(expected, actual);
}

TEST(GetDataTest, ReturnBool){
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    std::vector<int> actual = q1.GetData();
    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(expected, actual);
}