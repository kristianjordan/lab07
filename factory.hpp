#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include <iostream>
#include <string>
using namespace std;

class Factory
{
public:
    Factory(){}
    Base * parse(int length, char** input)
    {
        // convert input array into a simple string
        // called newInput
        string newInput = "";
        for (int i = 1; i < length; i++)
        {
            newInput = newInput + input[i];
        }

        // if the first character is not a number,
        // return nullptr
        if (!isdigit(newInput[0]))
            return nullptr;
        // otherwise, loop through array of characters
        int index = 0;
        Base * previous = nullptr;

        while (index < newInput.length())
        {
            // if the character is a digit then add it to a new string called num
            if (isdigit(newInput[index]))
            {
                string num = "";
                // while each character after the first character is a digit
                while (isdigit(newInput[index]))
                {
                    // add it to new string
                    num = num + newInput[index];
                    // increment to the next character
                    index++;
                }
                previous = new Op(atoi(num.c_str()));
            }
            else if ((newInput[index] == '+') || (newInput[index] == '-') ||
            (newInput[index] == '*') || (newInput[index] == '/')) {
                if ((!isdigit(newInput[index + 1])) && (newInput[index + 1] != '*'))
		{
		    if (previous != nullptr)
			delete previous;
                    return nullptr;
		}
                switch (newInput[index]) {
                    case '+':
                        if (isdigit(newInput[index + 1])) {
                            // increment to next character
                            index++;
                            // create new string
                            string add = "";
                            // while each character after the '+' is a digit
                            while (isdigit(newInput[index])) {
                                // add it to new string
                                add = add + newInput[index];
                                // increment to the next character
                                index++;
                            }
                            previous = new Add(previous, new Op(atoi(add.c_str())));
                        }
                        else
			{
			    if (previous != nullptr)
				delete previous;
                            return nullptr;
			}
                        break;
                    case '-':
                        if (isdigit(newInput[index + 1])) {
                            // increment to next character
                            index++;
                            string sub = ""; // new empty string
                            // while each character after the '+' is a digit
                            while (isdigit(newInput[index])) {
                                // add it to new string
                                sub = sub + newInput[index];
                                // increment to the next character
                                index++;
                            }
                            previous = new Sub(previous, new Op(atoi(sub.c_str())));
                        }
                        else
			{
			    if (previous != nullptr)
			    	delete previous;
                            return nullptr;
			}
                        break;
                    case '/':
                        if (isdigit(newInput[index + 1])) {
                            // increment to next character
                            index++;
                            string div = ""; // new empty string
                            // while each character after the '+' is a digit
                            while (isdigit(newInput[index])) {
                                // add it to new string
                                div = div + newInput[index];
                                // increment to the next character
                                index++;
                            }
                            previous = new Div(previous, new Op(atoi(div.c_str())));
                        }
                        else
			{
			    if (previous != nullptr)
				delete previous;
                            return nullptr;
			}
                        break;
                    case '*':
                        if (isdigit(newInput[index + 1])) {
                            // increment to next character
                            index++;
                            string multiplication = ""; // new empty string
                            // while each character after the '+' is a digit
                            while (isdigit(newInput[index])) {
                                // add it to new string
                                multiplication = multiplication + newInput[index];
                                // increment to the next character
                                index++;
                            }
                            previous = new Mult(previous, new Op(atoi(multiplication.c_str())));
                        } else if ((newInput[index + 1]) == '*') {
                            index++;
                            if (isdigit(newInput[index + 1])) {
                                // increment to next character
                                index++;
                                string power = ""; // new empty string
                                // while each character after the '+' is a digit
                                while (isdigit(newInput[index])) {
                                    // add it to new string
                                    power = power + newInput[index];
                                    // increment to the next character
                                    index++;
                                }
                                int number;
                                number = atoi(power.c_str());
                                previous = new Pow(previous, new Op(number));
                            }
                            else
			    {
				if (previous != nullptr)
					delete previous;
                                return nullptr;
			    }
                       }
                }
            }
            else
	    {
		if (previous != nullptr)
			delete previous; 
                return nullptr;
	    }
        }
        return previous;
    }
};

