#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <stack>

class RPN
{
	private :
		std::stack<char> rpnStack;

    public :
        RPN();
        ~RPN();
		RPN(const RPN &RPN);
		RPN &operator=(const RPN &RPN);

		void executeRPN(std::string input);
};

#endif