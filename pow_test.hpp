#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include "pow.hpp"
#include "mult.hpp"
using namespace std;

// pow testing

// testing case (1 ^ 9) * 74
TEST(PowTest, PowMultCombinedTest) {
	// creating op objects for operands and assigning them to pointer
        Base *operand1 = new Op(1);
        Base *operand2 = new Op(9);
        Base *operand3 = new Op(74);

	// creating pow and mult objects and assigning them to pointer
        Base *pow = new Pow(operand1, operand2);
        Base *multiplication = new Mult(pow, operand3);

        EXPECT_DOUBLE_EQ(multiplication->evaluate(), 74.0); // expect product = 74
        EXPECT_TRUE(multiplication->stringify() == "((1.000000 ^ 9.000000) * 74.000000)"); // expect stringify function return to = string of equation

	// deallocations
	delete operand1;
	delete operand2;
	delete operand3;
	delete pow;
	delete multiplication;
}


// testing case for positive exponentiation
TEST(PowTest, PowTestPositiveNumber) {
	// creating op objects for operands assigning them to pointers
        Op *operand1 = new Op(1);
        Op *operand2 = new Op(35);
	
	// creating pow object to pass operands and assigning to pointer
        Pow *pow = new Pow(operand1, operand2);

        EXPECT_DOUBLE_EQ(pow->evaluate(), 1.0); // expect exponentiation = 1
        EXPECT_TRUE(pow->stringify() == "(1.000000 ^ 35.000000)"); // expect stringify function return to = string of equation

	// deallocations
	delete operand1;
	delete operand2;
	delete pow;
}


// testing case for exponentiation = 0
TEST(PowTest, PowTestZero) {
	// creating op objects for operands assigning them to pointers
        Op *operand1 = new Op(0);
        Op *operand2 = new Op(13);

	// creating pow object to pass operands and assigning to pointer
        Pow *pow = new Pow(operand1, operand2);

        EXPECT_DOUBLE_EQ(pow->evaluate(), 0.0); // expect exponentiation = 0
        EXPECT_TRUE(pow->stringify() == "(0.000000 ^ 13.000000)"); // expect stringify function return to = string of equation
	
	// deallocations
	delete operand1;
	delete operand2;
	delete pow;
}

// testing case for exponentiation = negative
TEST(PowTest, PowNegativeNumber) {
	// creating op objects for operands assigning them to pointers
        Op *operand1 = new Op(-1);
        Op *operand2 = new Op(3);

	// creating pow object to pass operands and assigning to pointer
        Pow *pow = new Pow(operand1, operand2);

        EXPECT_DOUBLE_EQ(pow->evaluate(), -1.0); // expect exponentiation = -1
        EXPECT_TRUE(pow->stringify() == "(-1.000000 ^ 3.000000)"); // expect stringify function return to = string of equation

	// deallocations
	delete operand1;
	delete operand2;
	delete pow;
}

#endif //__POW_TEST_HPP__

