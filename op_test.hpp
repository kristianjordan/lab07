#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include "op.hpp"
using namespace std;

// op testing


// test case for nonzero value
TEST(OpTest, OpEvaluateNonZero) {
    // assign pointer to op object and pass value 8 to constructor
    Op* test = new Op(8.0);

    EXPECT_DOUBLE_EQ(test->evaluate(), 8.0); // expect value = 8
    EXPECT_TRUE(test->stringify() == "8.000000"); // expect stringify function to return string of 8 with 6 leading 0's

    // deallocations
    delete test;
}

// test case for value = 0
TEST(OpTest, OpEvaluateZero) {
    // assign pointer to op object and pass value 0 to constructor
    Op* test = new Op(0.0);

    EXPECT_DOUBLE_EQ(test->evaluate(), 0.0); // expect value = 0
    EXPECT_TRUE(test->stringify() == "0.000000"); // expect stringify function to return string of 0 with 6 leading 0's

    // deallocations
    delete test;
}

// test case for value = negative
TEST(OpTest, OpEvaluateNegative) {
    // assign pointer to op object and pass value -7 to constructor
    Op* test = new Op(-7.0);
    
    EXPECT_DOUBLE_EQ(test->evaluate(), -7.0); // expect value = -7
    EXPECT_TRUE(test->stringify() == "-7.000000"); // expect stringify function to return string of -7 with 6 leading 0's

    // deallocations
    delete test;
}

// test case for value = fraction
TEST(OpTest, OpEvaluateFraction) {
    // assign pointer to op object and pass value 100.123456 to constructor
    Op* test = new Op(100.123456);
    
    EXPECT_DOUBLE_EQ(test->evaluate(), 100.123456); // expect value = 100.123456
    EXPECT_TRUE(test->stringify() == "100.123456");  // expect stringify function to return string of 100.123456 

    //deallocations
    delete test;
}

#endif //__OP_TEST_HPP__
