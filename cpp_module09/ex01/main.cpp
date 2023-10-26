#include "RPN.hpp"

int main (int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::exception();
		RPN rpn;
		rpn.executeRPN(std::string(argv[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}