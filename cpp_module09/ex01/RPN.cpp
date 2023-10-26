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

// void checkInputElement(char element)
// {
// 	if (isOperator(element))
// 		return ;
// 	if (element >= '0' && element <= '9')
// }

void storeStack(std::string input)
{
	std::stack<std::string> splitStack;
	std::stringstream stringstream(input);
	std::string element;

	if (input.find("  "))
		throw std::exception();
	while (stringstream >> element)
	{
		splitStack.push(element);
	}
	while (!splitStack.empty())
	{
		std::cout << splitStack.top() << std::endl;
		//checkInputElement(splitStack.top());
		splitStack.pop();
	}
}

void RPN::executeRPN(std::string input)
{
	storeStack(input);
	//calculate();
}