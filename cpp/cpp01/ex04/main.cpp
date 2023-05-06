#include <iostream>
#include <fstream>

int main(int ac, char **av) {

	if (ac != 4)
		return (0);

	std::string filename = av[1];	
	std::string to_find = av[2];
	std::string to_replace = av[3];

	std::fstream file(filename.c_str(), std::ios::in);
	if (!file.is_open())
	{
		std::cerr << "Failed to open file: " << filename << std::endl;
		return 1;
	}	

	std::ofstream outfile(filename + ".replace");
	if (!outfile.is_open())
	{
		std::cerr << "Failed to open file: " << filename << ".replace" << std::endl;
		return 1;
	}

	std::string	line;
	std::string	output;
	while (std::getline(file, line))
	{
		size_t pos = line.find(to_find);
		while (pos != std::string::npos) 
		{
			output += line.substr(0, pos) + to_replace;
			line.erase(0, pos + to_find.length());
			pos = line.find(to_find);
		}
		output += line + "\n";
	}
	file.close();

	outfile << output;
	outfile.close();

	return 0;
}
