#include "Bird.h"

Bird::Bird() : breed("Unknown"), color("Unknown"), foodType("Unknown"), habitat("Unknown") {
    std::cout << "Bird default constructor called." << std::endl;
}

Bird::Bird(const std::string& breed, const std::string& color, const std::string& foodType, const std::string& habitat)
    : breed(breed), color(color), foodType(foodType), habitat(habitat) {
    std::cout << "Bird parameterized constructor called." << std::endl;
}

Bird::Bird(const Bird& other) : breed(other.breed), color(other.color), foodType(other.foodType), habitat(other.habitat) {
    std::cout << "Bird copy constructor called." << std::endl;
}

Bird::~Bird() {
    std::cout << "Bird destructor called." << std::endl;
}

void Bird::display() const {
    std::cout << "Bird: Breed: " << breed << ", Color: " << color << ", Food Type: " << foodType << ", Habitat: " << habitat << std::endl;
}

void Bird::save(std::ofstream& out) const {
    out << "Bird\n" << breed << "\n" << color << "\n" << foodType << "\n" << habitat << "\n";
}

void Bird::load(std::ifstream& in) {
    std::getline(in, breed);
    std::getline(in, color);
    std::getline(in, foodType);
    std::getline(in, habitat);
}

void Bird::edit(){
    std::string newinfo;
    int choice = -1;
    std::cout<<"1. Edit breed\n2. Edit color\n3. Edit food type\n4. Edit habitat\nenter what to edit:\n";
    std::cin>>choice;
    std::cout<<"type what you want to change it to"<<std::endl;
    std::cin>>newinfo;
    if (choice == 1){
        setBreed(newinfo);
    } else if (choice == 2){
        setColor(newinfo);
    } else if (choice == 3){
        setFoodType(newinfo);
    } else if (choice == 4){
        setHabitat(newinfo);
    } else {
        std::cout<<"wrong choice, returning to menu"<<std::endl;
    }
}

void Bird::setBreed(const std::string& breed) { this->breed = breed; }
void Bird::setColor(const std::string& color) { this->color = color; }
void Bird::setFoodType(const std::string& foodType) { this->foodType = foodType; }
void Bird::setHabitat(const std::string& habitat) { this->habitat = habitat; }
std::string Bird::getBreed() const { return breed; }
std::string Bird::getColor() const { return color; }
std::string Bird::getFoodType() const { return foodType; }
std::string Bird::getHabitat() const { return habitat; }
