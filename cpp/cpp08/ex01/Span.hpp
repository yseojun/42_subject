#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>

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

};

#endif