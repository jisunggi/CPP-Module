#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public :
		Intern();
		~Intern();
		Intern(const Intern &intern);
		Intern &operator=(const Intern &intern);

		AForm *makeForm(std::string name, std::string target);
		AForm *makeShrubberyCreationForm(std::string target);
		AForm *makeRobotomyRequestForm(std::string target);
		AForm *makePresidentialPardonForm(std::string target);
};

#endif