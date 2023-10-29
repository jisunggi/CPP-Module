#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return ostream;
}

std::ostream &operator<<(std::ostream &ostream, const AForm &aform)
{
	ostream << aform.getName() << ", form sign grade : " << aform.getSignGrade();
	ostream << ", form exec grade : " << aform.getExecGrade() << ".";
	return ostream;
}

int main ()
{
	try
	{
		Bureaucrat bureaucratA("Bureaucrate_A", 149);
		bureaucratA.checkGrade();
		Bureaucrat bureaucratB("Bureaucrate_B", 44);
		bureaucratB.checkGrade();
		Bureaucrat bureaucratC("Bureaucrate_C", 26);
		bureaucratC.checkGrade();
		ShrubberyCreationForm shrubberyCreationForm("home");
		RobotomyRequestForm robotomyRequestForm("robot");
		PresidentialPardonForm presidentialPardonForm("Presidential");
		
		std::cout << "<<---------------------->>" << std::endl;
		std::cout << bureaucratA << std::endl;
		std::cout << bureaucratB << std::endl;
		std::cout << bureaucratC << std::endl;
		std::cout << shrubberyCreationForm << std::endl;
		std::cout << robotomyRequestForm << std::endl;
		std::cout << presidentialPardonForm << std::endl;
		std::cout << std::endl;

		std::cout << "-----------------" << std::endl;
		bureaucratA.signForm(shrubberyCreationForm);
		bureaucratA.executeForm(shrubberyCreationForm);

		std::cout << "-----------------" << std::endl;
		bureaucratB.signForm(robotomyRequestForm);
		bureaucratB.executeForm(robotomyRequestForm);

		std::cout << "-----------------" << std::endl;
		bureaucratC.signForm(presidentialPardonForm);
		bureaucratC.executeForm(presidentialPardonForm);
		
		std::cout << "-----------------" << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}