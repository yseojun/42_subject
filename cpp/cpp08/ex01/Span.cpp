#include "Span.hpp"

Span::Span()
	:_data(0,0)  {
};

Span::Span(Span &src)
	:_data(0,0){
	_data.reserve(src._data.capacity());
	_data = src._data;
};

Span::Span(unsigned int N)
	:_data(0,0) {
	_data.reserve(N);
};

Span &Span::operator=(Span &rhs){
	if (this != &rhs)
	{
		_data.reserve(rhs._data.capacity());
		rhs._data = _data;
	}
	return *this;
};

Span::~Span(){

};

void	Span::addNumber(int n){
	if (_data.size() == _data.capacity())
		throw std::runtime_error("Insufficient size to add.");
	_data.push_back(n);
};

unsigned int Span::shortestSpan(){
	if (_data.size() <= 1)
		throw std::runtime_error("No span can be found.");

	std::vector<int>	tmp = _data;
	std::sort(tmp.begin(), tmp.end());

	unsigned int min = std::abs(tmp[0] - tmp[1]);
	for (size_t i = 1; i < tmp.size(); i++){
		unsigned int diff = std::abs(tmp[i] - tmp[i + 1]);
		if (diff < min)
			min = diff;
	}

	return min;
};

unsigned int Span::longestSpan(){
	if (_data.size() <= 1)
		throw std::runtime_error("No span can be found.");

	std::vector<int>	tmp = _data;
	std::sort(tmp.begin(), tmp.end());

	return tmp[tmp.size() - 1] - tmp[0];
};

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	if (static_cast<std::vector<int>::size_type>(std::distance(begin, end)) > _data.capacity())
		throw std::runtime_error("Insufficient size to add.");
	_data.insert(_data.end(), begin, end);
};