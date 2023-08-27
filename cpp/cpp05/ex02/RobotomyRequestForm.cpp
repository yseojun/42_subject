#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomyrequest", false, 72, 45), target("default") {
	std::cout << "Robotomyrequestform default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomyrequest", false, 72, 45), target(target) {
	std::cout << "Robotomyrequestform paramatic constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Robotomyrequestform default destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
	: AForm(src), target(src.target){
	std::cout << "Robotomyrequestform copy constructor called" << std::endl;
};

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs){
	std::cout << "Robotomyrequestform assignment opertor called" << std::endl;
	if (this != &rhs)
	{
		this->target = rhs.target;
	}
	return *this;
};

void	RobotomyRequestForm::specialwork() const{
	std::srand(static_cast<unsigned int>(std::time(0)));

    int randomValue = std::rand();

	std::cout << "dddd..! dddd..!" << std::endl;

    if (randomValue % 2)
	{
        std::cout << this->target << " is successfully robotomized!" << std::endl;
    }
	else
	{
        std::cout << this->target << " is failed to robotomized..." << std::endl;
    }
};
