#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

struct Data {
	int value;
};

class Serializer{
	private:
		Serializer() {};
		~Serializer() {};
		Serializer(Serializer const & src) { src.deserialize(0); };
		Serializer &operator=(Serializer const & rhs) { rhs.deserialize(0); return *this; };

	public: 
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif