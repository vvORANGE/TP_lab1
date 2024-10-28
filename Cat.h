#ifndef CAT_H
#define CAT_H

#include "Base.h"
#include <iostream>
#include <fstream>

class Cat : public Base {
private:
    std::string breed;
    std::string color;
    std::string ownerName;
    std::string nickname;

public:
    Cat();
    Cat(const std::string& breed, const std::string& color, const std::string& ownerName, const std::string& nickname);
    Cat(const Cat& other);
    ~Cat();

    void display() const override;
    void save(std::ofstream& out) const override; // Метод для сохранения
    void load(std::ifstream& in) override; // Метод для загрузки
    void edit();

    // Setters and getters
    void setBreed(const std::string& breed);
    void setColor(const std::string& color);
    void setOwnerName(const std::string& ownerName);
    void setNickname(const std::string& nickname);
    std::string getBreed() const;
    std::string getColor() const;
    std::string getOwnerName() const;
    std::string getNickname() const;
};

#endif // CAT_H
