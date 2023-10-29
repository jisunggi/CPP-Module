#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
		Bureaucrat bureaucratA("Bureaucrate_A", 137);
		bureaucratA.checkGrade();
		Bureaucrat bureaucratB("Bureaucrate_B", 44);
		bureaucratB.checkGrade();
		Bureaucrat bureaucratC("Bureaucrate_C", 5);
		bureaucratC.checkGrade();

		
		Intern  someRandomIntern;
		AForm*	scf;
		AForm*	rrf;
		AForm*	ppf;
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		rrf = someRandomIntern.makeForm("robotomy request", "Tom");
		ppf = someRandomIntern.makeForm("presidential pardon", "Bob");
		
		std::cout << "<<---------------------->>" << std::endl;
		std::cout << bureaucratA << std::endl;
		std::cout << bureaucratB << std::endl;
		std::cout << bureaucratC << std::endl;
		if (scf)
			std::cout << *scf << std::endl;
		if (rrf)
			std::cout << *rrf << std::endl;
		if (ppf)
			std::cout << *ppf << std::endl;
		std::cout << std::endl;

		std::cout << "-----------------" << std::endl;
		if (scf)
		{
			bureaucratA.signForm(*scf);
			bureaucratA.executeForm(*scf);
			delete scf;
			scf = 0;
		}

		std::cout << "-----------------" << std::endl;
		if (rrf)
		{
			bureaucratB.signForm(*rrf);
			bureaucratB.executeForm(*rrf);
			delete rrf;
			rrf = 0;
		}

		std::cout << "-----------------" << std::endl;
		if (ppf)
		{
			bureaucratC.signForm(*ppf);
			bureaucratC.executeForm(*ppf);
			delete ppf;
			ppf = 0;
		}
		
		std::cout << "-----------------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}