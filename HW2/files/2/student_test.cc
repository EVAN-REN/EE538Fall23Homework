#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(GetTest1, ReturnValue){
    SizedMap sm(5);
    sm.Put(1, "one");
    std::string actual = sm.Get(1);
    std::string expected = "one";
    EXPECT_EQ(actual, expected);
}

TEST(GetTest2, ReturnValue){
    SizedMap sm(5);
    sm.Put(1, "one");
    std::string actual = sm.Get(2);
    std::string expected = "INVALID_KEY";
    EXPECT_EQ(actual, expected);
}

TEST(PutTest1, ReturnNull){
    SizedMap sm(2);
    sm.Put(1, "one");
    sm.Put(2, "two");
    sm.Put(3, "three");
    std::string actual = sm.Get(3);
    std::string expected = "three";
    EXPECT_EQ(actual, expected);
}

TEST(PutTest2, ReturnNull){
    SizedMap sm(2);
    sm.Put(1, "one");
    sm.Put(2, "two");
    sm.Put(3, "three");
    std::string actual = sm.Get(1);
    std::string expected = "INVALID_KEY";
    EXPECT_EQ(actual, expected);
}

TEST(SizeTest1, ReturnSize){
    SizedMap sm(5);
    sm.Put(1, "one");
    sm.Put(2, "two");
    sm.Put(3, "three");
    int actual = sm.Size();
    int expected = 3;
    EXPECT_EQ(actual, expected);
}

TEST(SizeTest2, ReturnSize){
    SizedMap sm(2);
    sm.Put(1, "one");
    sm.Put(2, "two");
    sm.Put(3, "three");
    int actual = sm.Size();
    int expected = 2;
    EXPECT_EQ(actual, expected);
}

TEST(operatorTest, ReturnObject){
    SizedMap sm1(3);
    sm1.Put(1, "one");
    sm1.Put(2, "two");
    sm1.Put(3, "three");
    SizedMap sm2(4);
    sm2.Put(1, "four");
    sm2.Put(6, "six");
    sm2.Put(5, "five");
    SizedMap actual = sm1.operator+(sm2);
    std::string actual1 = actual.Get(1);
    std::string expected1 = "four";
    std::string actual2 = actual.Get(2);
    std::string expected2 = "two";
    std::string actual3 = actual.Get(3);
    std::string expected3 = "three";
    std::string actual4 = actual.Get(6);
    std::string expected4 = "six";
    std::string actual5 = actual.Get(5);
    std::string expected5 = "five";
    std::string actual6 = actual.Get(4);
    std::string expected6 = "INVALID_KEY";
    EXPECT_EQ(actual1, expected1);
    EXPECT_EQ(actual2, expected2);
    EXPECT_EQ(actual3, expected3);
    EXPECT_EQ(actual4, expected4);
    EXPECT_EQ(actual5, expected5);
    EXPECT_EQ(actual6, expected6);
    
}

TEST(ReverseTest, ReturnNull){
    SizedMap sm(2);
    sm.Put(1, "one");
    sm.Put(2, "two");
    sm.Reverse();
    sm.Put(3, "three");
    std::string actual = sm.Get(1);
    std::string expected = "one";
    EXPECT_EQ(actual, expected);
}