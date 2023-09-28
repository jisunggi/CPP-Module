#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat")
{
	this->grade = 1;
	std::cout << "Bureaucrat : Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string setName, int setGrade) : name(setName), grade(setGrade) 
{
	std::cout << "Bureaucrat : Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat : Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.getName())
{
	this->grade = bureaucrat.getGrade();
	std::cout << "Bureaucrat : Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
	{
		this->grade = bureaucrat.getGrade();
	}
	std::cout << "Bureaucrat : Copy assignment operator called" << std::endl;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

int Bureaucrat::checkGrade()
{
	try {
		if (this->grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (this->grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}

void Bureaucrat::incrementGrade()
{
	this->grade--;
	if (checkGrade())
		this->grade++;
}

void Bureaucrat::decrementGrade()
{
	this->grade++;
	if (checkGrade())
		this->grade--;
}

void Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
	if (form.getSign() == true)
		std::cout << this->name << " signed " <<  form.getName() << std::endl;
	else
		std::cout << this->name << " couldn’t sign " <<  form.getName() << " because bureaucrat grade lower than form grade" << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
	if (!form.execute(*this))
		std::cout << this->name << " executed " << form.getName() << std::endl;
	else
		std::cout << this->name << " didn't execute " << form.getName() << std::endl;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "bureaucrat grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "bureaucrat grade too low";
}