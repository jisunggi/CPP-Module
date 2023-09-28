#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		const std::string name;
		bool sign;
		const int signGrade;
		const int execGrade;
		std::string target;

	public :
		ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubberyCreationForm);

		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getSign() const;
		void beSigned(Bureaucrat &bureaucrat);

		int execute(Bureaucrat const & executor) const;
		void createFile() const;
};

#endif