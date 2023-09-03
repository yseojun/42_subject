#include "ScalarConverter.hpp"

std::string ScalarConverter::_input = "";
bool ScalarConverter::isValid = false;
double ScalarConverter::raw = 0;
double ScalarConverter::integralPart = 0;
double ScalarConverter::fractionalPart = 0;

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
    _input = src._input;
    isValid = src.isValid;
    raw = src.raw;
    integralPart = src.integralPart;
    fractionalPart = src.fractionalPart;
};

ScalarConverter	& ScalarConverter::operator=(ScalarConverter const & rhs){
    if (this != &rhs)
    {
        this->_input = rhs._input;
        this->isValid = rhs.isValid;
        this->raw = rhs.raw;
        this->integralPart = rhs.integralPart;
        this->fractionalPart = rhs.fractionalPart;
    }
    return *this;
};

void	ScalarConverter::convert(std::string const & literal){
    _input = literal;
    isValid = chkIsValid();
    if (isValid) {
        raw = strtod(_input.c_str(), 0);
        fractionalPart = std::modf(raw, &integralPart);
    }
    else {
        raw = 0; fractionalPart = 0; integralPart = 0;
    }
	displayChar();
	displayInt();
	displayFloat();
	displayDouble();
}

bool ScalarConverter::chkIsValid() {
    if (_input.empty() || _input == "-" || _input == "+") {
        return false;
    }

    bool isDecimalPoints = false;
    bool isSign = false;

    std::string::iterator it;
    for (it = _input.begin(); it != _input.end(); it++) {
        char c = *it;

        if (c == '.') {
            if (isDecimalPoints || it == _input.begin() || it == _input.end()) { // .으로 시작, 여러 개
                return false;
            }
            isDecimalPoints = true;
        } else if (c == '-' || c == '+') {
            if (it != _input.begin() || isSign) { // +,- 가 처음이 아님, 여러 개
                return false;
            }
            isSign = true;
        } else if (it == _input.begin() && c == '0'
                    && _input.size() > 1 && *(it + 1) != '.') { // 0으로 시작, 0뿐이 아님
            return false;
        } else if (!isdigit(c)) {
            if (!IsSpecialStr(it))
                return false;
            break ;
        }
    }
    return true;
}

bool    ScalarConverter::IsSpecialStr(std::string::iterator it) {
    if (it + 1 == _input.end() && *it == 'f') { // 마지막 문자가 f일 때는 보호
        _input.pop_back();

        if (_input.empty())
            return false;
        else if (_input.size() == 1
            && (*_input.begin() == '+' || *_input.begin() == '-' || *_input.begin() == '.')) // .f, +f, -f 예외처리
            return false;
        else
            return true;
    }
    else if (_input == "nan" || _input == "nanf" || _input == "+inf" || _input == "-inf"
        || _input == "+inff" || _input == "-inff") {
        return true;
    }
    return false ;
}

void	ScalarConverter::displayChar(){
	std::cout << "char: ";
	try {
		if (isValid == false || fractionalPart)
			throw std::runtime_error("impossible");

        if (raw < std::numeric_limits< char >::min()
            || std::numeric_limits< char >::max() < raw)
            throw std::runtime_error("overflow");

        char  output = static_cast< char > (raw);

        if (!isprint(output))
            throw std::runtime_error("Non displayable");
    
        std::cout << "'" << output << "'" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

void	ScalarConverter::displayInt(){
	std::cout << "int: ";
	try {
		if (isValid == false || fractionalPart)
			throw std::runtime_error("impossible");

        if (raw < std::numeric_limits< int >::min()
            || std::numeric_limits< int >::max() < raw)
            throw std::runtime_error("overflow");

        int    output = static_cast< int > (raw);
        std::cout << output << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

void	ScalarConverter::displayFloat(){
	std::cout << "float: ";
	try {
		if (isValid == false)
			throw std::runtime_error("impossible");

        if (_input == "+inf" || _input == "-inf"
            || _input == "+inff" || _input == "-inff")
            raw = (_input == "+inf" || _input == "+inff") ? HUGE_VAL : -HUGE_VAL;
        else if (raw < std::numeric_limits< float >::lowest()
            || std::numeric_limits< float >::max() < raw)
            throw std::runtime_error("overflow");

        float  output = static_cast< float > (raw);
        if (fractionalPart || isnan(output) || isinf(output))
            std::cout << output << 'f' << std::endl;
        else
            std::cout << output << ".0f" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

void	ScalarConverter::displayDouble(){
	std::cout << "double: ";
	try {
		if (isValid == false)
			throw std::runtime_error("impossible");

        if (_input == "+inf" || _input == "-inf"
            || _input == "+inff" || _input == "-inff")
            raw = (_input == "+inf" || _input == "+inff") ? HUGE_VAL : -HUGE_VAL;
        else if (raw < std::numeric_limits< double >::lowest()
            || std::numeric_limits< double >::max() < raw)
            throw std::runtime_error("overflow");

        double   output = static_cast< double > (raw);
        if (fractionalPart || isnan(output) || isinf(output))
            std::cout << output << std::endl;
        else
            std::cout << output << ".0" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}
