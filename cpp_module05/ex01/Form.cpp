#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), signGrade(1), execGrade(1)
{
	this->sign = false;
	std::cout << "Form : Default constructor called" << std::endl;
}

Form::Form(std::string setName, int setSignGrade, int setExecGrade) : name(setName), signGrade(setSignGrade), execGrade(setExecGrade) 
{
	this->sign = false;
	std::cout << "Form : Constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form : Destructor called" << std::endl;
}

Form::Form(const Form &form) : name(form.getName()), signGrade(form.getSignGrade()), execGrade(form.getExecGrade())
{
	this->sign = form.getSign();
	std::cout << "Form : Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &form)
{
	if (this != &form)
	{
		this->sign = form.getSign();
	}
	std::cout << "Form : Copy assignment operator called" << std::endl;
	return *this;
}

std::string Form::getName() const
{
	return this->name;
}

int Form::getSignGrade() const
{
	return this->signGrade;
}

int Form:: getExecGrade() const
{
	return this->execGrade;
}

bool Form::getSign() const
{
	return this->sign;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (this->sign == true)
		{
			this->sign = false;
			throw Form::AlreadySigned();
		}
		if (bureaucrat.getGrade() <= this->signGrade)
			this->sign = true;
		else
			throw Form::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Form::checkGrade()
{
	if (this->signGrade < 1 || this->execGrade < 1)
		throw Form::GradeTooHighException();
	if (this->signGrade > 150 || this->execGrade > 150)
		throw Form::GradeTooLowException();
}

const char * Form::AlreadySigned::what() const throw()
{
	return "AlreadySigned";
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "form grade too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "form grade too low";
}