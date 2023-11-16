#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(ConstructorTest1, ReturnNull){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    int actual = sll.back();
    int expected = 4;
    EXPECT_EQ(expected, actual);
}

TEST(ConstructorTest2, ReturnNull){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    SinglyLinkedList sll2 = sll;
    int actual = sll2.back();
    int expected = 4;
    EXPECT_EQ(expected, actual);
}

TEST(EmptyTest, ReturnBool){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    bool actual = sll.empty();;
    bool expected = false;
    EXPECT_EQ(expected, actual);
}

TEST(SizeTest, ReturnInt){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    int actual = sll.size();
    int expected = 4;
    EXPECT_EQ(expected, actual);
}

TEST(HeadTest, ReturnPointer){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    ListNode* ln = sll.head();
    int actual = ln->val;
    int expected = 1;
    EXPECT_EQ(expected, actual);
}

TEST(PushBackTest, ReturnNull){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    sll.push_back(5);
    int actual = sll.back();
    int expected = 5;
    EXPECT_EQ(expected, actual);
}

TEST(PushBackTest, ReturnBool){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    sll.pop_back();
    int actual = sll[2];
    int expected = 3;
    EXPECT_EQ(expected, actual);
}

TEST(GetBackPointerTest, ReturnPointer){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    ListNode* ln = sll.GetBackPointer();
    int actual = ln->val;
    int expected = 4;
    EXPECT_EQ(expected, actual);
}

TEST(GetIthPointerTest, ReturnPointer){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    ListNode* ln = sll.GetIthPointer(1);
    int actual = ln->val;
    int expected = 2;
    EXPECT_EQ(expected, actual);
}

TEST(convert_to_vectorTest, ReturnVector){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    std::vector<int> actual = sll.convert_to_vector();
    std::vector<int> expected = {1,2,3,4};
    EXPECT_EQ(expected, actual);
}

TEST(eraseTest1, ReturnPointer){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    ListNode* ln = sll.erase(1);
    int actual = ln->val;
    int expected = 1;
    EXPECT_EQ(expected, actual);
}

TEST(eraseTest2, ReturnPointer){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    ListNode* ln1 = sll.GetIthPointer(2);
    ListNode* ln = sll.erase(ln1);
    int actual = ln->val;
    int expected = 2;
    EXPECT_EQ(expected, actual);
}

TEST(GetPreviousTest, ReturnPointer){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    ListNode* ln1 = sll.GetIthPointer(2);
    ListNode* ln = sll.GetPrevious(ln1);
    int actual = ln->val;
    int expected = 2;
    EXPECT_EQ(expected, actual);
}

TEST(remove_duplicatesTest, ReturnNull){
    std::vector<int> vec = {1,2,3,4,3,5,1,2};
    SinglyLinkedList sll(vec);
    sll.remove_duplicates();
    std::vector<int> actual = sll.convert_to_vector();
    std::vector<int> expected = {1,2,3,4,5};
    EXPECT_EQ(expected, actual);
}

TEST(reverseTest, ReturnNull){
    std::vector<int> vec = {1,2,3,4};
    SinglyLinkedList sll(vec);
    sll.reverse();
    std::vector<int> actual = sll.convert_to_vector();
    std::vector<int> expected = {4,3,2,1};
    EXPECT_EQ(expected, actual);
}
