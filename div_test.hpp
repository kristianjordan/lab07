#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include "div.hpp"
#include "mult.hpp"
using namespace std;

// division testing

// (5 / 5) * 50
TEST(DivTest, DivMultCombinedTest) {
	// creating op objects for operands and assigning it to pointer 
        Base *operand1 = new Op(5);
        Base *operand2 = new Op(5);
        Base *operand3 = new Op(50);

	// creating Div and Mult objects and assigning them to pointers
	// to do equation operations
        Base *division = new Div(operand1, operand2);
        Base *multiplication = new Mult(division, operand3);

        EXPECT_DOUBLE_EQ(multiplication->evaluate(), 50.0); // expect final result of product = 50
        EXPECT_TRUE(multiplication->stringify() == "((5.000000 / 5.000000) * 50.000000)"); // expect strinfigy function return to equal string of equation
	
	// deallocations
	delete operand1;
	delete operand2;
	delete operand3;
	delete division;
	delete multiplication;

}

// testing case for positive quotient
TEST(DivTest, DivTestPositiveNumber) {
	// creating op objects for operands and assigning it to pointer
        Op *operand1 = new Op(25);
        Op *operand2 = new Op(25);
        
	// creating Div object to pass operands and assigning it to division pointer
	Div *division = new Div(operand1, operand2);

        EXPECT_DOUBLE_EQ(division->evaluate(), 1.0); // expect quotient to = `
        EXPECT_TRUE(division->stringify() == "(25.000000 / 25.000000)"); // expect strinfigy function return to equal string of equation
	
	// deallocations
        delete operand1;
        delete operand2;
        delete division;
}


// testting case for quotient = 0
TEST(DivTest, DovTestZero) {
	// creating op objects for operands and assigning it to pointer
        Op *operand1 = new Op(0);
        Op *operand2 = new Op(90);
        
	// creating Div object to pass operands and assigning it to division pointer
	Div *division = new Div(operand1, operand2);

        EXPECT_DOUBLE_EQ(division->evaluate(), 0.0); // expect quotient = 0
        EXPECT_TRUE(division->stringify() == "(0.000000 / 90.000000)"); // expect strinfigy function return to equal string of equation

	// deallocations
        delete operand1;
        delete operand2;
        delete division;
}


// testing case for quotient = negative number
TEST(DivTest, DivNegativeNumber) {
	// creating op objects for operands and assigning it to pointer
        Op *operand1 = new Op(-25);
        Op *operand2 = new Op(5);

	// creating Div object to pass operands and assinging it to division pointer
        Div *division = new Div(operand1, operand2);
	
        EXPECT_DOUBLE_EQ(division->evaluate(), -5.0); // expect quotient = -5
        EXPECT_TRUE(division->stringify() == "(-25.000000 / 5.000000)"); // expect strinfigy function return to equal string of equation

	// deallocations
        delete operand1;
        delete operand2;
        delete division;
}


// testing case for quotient = fraction
TEST(DivTest, DivTestFraction) {
	// creating op objects for operands and assigning it to pointer
        Op *operand1 = new Op(3.0);
        Op *operand2 = new Op(4.0);

	// creating Div object to pass operands and assigning it to division pointer
        Div *division = new Div(operand1, operand2);

        EXPECT_DOUBLE_EQ(division->evaluate(), 0.75); // expect quotient = 0.75
        EXPECT_TRUE(division->stringify() == "(3.000000 / 4.000000)"); // expect strinfigy function return to equal string of equation
	
	// deallocations
        delete operand1;
        delete operand2;
        delete division;

}

// test case for when a number is divided by 0
TEST(DivTest, DivDivideZeroTest) {
	// create op objects for operands and assign to pointer
	Op * operand1 = new Op(7.0);
	Op * operand2 = new Op(0.0);
	
	// create double infinity to use when testing the 
	// evaluate function	
	double infinity = (1.0/0.0);

	// create Div object to pass parameters and assign to pointer
	Div *division = new Div(operand1, operand2);

	// compare quotient of 7/0 with inifity. should be equal because
	// a number > 0 divided by zero outputs infinity
	EXPECT_EQ(division->evaluate(), infinity);	

	EXPECT_TRUE(division->stringify() == "(7.000000 / 0.000000)"); // expect strinfigy function return to equal string of equation

	// deallocations
	delete operand1;
	delete operand2;
	delete division;
}
#endif //__OP_TEST_HPP__

