#include "MutantStack.hpp"

int main()
{ 
	std::cout << "---iterator---" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::stack<int> s(mstack); 
	}
	
	{
		std::cout << std::endl;
		std::list<int>	lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3); lst.push_back(5); lst.push_back(737); //[...] lst.push_back(0);
		std::list<int>::iterator it = lst.begin(); std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::list<int> s(lst);
	}

	std::cout << "---reverse_iterator---" << std::endl;
	{
		std::cout << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
		MutantStack<int>::reverse_iterator it = mstack.rbegin(); MutantStack<int>::reverse_iterator ite = mstack.rend();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::stack<int> s(mstack); 
	}
	
	{
		std::cout << std::endl;
		std::list<int>	lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3); lst.push_back(5); lst.push_back(737); //[...] lst.push_back(0);
		std::list<int>::reverse_iterator it = lst.rbegin(); std::list<int>::reverse_iterator ite = lst.rend();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::list<int> s(lst);
	}
	
	std::cout << "---const_iterator---" << std::endl;
	{
		std::cout << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
		MutantStack<int>::const_iterator it = mstack.cbegin(); MutantStack<int>::const_iterator ite = mstack.cend();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::stack<int> s(mstack);
	}

	{
		std::cout << std::endl;
		std::list<int>	lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3); lst.push_back(5); lst.push_back(737); //[...] lst.push_back(0);
		std::list<int>::const_iterator it = lst.cbegin(); std::list<int>::const_iterator ite = lst.cend();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::list<int> s(lst);
	}
	
	std::cout << "---const_reverse_iterator---" << std::endl;
	{
		std::cout << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
		MutantStack<int>::const_reverse_iterator it = mstack.crbegin(); MutantStack<int>::const_reverse_iterator ite = mstack.crend();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::stack<int> s(mstack);
	}

	{
		std::cout << std::endl;
		std::list<int>	lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3); lst.push_back(5); lst.push_back(737); //[...] lst.push_back(0);
		std::list<int>::const_reverse_iterator it = lst.crbegin(); std::list<int>::const_reverse_iterator ite = lst.crend();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::list<int> s(lst);
	}
	
	return 0;
}