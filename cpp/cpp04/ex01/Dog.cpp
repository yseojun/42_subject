#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
    std::cout << "Dog default constructor called" << std::endl;
    this->brain->ideas[0] = "Bone! Bone!";
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*(copy.brain));
}

Dog &Dog::operator=(const Dog &copy) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &copy) {
        Animal::operator=(copy); // 부모 클래스의 대입 연산자 호출
        *this->brain = *(copy.brain); // Brain 객체의 대입 연산자 사용
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

std::string Dog::getIdea(int i) const {
    return this->brain->ideas[i];
}

void Dog::setIdea(int i, std::string idea) {
    this->brain->ideas[i] = idea;
}
