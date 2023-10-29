#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class AForm
{
	private :
		const std::string name;
		bool sign;
		const int signGrade;
		const int execGrade;

	public :
		AForm();
        AForm(std::string setName);
		virtual ~AForm();
		AForm(const AForm &aform);
		AForm &operator=(const AForm &aform);

		virtual std::string getName() const;
		virtual int getSignGrade() const;
		virtual int getExecGrade() const;
		virtual bool getSign() const;
		virtual void beSigned(Bureaucrat &executor);

		virtual int execute(Bureaucrat const &executor) const = 0;
		int checkExecute(Bureaucrat const &executor, int formExecGrade) const;

		class AlreadySigned : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class NoExecuteException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

};

#endif