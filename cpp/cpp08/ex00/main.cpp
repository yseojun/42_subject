#include "easyfind.hpp"

int main(){
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;

	for (int i = 0; i < 5; i++){
		v.push_back(i);
		d.push_back(i);
		l.push_back(i);
	}

	try
	{
		std::vector<int>::iterator iter;
		iter = easyfind(v, 2);
		std::cout << "found index: "
			<< std::distance(v.begin(), iter) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::deque<int>::iterator iter;
		iter = easyfind(d, 1);
		std::cout << "found index: "
			<< std::distance(d.begin(), iter) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator iter;
		iter = easyfind(l, 4);
		std::cout << "found index: "
			<< std::distance(l.begin(), iter) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator iter;
		iter = easyfind(l, 8);
		std::cout << "found index: "
			<< std::distance(l.begin(), iter) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
