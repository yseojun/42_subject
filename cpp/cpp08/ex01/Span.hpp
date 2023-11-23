#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Span {
	private:
		std::vector<int>	_data;

	public:
		Span();
		Span(Span &src);
		Span(unsigned int N);
		Span &operator=(Span &rhs);
		~Span();

		void	addNumber(int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif