#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern : Default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern : Destructor called" << std::endl;
}

Intern::Intern(const Intern &intern)
{
	(void)intern;
	std::cout << "Intern : Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &intern)
{
	(void)intern;
	std::cout << "Intern : Copy assignment operator called" << std::endl;
	return *this;
}

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*function[3])(std::string) = {&Intern::makeShrubberyCreationForm, \
												&Intern::makeRobotomyRequestForm, \
												&Intern::makePresidentialPardonForm};
	
	for(int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*function[i])(target);
		}
	}
	std::cout << name << "form doesn't exist" << std::endl;
	return NULL;
}