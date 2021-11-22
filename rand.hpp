#ifndef __RAND_HPP__
#define __RAND_HPP__
#include "base.hpp"
#include <string.h>
using namespace std;

class Rand : public Base {
    private:
        double number;
    public:
        Rand() : Base() { }
        virtual double evaluate() { number = rand() % 100; return number; }
        virtual std::string stringify() { return to_string(number); }
};

#endif //__RAND_HPP__
