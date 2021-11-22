#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include "sub.hpp"
#include "add.hpp"
using namespace std;



// addition testing


// testing case for (7 - 5) + 3
TEST(AddTest, AddSubCombinedTest) {
	// creating op objects for each operand and assigning to pointer
        Base *operand1 = new Op(7); 
        Base *operand2 = new Op(5); 
        Base *operand3 = new Op(3); 

        Base *subtraction = new Sub(operand1, operand2); // create subtraction pointer to point to Sub object containing 
							 // result of subtraction operation
							 
        Base *addition = new Add(subtraction, operand3); // create addition pointer to point to Add object containing 
							 // result of addition operation

        EXPECT_DOUBLE_EQ(addition->evaluate(), 5.0); // expect final result of addition to equal 5
        EXPECT_TRUE(addition->stringify() == "((7.000000 - 5.000000) + 3.000000)"); // testing to see if stringify function return is equal to string of
										    // equation 
	
	// deallocations
	delete operand1;
	delete operand2;
	delete operand3;
	delete subtraction;
	delete addition;

}


// testing case for positive sum
TEST(AddTest, AddTestPositiveNumber) {
	// create op object for operands and assign to pointer
	Op *operand1 = new Op(2);
	Op *operand2 = new Op(9);

	// creates addition object and passes operands
	// assign it to addition pointer
        Add *addition = new Add(operand1, operand2);
	
        EXPECT_DOUBLE_EQ(addition->evaluate(), 11.0); // expect sum to equal 11
	EXPECT_TRUE(addition->stringify() == "(2.000000 + 9.000000)"); // expect strinfigy function return to equal string of equation

	// deallocations
	delete operand1;
	delete operand2;
	delete addition;
}

// testing case for sum = 0
TEST(AddTest, AddTestZero) {
	// create op object for operands and assign to pointer
        Op *operand1 = new Op(5);
        Op *operand2 = new Op(-5);
	
	// creates addition object and passes operands
        // assign it to addition pointer
        Add *addition = new Add(operand1, operand2);

        EXPECT_DOUBLE_EQ(addition->evaluate(), 0.0); // expect sum = 0
        EXPECT_TRUE(addition->stringify() == "(5.000000 + -5.000000)"); // expect strinfigy function return to equal string of equation

	 // deallocations
        delete operand1;
        delete operand2;
        delete addition;

}

// testing case for sum = negative number
TEST(AddTest, AddTestNegativeNumber) {
	// create op object for operands and assign to pointer
        Op *operand1 = new Op(-95);
        Op *operand2 = new Op(-5);

	// creates addition object and passes operands
        // assign it to addition pointer
        Add *addition = new Add(operand1, operand2);

        EXPECT_DOUBLE_EQ(addition->evaluate(), -100.0); // expect sum = -100
        EXPECT_TRUE(addition->stringify() == "(-95.000000 + -5.000000)"); // expect strinfigy function return to equal string of equation

	 // deallocations
        delete operand1;
        delete operand2;
        delete addition;

}


// testing case for sum = fraction
TEST(AddTest, AddTestFraction) {
	// create op object for operands and assign to pointer
        Op *operand1 = new Op(0.50);
        Op *operand2 = new Op(0.25);
	
	// creates addition object and passes operands
        // assign it to addition pointer
        Add *addition = new Add(operand1, operand2);

        EXPECT_DOUBLE_EQ(addition->evaluate(), 0.75); // expect sum = 0.75
        EXPECT_TRUE(addition->stringify() == "(0.500000 + 0.250000)"); // expect strinfigy function return to equal string of equation

	// deallocations
	delete operand1;
	delete operand2;
	delete addition;
}

#endif //__ADD_TEST_HPP__

