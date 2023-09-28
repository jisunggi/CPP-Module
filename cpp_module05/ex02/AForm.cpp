#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("AForm"), signGrade(1), execGrade(1)
{
	this->sign = false;
	std::cout << "AForm : Default constructor called" << std::endl;
}

AForm::AForm(std::string setName) : name(setName), signGrade(1), execGrade(1) 
{
	this->sign = false;
	std::cout << "AForm : Constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm : Destructor called" << std::endl;
}

AForm::AForm(const AForm &aform) : name(aform.getName()), signGrade(aform.getSignGrade()), execGrade(aform.getExecGrade())
{
	this->sign = aform.getSign();
	std::cout << "AForm : Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &aform)
{
	if (this != &aform)
	{
		this->sign = aform.getSign();
	}
	std::cout << "AForm : Copy assignment operator called" << std::endl;
	return *this;
}

std::string AForm::getName() const
{
	return this->name;
}

int AForm::getSignGrade() const
{
	return this->signGrade;
}

int AForm::getExecGrade() const
{
	return this->execGrade;
}

bool AForm::getSign() const
{
	return this->sign;
}

void AForm::beSigned(Bureaucrat &executor)
{
	try
	{
		if (executor.getGrade() <= this->signGrade)
			this->sign = true;
		else
		{
			this->sign = false;
			throw AForm::GradeTooLowException();
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}


int AForm::checkExecute(Bureaucrat const &executor, int formExecGrade) const
{
	try
	{
		if (executor.getGrade() > formExecGrade)
			throw AForm::NoExecuteException();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "form grade too high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "form grade too low";
}

const char * AForm::NoExecuteException::what() const throw()
{
	return "The beuraucrat grade is low, and can't execute the form";
}