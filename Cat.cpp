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

void Cat::save(std::ofstream& out) const {
    out << "Cat\n" << breed << "\n" << color << "\n" << ownerName << "\n" << nickname << "\n";
}

void Cat::load(std::ifstream& in) {
    std::getline(in, breed);
    std::getline(in, color);
    std::getline(in, ownerName);
    std::getline(in, nickname);
}

void Cat::edit(){
    std::string newinfo;
    int choice = -1;
    std::cout<<"1. Edit breed\n2. Edit color\n3. Edit owner name\n4. Edit nickname\nenter what to edit:\n";
    std::cin>>choice;
    std::cout<<"type what you want to change it to"<<std::endl;
    std::cin>>newinfo;
    if (choice == 1){
        setBreed(newinfo);
    } else if (choice == 2){
        setColor(newinfo);
    } else if (choice == 3){
        setOwnerName(newinfo);
    } else if (choice == 4){
        setNickname(newinfo);
    } else {
        std::cout<<"wrong choice, returning to menu"<<std::endl;
    }
}

void Cat::setBreed(const std::string& breed) { this->breed = breed; }
void Cat::setColor(const std::string& color) { this->color = color; }
void Cat::setOwnerName(const std::string& ownerName) { this->ownerName = ownerName; }
void Cat::setNickname(const std::string& nickname) { this->nickname = nickname; }
std::string Cat::getBreed() const { return breed; }
std::string Cat::getColor() const { return color; }
std::string Cat::getOwnerName() const { return ownerName; }
std::string Cat::getNickname() const { return nickname; }
