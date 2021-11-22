#ifndef __COMPOSITE_HPP__
#define __COMPOSITE_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string.h>
using namespace std;

class Composite : public Base {
    protected:
	Base * operand1;
	Base * operand2;  
    public:
	~Composite() {
      	if (operand1 != nullptr)
        {
            delete operand1;
            operand1 = nullptr;
        }
        if (operand2 != nullptr)
        {
            delete operand2;
            operand2 = nullptr;
        }
	}
        Composite(Base *op1, Base *op2) : Base() {operand1 = op1; operand2 = op2; }
        virtual double evaluate() = 0;
        virtual string stringify() = 0;
};

#endif //__COMPOSITE_HPP__
