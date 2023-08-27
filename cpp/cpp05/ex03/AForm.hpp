#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	class GradeTooLowException : public std::exception
	{
		private:
			std::string	errorMessage;
		public:
			GradeTooLowException() : errorMessage("Grade is too Low") {};
			virtual ~GradeTooLowException() throw() {};

			virtual const char *what() const throw() {
				return errorMessage.c_str();
			}
	};

	class GradeTooHighException : public std::exception
	{
		private:
			std::string	errorMessage;
		public:
			GradeTooHighException() : errorMessage("Grade is too Low") {};
			virtual ~GradeTooHighException() throw() {};

			virtual const char *what() const throw() {
				return errorMessage.c_str();
			}
	};

	protected:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			executeGrade;

	public:
		AForm();
		virtual ~AForm();
		AForm(std::string name, bool sign, int signGrade, int executeGrade);
		AForm(AForm const &src);
		AForm &operator=(AForm const &rhs);

		std::string getName() const { return this->name; };
		bool		getIsSigned() const { return this->isSigned; };
		int			getSignGrade() const { return this->signGrade; };
		int			getExecuteGrade() const { return this->executeGrade; };

		void	beSigned(Bureaucrat man);

		void execute(Bureaucrat const & executor) const;
		virtual void specialwork() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm &rhs);

#endif