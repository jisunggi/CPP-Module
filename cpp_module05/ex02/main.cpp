#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return ostream;
}

std::ostream &operator<<(std::ostream &ostream, const Form &form)
{
	ostream << form.getName() << ", form grade " << form.getGrade() << ".";
	return ostream;
}

int main ()
{
	Bureaucrat bureaucratA("Bureaucrate_A", 60);
	if (bureaucratA.checkGrade())
		return 1;
	Form formA("Form_A", 61);
	if (formA.checkGrade())
		return 1;

	std::cout << bureaucratA << std::endl;
	std::cout << formA << std::endl;
	std::cout << "-----------------" << std::endl;
	
	formA.beSigned(bureaucratA);
	std::cout << "-----------------" << std::endl;

	bureaucratA.decrementGrade();
	bureaucratA.decrementGrade();
	std::cout << bureaucratA << std::endl;
	std::cout << "-----------------" << std::endl;
	
	formA.beSigned(bureaucratA);

}