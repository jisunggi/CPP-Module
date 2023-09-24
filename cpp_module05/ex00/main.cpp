#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return ostream;
}

int main ()
{
	Bureaucrat bureaucratA;
	if (bureaucratA.checkGrade())
		return 1;
	Bureaucrat bureaucratB("Bureaucrate_B", 150);
	if (bureaucratB.checkGrade())
		return 1;

	bureaucratA.incrementGrade();
	std::cout << bureaucratA << std::endl;
	bureaucratA.decrementGrade();
	std::cout << bureaucratA << std::endl;

	std::cout << "-----------------" << std::endl;
	bureaucratB.decrementGrade();
	std::cout << bureaucratB << std::endl;
	bureaucratB.incrementGrade();
	std::cout << bureaucratB << std::endl;
}