#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <vector>
# include <list>
# include <deque>
# include <iostream>

template <typename T>
typename T::iterator	easyfind(T& container, int to_find){
	typename T::iterator iter;
	iter = std::find(container.begin(), container.end(), to_find);
	if (iter == container.end())
		throw (std::runtime_error("Error. Not found."));
	return iter;
}

#endif