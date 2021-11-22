#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include "mult.hpp"
#include "div.hpp"
using namespace std;


// testing case for (5 * 5) / 5
TEST(MultTest, MultDivCombinedTest) {
	// creating op objects for operands and assigning it to pointer
        Base *operand1 = new Op(5);
        Base *operand2 = new Op(5);
        Base *operand3 = new Op(5);
	
	// creating pointers for Mult and Div objects
        Base *multiplication = new Mult(operand1, operand2);
        Base *division = new Div(multiplication, operand3);

        EXPECT_DOUBLE_EQ(division->evaluate(), 5.0); // expect quotient = 5
        EXPECT_TRUE(division->stringify() == "((5.000000 * 5.000000) / 5.000000)"); // expect strinfigy function return to equal string of equation

	// deallocations
	delete operand1;
	delete operand2;
	delete operand3;
	delete multiplication;
	delete division;
}

// testing case for positive product
TEST(MultTest, MultTestPositiveNumber) {
	// creating op objects for operands and assigning it to pointer
        Op *operand1 = new Op(4);
        Op *operand2 = new Op(5);
	
	// creating Mult object to pass operands and assigning it to multiplication pointer
        Mult *multiplication = new Mult(operand1, operand2);

        EXPECT_DOUBLE_EQ(multiplication->evaluate(), 20.0); // expect product = 20
        EXPECT_TRUE(multiplication->stringify() == "(4.000000 * 5.000000)"); // expect strinfigy function return to equal string of equation
	
	// deallocations
	delete operand1;
	delete operand2;
	delete multiplication;
}


// testing case for product = 0
TEST(MultTest, MultTestZero) {
	// creating op objects for operands and assigning it to pointer
        Op *operand1 = new Op(17);
        Op *operand2 = new Op(0);
	
	// creating Mult object to pass operands and assigning it to multiplication pointer
        Mult *multiplication = new Mult(operand1, operand2);

        EXPECT_DOUBLE_EQ(multiplication->evaluate(), 0.0); // expect product = 0
        EXPECT_TRUE(multiplication->stringify() == "(17.000000 * 0.000000)"); // expect strinfigy function return to equal string of equation

	// deallocations
        delete operand1;
        delete operand2;
        delete multiplication;
}


// testing case for product = negative
TEST(MultTest, MultNegativeNumber) {
	// creating op objects for operands and assigning it to pointer
        Op *operand1 = new Op(-8);
        Op *operand2 = new Op(6);
	
	// creating Mult object to pass operands and assigning it to multiplication pointer
        Mult *multiplication = new Mult(operand1, operand2);

        EXPECT_DOUBLE_EQ(multiplication->evaluate(), -48.0); // expect product = -48
        EXPECT_TRUE(multiplication->stringify() == "(-8.000000 * 6.000000)"); // expect strinfigy function return to equal string of equation

	// deallocations
        delete operand1;
        delete operand2;
        delete multiplication;
}

// testing case for product = fraction
TEST(MultTest, MultTestFraction) {
	// creating op objects for operands and assigning it to pointer
        Op *operand1 = new Op(1.0);
        Op *operand2 = new Op(1.5);
	
	// creating Mult object to pass operands and assigning it to multiplication pointer
        Mult *multiplication = new Mult(operand1, operand2);

        EXPECT_DOUBLE_EQ(multiplication->evaluate(), 1.50); // expect product = 1.5
        EXPECT_TRUE(multiplication->stringify() == "(1.000000 * 1.500000)"); // expect strinfigy function return to equal string of equation

	// deallocations
        delete operand1;
        delete operand2;
        delete multiplication;
}


#endif //__MULT_TEST_HPP__

