#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		const std::string name;
		bool sign;
		const int signGrade;
		const int execGrade;
		std::string target;

	public :
		PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &presidentialPardonForm);

		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getSign() const;
		void beSigned(Bureaucrat &bureaucrat);

		int execute(Bureaucrat const & executor) const;
};

#endif