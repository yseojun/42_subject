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
	std::cout << "Debug" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Info" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Warning" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "Error" << std::endl;
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
