#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), signGrade(150), executeGrade(150){
	std::cout << "Form instructor called" << std::endl;
};

AForm::~AForm(){
	std::cout << "Form destructor called" << std::endl;
};

AForm::AForm(std::string name, bool sign, int signGrade, int executeGrade)
	: name(name), isSigned(sign), signGrade(signGrade), executeGrade(executeGrade){
	std::cout << "Form paramatic instructor called" << std::endl;
	try
	{
		if (signGrade < 1 || executeGrade < 1)
			throw AForm::GradeTooHighException();
		else if (signGrade > 150 || executeGrade > 150)
			throw AForm::GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
};

AForm::AForm(AForm const &src)
	: name(src.name), isSigned(src.isSigned), signGrade(src.signGrade), executeGrade(src.executeGrade){
	std::cout << "Form copy constructor called" << std::endl;
};

AForm &AForm::operator=(AForm const &rhs){
	std::cout << "Form assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->isSigned = rhs.isSigned;
	}
	return *this;
};

void	AForm::beSigned(Bureaucrat man){
	if (this->getIsSigned() == true)
		throw "aleady signed!";
	if (this->getSignGrade() < man.getGrade())
		throw "Form's grade is higher than Bureaucrat!";
	this->isSigned = true;
	std::cout << man.getName() << " signed " << this->getName() << std::endl;
};

std::ostream& operator<<(std::ostream& os, const AForm &rhs){
	os << rhs.getName() << ", Form is ";
	if (rhs.getIsSigned() == true)
		os << "signed. \n";
	else
		os << "not signed. \n";
	os << "Sign Grade : " << rhs.getSignGrade() << '\n';
	os << "Execute Grade : " << rhs.getExecuteGrade() << std::endl;
	return os;
};

void AForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false)
		throw "form is not signed.";
	if (this->getExecuteGrade() < executor.getGrade())
		throw "executor's grade is lower than form.";
	this->specialwork();
};
