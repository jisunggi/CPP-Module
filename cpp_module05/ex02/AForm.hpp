#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
class Bureaucrat;

class AForm
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

	protected :
		const std::string name;
		bool sign;
		const int grade;

	public :
		AForm();
        AForm(std::string setName, int setGrade);
		virtual ~AForm();
		AForm(const AForm &aform);
		AForm &operator=(const AForm &aform);

		std::string getName() const;
		int getGrade() const;
		bool getBeSigned() const;
		int checkGrade();
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

#endif