#include "RPN.hpp"

RPN::RPN() {
	numbersOfNum = 0;
	numbersOfOperator = 0;
}

RPN::~RPN(){}

RPN::RPN(const RPN &rpn)
{
	this->rpnStack = rpn.rpnStack;
	this->elementsStack = rpn.elementsStack;
    this->numbersOfOperator = rpn.numbersOfOperator;
    this->numbersOfNum = rpn.numbersOfNum;
}

RPN &RPN::operator=(const RPN &rpn)
{
	if (this != &RPN)
	{
		this->rpnStack = rpn.rpnStack;
		this->elementsStack = rpn.elementsStack;
		this->numbersOfOperator = rpn.numbersOfOperator;
		this->numbersOfNum = rpn.numbersOfNum;
	}
    return *this;
}

int RPN::isOperator(std::string element)
{
	if (element == "+" || element == "-" || element == "/" || element == "*")
		return 1;
	return 0;
}

void RPN::checkInputElement(std::string element)
{
	if (element.size() > 1)
		throw std::exception();
	if (isOperator(element))
	{
		numbersOfOperator++;
		return ;
	}
	if (!(element >= "0" && element <= "9"))
		throw std::exception();
	numbersOfNum++;
}

void RPN::storeStack(std::string input)
{
	std::stack<std::string> reverseStack;
	std::stringstream stringstream(input);
	std::string element;

	if (input.find("  ") != std::string::npos)
		throw std::exception();
	while (stringstream >> element)
		reverseStack.push(element);
	while (!reverseStack.empty())
	{
		checkInputElement(reverseStack.top());
		elementsStack.push(reverseStack.top());
		reverseStack.pop();
	}
	if ((numbersOfNum - 1) != numbersOfOperator)
		throw std::exception();
}

int RPN::elementsCalculate(int a, int b, std::string op)
{
	if (op == "/" && b == 0)
		throw std::exception();
	if (op == "+")
		return (a + b);
	if (op == "-")
		return (a - b);
	if (op == "*")
		return (a * b);
	if (op == "/")
		return (a / b);
	return 0;
}

void RPN::storeRPNStack(std::string op)
{
	int a;
	int b;

	if (rpnStack.size() < 2)
		throw std::exception();
	b = rpnStack.top();
	rpnStack.pop();
	a = rpnStack.top();
	rpnStack.pop();
	rpnStack.push(elementsCalculate(a, b, op));
}

int	RPN::stringToInt(std::string string)
{
	std::stringstream stream;
	int integer;

	stream << string;
	stream >> integer;
	return integer;
}

void RPN::calculate()
{
	while (!elementsStack.empty())
	{
		if (!isOperator(elementsStack.top()))
		{
			rpnStack.push(stringToInt(elementsStack.top()));
		}
		else
		{
			storeRPNStack(elementsStack.top());
		}
		elementsStack.pop();
	}
	std::cout << rpnStack.top() << std::endl;	
}

void RPN::executeRPN(std::string input)
{
	storeStack(input);
	calculate();
}