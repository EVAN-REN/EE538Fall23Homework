#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(UniqueVectorNotBySetTest1, ReturnNull){
    std::vector<int> actual = {1,2,2,4,6,6};
    UniqueVectorNotBySet(actual);
    std::vector<int> expected = {1,2,4,6};
    EXPECT_EQ(actual, expected);
}

TEST(UniqueVectorNotBySetTest2, ReturnNull){
    std::vector<int> actual = {1,2,4};
    UniqueVectorNotBySet(actual);
    std::vector<int> expected = {1,2,4};
    EXPECT_EQ(actual, expected);
}

TEST(UniqueVectorBySetTest1, ReturnNull){
    std::vector<int> actual = {1,2,2,4,6,6};
    UniqueVectorBySet(actual);
    std::vector<int> expected = {1,2,4,6};
    EXPECT_EQ(actual, expected);
}

TEST(UniqueVectorBySetTest2, ReturnNull){
    std::vector<int> actual = {1,2,4};
    UniqueVectorBySet(actual);
    std::vector<int> expected = {1,2,4};
    EXPECT_EQ(actual, expected);
}

TEST(IntersectVectorsTest1, ReturnVector){
    std::vector<int> input1 = {1,2,2,3,3};
    std::vector<int> input2 = {3,3,4,4,5};
    std::vector<int> actual =IntersectVectors(input1, input2);
    std::vector<int> expected = {3};
    EXPECT_EQ(actual, expected);
}

TEST(IntersectVectorsTest2, ReturnVector){
    std::vector<int> input1 = {1,2,3};
    std::vector<int> input2 = {4,5,6};
    std::vector<int> actual =IntersectVectors(input1, input2);
    std::vector<int> expected = {};
    EXPECT_EQ(actual, expected);
}

TEST(IntersectVectorsTest3, ReturnVector){
    std::vector<int> input1 = {};
    std::vector<int> input2 = {4,5,6};
    std::vector<int> actual =IntersectVectors(input1, input2);
    std::vector<int> expected = {};
    EXPECT_EQ(actual, expected);
}

TEST(IntersectVectorsTest4, ReturnVector){
    std::vector<int> input1 = {1,2,3};
    std::vector<int> input2 = {};
    std::vector<int> actual =IntersectVectors(input1, input2);
    std::vector<int> expected = {};
    EXPECT_EQ(actual, expected);
}

TEST(DiffVectorsTest1, ReturnVector){
    std::vector<int> input1 = {1, 2, 2, 3, 4};
    std::vector<int> input2 = {3, 4, 4, 5};
    std::set<int> actual = DiffVectors(input1, input2);
    std::set<int> expected = {1, 2};
    EXPECT_EQ(actual, expected);
}

TEST(DiffVectorsTest2, ReturnVector){
    std::vector<int> input1 = {};
    std::vector<int> input2 = {3, 4, 4, 5};
    std::set<int> actual = DiffVectors(input1, input2);
    std::set<int> expected = {};
    EXPECT_EQ(actual, expected);
}