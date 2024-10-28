#include "Fish.h"

Fish::Fish() : breed("Unknown"), color("Unknown"), foodType("Unknown") {
    std::cout << "Fish default constructor called." << std::endl;
}

Fish::Fish(const std::string& breed, const std::string& color, const std::string& foodType)
    : breed(breed), color(color), foodType(foodType) {
    std::cout << "Fish parameterized constructor called." << std::endl;
}

Fish::Fish(const Fish& other) : breed(other.breed), color(other.color), foodType(other.foodType) {
    std::cout << "Fish copy constructor called." << std::endl;
}

Fish::~Fish() {
    std::cout << "Fish destructor called." << std::endl;
}

void Fish::display() const {
    std::cout << "Fish: Breed: " << breed << ", Color: " << color << ", Food Type: " << foodType << std::endl;
}

void Fish::save(std::ofstream& out) const {
    out << "Fish\n" << breed << "\n" << color << "\n" << foodType << "\n";
}

void Fish::load(std::ifstream& in) {
    std::getline(in, breed);
    std::getline(in, color);
    std::getline(in, foodType);
}

void Fish::setBreed(const std::string& breed) { this->breed = breed; }
void Fish::setColor(const std::string& color) { this->color = color; }
void Fish::setFoodType(const std::string& foodType) { this->foodType = foodType; }
std::string Fish::getBreed() const { return breed; }
std::string Fish::getColor() const { return color; }
std::string Fish::getFoodType() const { return foodType; }
