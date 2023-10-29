#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : name("PresidentialPardonForm"), signGrade(25), execGrade(5)
{
	this->target = "trees";
	this->sign = false;
	std::cout << "PresidentialPardonForm : Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : name("PresidentialPardonForm"), signGrade(25), execGrade(5)
{
	this->target = target;
	this->sign = false;
	std::cout << "PresidentialPardonForm : Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm : Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm) : name(presidentialPardonForm.getName()), signGrade(getSignGrade()), execGrade(getExecGrade())
{
	this->sign = presidentialPardonForm.getSign();
	std::cout << "PresidentialPardonForm : Copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm)
{
	if (this != &presidentialPardonForm)
	{
		this->sign = presidentialPardonForm.getSign();
	}
	std::cout << "PresidentialPardonForm : Copy assignment operator called" << std::endl;
	return *this;
}

std::string PresidentialPardonForm::getName() const
{
	return this->name;
}

int PresidentialPardonForm::getSignGrade() const
{
	return this->signGrade;
}

int PresidentialPardonForm::getExecGrade() const
{
	return this->execGrade;
}


bool PresidentialPardonForm::getSign() const
{
	return this->sign;
}

void PresidentialPardonForm::beSigned(Bureaucrat &executor)
{
	try
	{
		if (this->sign == true)
		{
			this->sign = false;
			throw AForm::AlreadySigned();
		}
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

int PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign() && !checkExecute(executor, this->getExecGrade()))
	{
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		return 0;
	}
	return 1;
}