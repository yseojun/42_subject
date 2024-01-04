#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class Span {
	private:
		std::vector<int> _data;
		Span(void);

	public:
		explicit Span(std::size_t n);
		Span& operator=(const Span& rhs);
		Span(const Span& src);
		~Span(void);
		const std::vector<int>& getData(void) const;

		void addNumber(int value);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		std::size_t shortestSpan(void);
		std::size_t longestSpan(void);
};

#endif