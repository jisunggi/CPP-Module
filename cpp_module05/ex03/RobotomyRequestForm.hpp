#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private :
		const std::string name;
		bool sign;
		const int signGrade;
		const int execGrade;
		std::string target;

	public :
		RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyRequestForm);

		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getSign() const;
		void beSigned(Bureaucrat &bureaucrat);

		int execute(Bureaucrat const & executor) const;
		void randomNumber() const;
};

#endif