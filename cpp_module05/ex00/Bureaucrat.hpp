#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
	class GradeTooHighException : public std::exception
	{
		
	};

	class GradeTooLowException : public std::exception
	{};

	private :
		std::string const name;
		unsigned int grade;
	
	public :
		Bureaucrat();
        Bureaucrat(std::string const &name);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);

		void getName();
		void getGrade();
		void incrementGrade();
		void decrementGrade();

};


#endif