#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cmath>

class ScalarConverter
{
	private:
		static std::string		_input;
		static bool				isValid;
		static double			raw;
		static double			integralPart;
		static double			fractionalPart;

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter	& operator=(ScalarConverter const & rhs);

	public:
		static void	convert(std::string const & literal);

		static bool	chkIsValid();
		static bool	IsSpecialStr(std::string::iterator it);
		
		static void	displayChar();
		static void	displayInt();
		static void	displayDouble();
		static void	displayFloat();

};

#endif