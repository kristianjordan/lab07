#ifndef __MULT_HPP__
#define __MULT_HPP__
#include "composite.hpp"
#include <string.h>

using namespace std;

class Mult : public Composite {
    public:
        Mult(Base *op1, Base *op2) : Composite(op1, op2) {}
        virtual double evaluate() {return (operand1->evaluate() * operand2->evaluate()); }
        virtual string stringify() { return(operand1->stringify() + " * " + operand2->stringify()); }
};

#endif //__MULT_HPP__
