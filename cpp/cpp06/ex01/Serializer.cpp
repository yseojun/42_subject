#include "Serializer.hpp"

Serializer::Serializer() {};

Serializer::~Serializer() {};

Serializer::Serializer(Serializer const & src) { 
	src.deserialize(0); 
};

Serializer &Serializer::operator=(Serializer const & rhs) { 
	rhs.deserialize(0); 
	return *this; 
};

static uintptr_t	serialize(Data *ptr){
	return reinterpret_cast< uintptr_t > (ptr);
};

static Data*		deserialize(uintptr_t raw){
	return reinterpret_cast< Data* > (raw);
};
