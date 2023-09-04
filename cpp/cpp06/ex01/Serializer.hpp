#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

struct Data {
	int value;
};

class Serializer{
	private:
		Serializer();
		~Serializer();
		Serializer(Serializer const & src);
		Serializer &operator=(Serializer const & rhs);

	public: 
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif