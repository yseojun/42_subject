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
	int	idx;

	for (idx = 0; idx < 4; idx++)
	{
		if (level == level_str[idx])
			break ;
	}

	switch (idx)
	{
		case 0:
			debug();
			return ;
		case 1:
			info();
			return ;
		case 2:
			warning();
			return ;
		case 3:
			error();
			return ;
		default:
			std::cout << "Invalid level." << std::endl;
			break ;
	}

}
