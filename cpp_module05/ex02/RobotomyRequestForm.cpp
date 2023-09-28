#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : name("RobotomyRequestForm"), signGrade(72), execGrade(45)
{
	this->target = "trees";
	this->sign = false;
	std::cout << "RobotomyRequestForm : Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : name("RobotomyRequestForm"), signGrade(72), execGrade(45)
{
	this->target = target;
	this->sign = false;
	std::cout << "RobotomyRequestForm : Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm : Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm) : name(robotomyRequestForm.getName()), signGrade(getSignGrade()), execGrade(getExecGrade())
{
	this->sign = robotomyRequestForm.getSign();
	std::cout << "RobotomyRequestForm : Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm)
{
	if (this != &robotomyRequestForm)
	{
		this->sign = robotomyRequestForm.getSign();
	}
	std::cout << "RobotomyRequestForm : Copy assignment operator called" << std::endl;
	return *this;
}

std::string RobotomyRequestForm::getName() const
{
	return this->name;
}

int RobotomyRequestForm::getSignGrade() const
{
	return this->signGrade;
}

int RobotomyRequestForm::getExecGrade() const
{
	return this->execGrade;
}


bool RobotomyRequestForm::getSign() const
{
	return this->sign;
}

void RobotomyRequestForm::beSigned(Bureaucrat &executor)
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

void RobotomyRequestForm::randomNumber() const
{
	srand((unsigned int)time(NULL));
	int num = rand() % 10;
	if (num < 5)
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->target << " the robotomy failed" << std::endl;
		
}

int RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign() && !checkExecute(executor, this->getExecGrade()))
	{
		randomNumber();
		return 0;
	}
	return 1;
}