#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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

	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			executeGrade;

	public:
		Form();
		~Form();
		Form(std::string name, bool sign, int signGrade, int executeGrade);
		Form(Form const &src);
		Form &operator=(Form const &rhs);

		std::string getName() const { return this->name; };
		bool		getIsSigned() const { return this->isSigned; };
		int			getSignGrade() const { return this->signGrade; };
		int			getExecuteGrade() const { return this->executeGrade; };

		void	beSigned(Bureaucrat man);
};

std::ostream& operator<<(std::ostream& os, const Form &rhs);

#endif