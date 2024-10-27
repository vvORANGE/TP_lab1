#include "Cat.h"

Cat::Cat() : breed("Unknown"), color("Unknown"), ownerName("Unknown"), nickname("Unknown") {
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& nickname)
    : breed(breed), color(color), ownerName(ownerName), nickname(nickname) {
    std::cout << "Cat parameterized constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : breed(other.breed), color(other.color), ownerName(other.ownerName), nickname(other.nickname) {
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::display() const {
    std::cout << "Cat: Breed: " << breed << ", Color: " << color << ", Owner: " << ownerName << ", Nickname: " << nickname << std::endl;
}

void Cat::setBreed(const std::string& breed) { this->breed = breed; }
void Cat::setColor(const std::string& color) { this->color = color; }
void Cat::setOwnerName(const std::string& ownerName) { this->ownerName = ownerName; }
void Cat::setNickname(const std::string& nickname) { this->nickname = nickname; }
std::string Cat::getBreed() const { return breed; }
std::string Cat::getColor() const { return color; }
std::string Cat::getOwnerName() const { return ownerName; }
std::string Cat::getNickname() const { return nickname; }
