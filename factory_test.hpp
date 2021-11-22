#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include "factory.hpp"
using namespace std;

// testing multiplication and subtraction
TEST(FactoryTest, MultSubTest) {
	Factory * factory = new Factory();
	char *equation[] = {"calculator","6*3+2"};
	Base * result = factory->parse(2, equation);
	EXPECT_EQ(result->evaluate(), 20); // expect value = 20
    

    	// deallocations
    	delete factory;
	delete result;
}

// testing first character is not number
TEST(FactoryTest, FirstCharacterErrorTest) {
        Factory * factory = new Factory();
        char *equation[] = {"calculator","+2*3+1"};
        Base * result = factory->parse(2, equation);
        EXPECT_EQ(result, nullptr); 


    	// deallocations
    	delete factory;
}

// testing pow and division
TEST(FactoryTest, PowDivTest) {
        Factory * factory = new Factory();
        char *equation[] = {"calculator","2**3/2"};
        Base * result = factory->parse(2, equation);
        EXPECT_EQ(result->evaluate(), 4); 


        // deallocations
        delete factory;
        delete result;
}

// testing addition
TEST(FactoryTest, AdditionTest) {
        Factory * factory = new Factory();
        char *equation[] = {"calculator","9+9+9"};
        Base * result = factory->parse(2, equation);
        EXPECT_EQ(result->evaluate(), 27);


        // deallocations
        delete factory;
        delete result;
}

// testing consecutive operations
TEST(FactoryTest, DoubleOperationTest) {
        Factory * factory = new Factory();
        char *equation[] = {"calculator", "2+-3+2"};
        Base * result = factory->parse(2, equation);
        EXPECT_EQ(result, nullptr);


        // deallocations
        delete factory;
}

// testing error on last character
TEST(FactoryTest, LastCharacterError) {
        Factory * factory = new Factory();
        char *equation[] = {"calculator", " 5**3/2' "};
        Base * result = factory->parse(2, equation);
        EXPECT_EQ(result, nullptr); 


        // deallocations
        delete factory;
}

// testing all operations
TEST(FactoryTest, AllOperationsTest) {
        Factory * factory = new Factory();
        char *equation[] = {"calculator","1**2*4/2*8+10-4"};
        Base * result = factory->parse(2, equation);
        EXPECT_EQ(result->evaluate(), 22); 


        // deallocations
        delete factory;
        delete result;
}


// testing negative result
TEST(FactoryTest,NegativeTest) {
        Factory * factory = new Factory();
        char *equation[] = {"calculator","6*2-14"};
        Base * result = factory->parse(2, equation);
        EXPECT_EQ(result->evaluate(), -2); 


        // deallocations
        delete factory;
        delete result;
}

// testing negative result
TEST(FactoryTest,ZeroTest) {
        Factory * factory = new Factory();
        char *equation[] = {"calculator","7**2-49"};
        Base * result = factory->parse(2, equation);
        EXPECT_EQ(result->evaluate(), 0);


        // deallocations
        delete factory;
        delete result;
}

#endif //__FACTORY_TEST_HPP__
