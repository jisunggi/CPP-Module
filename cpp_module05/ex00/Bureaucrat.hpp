#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
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
		int grade;
	
	public :
		Bureaucrat();
        Bureaucrat(std::string setName, int setGrade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void checkGrade();
};

#endif