#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include "sub.hpp"
#include "add.hpp"
using namespace std;


// subtraction testing

// test case for 10 - (5+5)
TEST(SubTest, SubAddCombinedTest) {
	// creating op objets for operands and assigning to pointer
        Base *operand1 = new Op(5);
        Base *operand2 = new Op(5);
	Base *operand3 = new Op(10);

	// creating Add and Sub objects to pass operands and assign them to pointers
	Base *addition = new Add(operand1, operand2);
        Base *subtraction = new Sub(operand3, addition);
	
        EXPECT_DOUBLE_EQ(subtraction->evaluate(), 0.0); // expect difference = 0
        EXPECT_TRUE(subtraction->stringify() == "(10.000000 - (5.000000 + 5.000000))"); // expect stringify function return to = string of equation

	// deallocations
	delete operand1;
	delete operand2;
	delete operand3;
	delete addition;
	delete subtraction;
}


// test case for positive difference
TEST(SubTest, SubTestPositiveNumber) {
	// create op objects for operands and assign them to pointer
        Op *operand1 = new Op(700);
        Op *operand2 = new Op(400);

	// create Sub object to pass operands and assign to pointer
        Sub *subtraction = new Sub(operand1, operand2);

        EXPECT_DOUBLE_EQ(subtraction->evaluate(), 300.0); // expect difference = 300
        EXPECT_TRUE(subtraction->stringify() == "(700.000000 - 400.000000)"); // expect stringify function return to = string of equation
	
	// deallocations
	delete operand1;
	delete operand2;
	delete subtraction;
}


// test case for difference = 0
TEST(SubTest, SubTestZero) {
	// create op objects for operands and assign them to pointer
        Op *operand1 = new Op(5);
        Op *operand2 = new Op(5);
	
	// create Sub object to pass operands and assign to pointer
        Sub *subtraction = new Sub(operand1, operand2);

        EXPECT_DOUBLE_EQ(subtraction->evaluate(), 0.0); // expect difference = 0
        EXPECT_TRUE(subtraction->stringify() == "(5.000000 - 5.000000)"); // expect stringify function return to = string of equation

	// deallocations
	delete operand1;
	delete operand2;
	delete subtraction;
}


// test case for difference = negative
TEST(SubTest, SubTestNegativeNumber) {
	// create op objects for operands and assign them to pointer
        Op *operand1 = new Op(5);
        Op *operand2 = new Op(10);
	
	// create Sub object to pass operands and assign to pointer		
        Sub *subtraction = new Sub(operand1, operand2);

        EXPECT_DOUBLE_EQ(subtraction->evaluate(), -5.0); // expect difference = -5
        EXPECT_TRUE(subtraction->stringify() == "(5.000000 - 10.000000)"); // expect stringify function return to = string of equation

	// deallocations
	delete operand1;
	delete operand2;
	delete subtraction;
}


// test case for difference = fraction
TEST(SubTest, SubTestFraction) {
	// create op objects for operands and assign them to pointer
        Op *operand1 = new Op(0.70);
        Op *operand2 = new Op(0.25);
	
	// create Sub object to pass operands and assign to pointer
        Sub *subtraction = new Sub(operand1, operand2);

        EXPECT_DOUBLE_EQ(subtraction->evaluate(), 0.45); // expect difference = 0.45
        EXPECT_TRUE(subtraction->stringify() == "(0.700000 - 0.250000)"); // expect stringify function return to = string of equation

	// deallocations
	delete operand1;
	delete operand2;
	delete subtraction;
}

#endif //__SUB_TEST_HPP__


