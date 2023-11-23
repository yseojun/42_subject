#include "Span.hpp"

int main(){ 
	{
		Span	test(10);

		test.addNumber(5);
		test.addNumber(3);
		test.addNumber(17);
		test.addNumber(9);
		test.addNumber(11);
		test.addNumber(1);
		test.addNumber(13);

		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl;

		std::vector<int>	v;
		Span				test2(10000);
		for (int i = 0; i < 10000; i++)
			v.push_back(i);
		test2.addNumber(v.begin(), v.end());
		std::cout << "Shortest span: " << test2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test2.longestSpan() << std::endl;
	}

}