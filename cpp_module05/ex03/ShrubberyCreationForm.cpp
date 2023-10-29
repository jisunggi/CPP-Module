#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : name("ShrubberyCreationForm"), signGrade(145), execGrade(137)
{
	this->target = "trees";
	this->sign = false;
	std::cout << "ShrubberyCreationForm : Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : name("ShrubberyCreationForm"), signGrade(145), execGrade(137)
{
	this->target = target;
	this->sign = false;
	std::cout << "ShrubberyCreationForm : Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm : Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm) : name(shrubberyCreationForm.getName()), signGrade(getSignGrade()), execGrade(getExecGrade())
{
	this->sign = shrubberyCreationForm.getSign();
	std::cout << "ShrubberyCreationForm : Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm)
{
	if (this != &shrubberyCreationForm)
	{
		this->sign = shrubberyCreationForm.getSign();
	}
	std::cout << "ShrubberyCreationForm : Copy assignment operator called" << std::endl;
	return *this;
}

std::string ShrubberyCreationForm::getName() const
{
	return this->name;
}

int ShrubberyCreationForm::getSignGrade() const
{
	return this->signGrade;
}

int ShrubberyCreationForm::getExecGrade() const
{
	return this->execGrade;
}


bool ShrubberyCreationForm::getSign() const
{
	return this->sign;
}

void ShrubberyCreationForm::beSigned(Bureaucrat &executor)
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

void ShrubberyCreationForm::createFile() const
{
	std::ofstream shrubberyFile;
	std::string fileName = this->target + "_shrubbery";
	shrubberyFile.open(fileName.c_str());
	if (!shrubberyFile.is_open())
		return ;
	(this->target + "_shrubbery");
	shrubberyFile << "    ###    " << std::endl;
	shrubberyFile << "   #o###   " << std::endl;
	shrubberyFile << " #####o### " << std::endl;
	shrubberyFile << "#o###|#/###" << std::endl; 
	shrubberyFile << " ####|/#o# " << std::endl;
	shrubberyFile << "  # }|{  # " << std::endl;
	shrubberyFile << "    }|{    " << std::endl;
	shrubberyFile.close();
}

int ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign() && !checkExecute(executor, this->getExecGrade()))
	{
		createFile();
		return 0;
	}
	return 1;
}