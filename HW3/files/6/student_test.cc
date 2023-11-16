#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------


TEST(IsFullTest1, ReturnBool){
    Tree mytree(new TreeNode('3'));
    mytree.Insert('2');
    mytree.Insert('1');
    mytree.Insert('4');
    bool actual = mytree.IsFull();
    bool expected = false;
    EXPECT_EQ(actual, expected);
}

TEST(IsFullTest2, ReturnBool){
    Tree mytree(new TreeNode('3'));
    mytree.Insert('2');
    mytree.Insert('4');
    bool actual = mytree.IsFull();
    bool expected = true;
    EXPECT_EQ(actual, expected);
}

TEST(CreateHistogramTest, ReturnMap){
    Tree mytree(new TreeNode('3'));
    mytree.Insert('2');
    mytree.Insert('5');
    mytree.Insert('4');
    mytree.Insert('6');
    std::map<char, int> actual = mytree.CreateHistogram();
    std::map<char, int> expected = {{'2',1},{'5',1},{'4',1},{'6',1},{'3',1}};
    EXPECT_EQ(actual, expected);
}

TEST(CountNodesTest, ReturnMap){
    Tree mytree(new TreeNode('3'));
    mytree.Insert('2');
    mytree.Insert('5');
    mytree.Insert('4');
    mytree.Insert('6');
    int actual = mytree.CountNodes();
    int expected = 5;
    EXPECT_EQ(actual, expected);
}

TEST(ToVectorPostOrderTest, ReturnMap){
    Tree mytree(new TreeNode('2'));
    mytree.Insert('1');
    mytree.Insert('4');
    mytree.Insert('3');
    mytree.Insert('5');
    std::vector<char> actual = mytree.ToVectorPostOrder();
    std::vector<char> expected = {'1','3','5','4','2'};
    EXPECT_EQ(actual, expected);
}

TEST(IsLeftSkewedTest1, ReturnBool){
    Tree mytree(new TreeNode('6'));
    mytree.Insert('5');
    mytree.Insert('4');
    mytree.Insert('3');
    mytree.Insert('2');
    mytree.Insert('1');
    bool actual = mytree.IsLeftSkewed();
    bool expected = true;
    EXPECT_EQ(actual, expected);
}

TEST(IsLeftSkewedTest2, ReturnBool){
    Tree mytree(new TreeNode('4'));
    mytree.Insert('2');
    mytree.Insert('1');
    mytree.Insert('3');
    bool actual = mytree.IsLeftSkewed();
    bool expected = false;
    EXPECT_EQ(actual, expected);
}