#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	class GradeTooHighException : public std::exception
	{
		private:
			std::string	errorMessage;
		public:
			GradeTooHighException() : errorMessage("Grade is too High!") {};
			virtual ~GradeTooHighException() throw() {};

			virtual	const char *what() const throw() { // 예외를 던지지 않음
				return errorMessage.c_str();
			};
	};

	class GradeTooLowException : public std::exception
	{
		private:
			std::string	errorMessage;
		public:
			GradeTooLowException() : errorMessage("Grade is too Low!") {};
			virtual ~GradeTooLowException() throw() {};

			virtual	const char *what() const throw(){
				return errorMessage.c_str();
			};
	};

	private:
		const std::string	name;
		int	grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &rhs);
		Bureaucrat &operator++();
		Bureaucrat &operator--();
		Bureaucrat operator++(int);
		Bureaucrat operator--(int);
	
		std::string	getName() const{
			return name;
		}
		int getGrade() const{
			return grade;
		};

		void	signForm(AForm &form);

		void	executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &rhs);

#endif