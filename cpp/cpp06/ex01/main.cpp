#include "Serializer.hpp"

int main() {
	{
		Data data;
		data.value = 42;

		uintptr_t serializedPtr = Serializer::serialize(&data);
		Data* deserializedPtr = Serializer::deserialize(serializedPtr);

		std::cout << "Original value: " << data.value << std::endl;
		std::cout << "Deserialized value: " << deserializedPtr->value << std::endl;

		if (&data == deserializedPtr) {
			std::cout << "Pointers match!" << std::endl;
		} else {
			std::cout << "Pointers don't match!" << std::endl;
		}
	}

    return 0;
}
