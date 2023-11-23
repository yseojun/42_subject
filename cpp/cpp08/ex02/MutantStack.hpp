#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack() : std::stack<T>(){};
		MutantStack(MutantStack &src) : std::stack<T>(src){};
		MutantStack &operator=(MutantStack &rhs){
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return *this;
		};
		~MutantStack(){};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(){
			return std::stack<T>::c.begin();
		};
		iterator	end(){
			return std::stack<T>::c.end();
		};
};

#endif