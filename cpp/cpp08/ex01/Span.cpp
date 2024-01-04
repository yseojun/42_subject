#include "Span.hpp"

Span::Span(void)
	: _data(0, 0) {
	_data.reserve(0);
}

Span::Span(std::size_t n)
	: _data(0, 0) {
	_data.reserve(n);
}

Span::Span(const Span& src)
	: _data(0, 0) {
	_data.reserve(src.getData().capacity());
	std::copy(std::begin(src.getData()),
			std::end(src.getData()),
			std::back_inserter(_data));
}

Span& Span::operator=(const Span& rhs) {
	if (_data.capacity() != rhs.getData().capacity())
		return *this;
	if (this != &rhs) {
		_data.clear();
		_data.reserve(rhs.getData().capacity());
		std::copy(std::begin(rhs.getData()),
					std::end(rhs.getData()),
					std::back_inserter(_data));
	}
	return *this;
}

Span::~Span(void) { }

const std::vector<int>& Span::getData(void) const {
	return _data;
}

void  Span::addNumber(int value) {
	if (_data.size() == _data.capacity())
		throw std::runtime_error("Cannot store more data");
	_data.push_back(value);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	if (static_cast<std::vector<int>::size_type>(std::distance(begin, end)) > _data.capacity())
		throw std::runtime_error("Insufficient size to add.");
	_data.insert(_data.end(), begin, end);
};

std::size_t Span::shortestSpan(void) {
	if (_data.size() <= 1)
		throw std::runtime_error("No span found.");

	std::vector<int>	tmp = _data;
	std::sort(tmp.begin(), tmp.end());

	std::size_t min = std::abs(tmp[0] - tmp[1]);
	for (size_t i = 1; i < tmp.size(); i++){
		std::size_t diff = std::abs(tmp[i] - tmp[i + 1]);
		if (diff < min)
			min = diff;
	}

	return min;
}

std::size_t Span::longestSpan(void) {
	if (_data.size() < 2)
		throw std::runtime_error("No span found");
	
	return *std::max_element(_data.begin(), _data.end()) - *std::min_element(_data.begin(), _data.end());
}
