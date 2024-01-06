#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	BitcoinExchange b;
	std::fstream file(argv[1], std::ios::in);
	if (!file.is_open()){
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
}
