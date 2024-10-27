#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"
#include <iostream>
#include <fstream>

class Keeper {
private:
    Base** animals; // массив указателей на базовые объекты
    int size;

public:
    Keeper();
    ~Keeper();

    void addAnimal(Base* animal);
    void removeAnimal(int index);
    void displayAnimals() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif // KEEPER_H
