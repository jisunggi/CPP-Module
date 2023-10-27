#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

class RPN
{
	private :
		std::stack<int> rpnStack;
		std::stack<std::string> elementsStack;
		int numbersOfOperator;
		int numbersOfNum;

    public :
        RPN();
        ~RPN();
		RPN(const RPN &RPN);
		RPN &operator=(const RPN &RPN);

		void executeRPN(std::string input);
		void storeStack(std::string input);
		void checkInputElement(std::string element);
		int isOperator(std::string element);

		void calculate();
		void storeRPNStack(std::string op);
		int	stringToInt(std::string string);
		int elementsCalculate(int a, int b, std::string op);

};

#endif