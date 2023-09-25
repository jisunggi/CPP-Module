#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("AForm"), grade(1)
{
	this->sign = false;
	std::cout << "AForm : Default constructor called" << std::endl;
}

AForm::AForm(std::string setName, int setGrade) : name(setName), grade(setGrade) 
{
	this->sign = false;
	std::cout << "AForm : Constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm : Destructor called" << std::endl;
}

AForm::AForm(const AForm &aform) : name(aform.getName()), grade(aform.getGrade())
{
	this->sign = aform.getBeSigned();
	std::cout << "AForm : Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &aform)
{
	if (this != &aform)
	{
		this->sign = aform.getBeSigned();
	}
	std::cout << "AForm : Copy assignment operator called" << std::endl;
	return *this;
}

std::string AForm::getName() const
{
	return this->name;
}

int AForm::getGrade() const
{
	return this->grade;
}

bool AForm::getBeSigned() const
{
	return this->sign;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() <= this->grade)
		{
			this->sign = true;
			bureaucrat.signAForm(*this);
		}
		else
		{
			this->sign = false;
			bureaucrat.signAForm(*this);
			throw AForm::GradeTooLowException();
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int AForm::checkGrade()
{
	try {
		if (this->grade < 1)
			throw AForm::GradeTooHighException();
		if (this->grade > 150)
			throw AForm::GradeTooLowException();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "aform grade too high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "aform grade too low";
}