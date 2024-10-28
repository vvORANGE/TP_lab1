#ifndef FISH_H
#define FISH_H

#include "Base.h"
#include <iostream>
#include <fstream>

class Fish : public Base {
private:
    std::string breed;
    std::string color;
    std::string foodType;

public:
    Fish();
    Fish(const std::string& breed, const std::string& color, const std::string& foodType);
    Fish(const Fish& other);
    ~Fish();

    void display() const override;
    void save(std::ofstream& out) const override; // Метод для сохранения
    void load(std::ifstream& in) override; // Метод для загрузки
    void edit();
    
    // Setters and getters
    void setBreed(const std::string& breed);
    void setColor(const std::string& color);
    void setFoodType(const std::string& foodType);
    std::string getBreed() const;
    std::string getColor() const;
    std::string getFoodType() const;
};

#endif // FISH_H
