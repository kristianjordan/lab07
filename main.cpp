#include <iostream>
#include "factory.hpp"
using namespace std;
int main(int argc, char** argv) {
    Factory * factory = new Factory();
    Base * result = factory->parse(argc, argv);
    if (result == nullptr)
    {
        cout << "Error. Equation syntax error" << endl;
    }
    else
    {
        cout << result->stringify() << " = " << result->evaluate() << endl;
    }
    delete result;
    delete factory;
    return 0;
}
