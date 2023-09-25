#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
class Bureaucrat;

class Form
{
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

	private :
		const std::string name;
		bool sign;
		const int grade;

	public :
		Form();
        Form(std::string setName, int setGrade);
		~Form();
		Form(const Form &form);
		Form &operator=(const Form &form);

		std::string getName() const;
		int getGrade() const;
		bool getBeSigned() const;
		int checkGrade();
		void beSigned(Bureaucrat &bureaucrat);
};

#endif