#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return ostream;
}

int main ()
{
	try
	{
		Bureaucrat bureaucratA;
		bureaucratA.checkGrade();
		Bureaucrat bureaucratB("Bureaucrate_B", 149);
		bureaucratB.checkGrade();

		bureaucratA.decrementGrade();
		std::cout << bureaucratA << std::endl;
		bureaucratA.incrementGrade();
		std::cout << bureaucratA << std::endl;


		std::cout << "-----------------" << std::endl;
		bureaucratB.decrementGrade();
		std::cout << bureaucratB << std::endl;
		bureaucratB.incrementGrade();
		std::cout << bureaucratB << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}