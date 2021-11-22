#ifndef __POW_HPP__
#define __POW_HPP__
#include "composite.hpp"
#include <string.h>
#include "math.h"

using namespace std;

class Pow : public Composite {
    public:
        Pow(Base *op1, Base *op2) : Composite(op1, op2) {}
        virtual double evaluate() {return (pow(operand1->evaluate(), operand2->evaluate())); }
        virtual string stringify() { return(operand1->stringify() + " ^ " + operand2->stringify()); }
};

#endif //__POW_HPP__
