#ifndef BIRD_H
#define BIRD_H

#include "Base.h"
#include <iostream>

class Bird : public Base {
private:
    std::string breed;
    std::string color;
    std::string foodType;
    std::string habitat;

public:
    Bird();
    Bird(const std::string& breed, const std::string& color, const std::string& foodType, const std::string& habitat);
    Bird(const Bird& other);
    ~Bird();

    void display() const override;

    // Setters and getters
    void setBreed(const std::string& breed);
    void setColor(const std::string& color);
    void setFoodType(const std::string& foodType);
    void setHabitat(const std::string& habitat);
    std::string getBreed() const;
    std::string getColor() const;
    std::string getFoodType() const;
    std::string getHabitat() const;
};

#endif // BIRD_H
