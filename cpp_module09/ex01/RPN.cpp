#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN(){}

RPN::RPN(const RPN &RPN)
{
	(void)RPN;
}

RPN &RPN::operator=(const RPN &RPN)
{
	if (this != &RPN)
	{
	}
    return *this;
}

void RPN::executeRPN(std::string input)
{
	checkInput();
	storeStack();
	calculate();
}