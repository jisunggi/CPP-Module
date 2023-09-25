#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Form"), grade(1)
{
	this->sign = false;
	std::cout << "Form : Default constructor called" << std::endl;
}

Form::Form(std::string setName, int setGrade) : name(setName), grade(setGrade) 
{
	this->sign = false;
	std::cout << "Form : Constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form : Destructor called" << std::endl;
}

Form::Form(const Form &form) : name(form.getName()), grade(form.getGrade())
{
	this->sign = form.getBeSigned();
	std::cout << "Form : Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &form)
{
	if (this != &form)
	{
		this->sign = form.getBeSigned();
	}
	std::cout << "Form : Copy assignment operator called" << std::endl;
	return *this;
}

std::string Form::getName() const
{
	return this->name;
}

int Form::getGrade() const
{
	return this->grade;
}

bool Form::getBeSigned() const
{
	return this->sign;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() <= this->grade)
		{
			this->sign = true;
			bureaucrat.signForm(*this);
		}
		else
		{
			this->sign = false;
			bureaucrat.signForm(*this);
			throw Form::GradeTooLowException();
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int Form::checkGrade()
{
	try {
		if (this->grade < 1)
			throw Form::GradeTooHighException();
		if (this->grade > 150)
			throw Form::GradeTooLowException();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "form grade too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "form grade too low";
}