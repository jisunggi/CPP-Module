#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return ostream;
}

std::ostream &operator<<(std::ostream &ostream, const Form &form)
{
	ostream << form.getName() << ", form grade " << form.getSignGrade() << ".";
	return ostream;
}

int main ()
{
	try
	{
		Bureaucrat bureaucrat("Bureaucrate", 60);
		bureaucrat.checkGrade();
		Form form("Form", 61, 61);
		form.checkGrade();

		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		std::cout << "-----------------" << std::endl;
		
		bureaucrat.signForm(form);
		std::cout << "-----------------" << std::endl;

		bureaucrat.decrementGrade();
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		std::cout << "-----------------" << std::endl;
		
		bureaucrat.signForm(form);
		std::cout << "-----------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}