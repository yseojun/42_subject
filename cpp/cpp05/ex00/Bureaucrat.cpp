#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"),grade(150){
	std::cout << "Bureaucrat default constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(std::string const & name, int grade) : name(name){
	std::cout << "Bureaucrat parametric constructor called" << std::endl;
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->grade = grade;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
};

Bureaucrat::Bureaucrat(Bureaucrat const & src) : name(src.name), grade(src.grade){
	std::cout << "Bureaucrat copy constructor called" << std::endl;
};

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor called" << std::endl;
};

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs){
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->grade = rhs.grade;
	}
	return *this;
};

Bureaucrat	&Bureaucrat::operator++(){
	try
	{
		if (this->grade > 1)
			this->grade--;
		else
			throw Bureaucrat::GradeTooHighException();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (*this);
};

Bureaucrat	&Bureaucrat::operator--(){
	try
	{
		if (this->grade < 150)
			this->grade++;
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (*this);
};

Bureaucrat	Bureaucrat::operator++(int){
	Bureaucrat tmp(*this);
	operator++();
	return (tmp);
};

Bureaucrat	Bureaucrat::operator--(int){
	Bureaucrat tmp(*this);
	operator--();
	return (tmp);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &rhs){
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".\n";
	return os;
};
