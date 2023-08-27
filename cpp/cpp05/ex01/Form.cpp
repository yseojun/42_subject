#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), signGrade(150), executeGrade(150){
	std::cout << "Form instructor called" << std::endl;
};

Form::~Form(){
	std::cout << "Form destructor called" << std::endl;
};

Form::Form(std::string name, bool sign, int signGrade, int executeGrade)
	: name(name), isSigned(sign), signGrade(signGrade), executeGrade(executeGrade){
	std::cout << "Form paramatic instructor called" << std::endl;
	try
	{
		if (signGrade < 1 || executeGrade < 1)
			throw Form::GradeTooHighException();
		else if (signGrade > 150 || executeGrade > 150)
			throw Form::GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
};

Form::Form(Form const &src)
	: name(src.name), isSigned(src.isSigned), signGrade(src.signGrade), executeGrade(src.executeGrade){
	std::cout << "Form copy constructor called" << std::endl;
};

Form &Form::operator=(Form const &rhs){
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->isSigned = rhs.isSigned;
	}
	return *this;
};

void	Form::beSigned(Bureaucrat man){
	if (this->getIsSigned() == true)
		throw "aleady signed!";
	if (this->getSignGrade() < man.getGrade())
		throw "Form's grade is higher than Bureaucrat!";
	this->isSigned = true;
	std::cout << man.getName() << " signed " << this->getName() << std::endl;
};

std::ostream& operator<<(std::ostream& os, const Form &rhs){
	os << rhs.getName() << ", Form is ";
	if (rhs.getIsSigned() == true)
		os << "signed. \n";
	else
		os << "not signed. \n";
	os << "Sign Grade : " << rhs.getSignGrade() << '\n';
	os << "Execute Grade : " << rhs.getExecuteGrade() << std::endl;
	return os;
};