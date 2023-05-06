#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl is born." << std::endl;
};

Harl::~Harl(void)
{
	std::cout << "Harl is dead." << std::endl;
};

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl
		<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl
		<< "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl
		<< "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[Error]" << std::endl
		<< "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	static const std::string level_str[4] = {"debug", "info", "warning", "error"};

	void (Harl::*level_func[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int idx = 0; idx < 4; idx++)
	{
		if (level == level_str[idx])
		{
			(this->*level_func[idx])();
			return;
		}
	}

	std::cout << "Invalid level." << std::endl;
	
}
