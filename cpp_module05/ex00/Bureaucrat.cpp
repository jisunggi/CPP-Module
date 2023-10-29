#include "Bureaucrat.hpp"

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

void Bureaucrat::checkGrade()
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::incrementGrade()
{
	this->grade--;
	checkGrade();
}

void Bureaucrat::decrementGrade()
{
	this->grade++;
	checkGrade();
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low";
}