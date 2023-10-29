#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
class Bureaucrat;

class Form
{
	private :
		const std::string name;
		bool sign;
		const int signGrade;
		const int execGrade;

	public :
		Form();
        Form(std::string setName, int setSignGrade, int setExecGrade);
		~Form();
		Form(const Form &form);
		Form &operator=(const Form &form);

		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getSign() const;
		void checkGrade();
		void beSigned(Bureaucrat &bureaucrat);

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
};

#endif