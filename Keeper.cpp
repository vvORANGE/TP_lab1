#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

Keeper::Keeper() : animals(nullptr), size(0) {}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }
    delete[] animals;
}

void Keeper::addAnimal(Base* animal) {
    Base** newAnimals = new Base*[size + 1];
    for (int i = 0; i < size; ++i) {
        newAnimals[i] = animals[i];
    }
    newAnimals[size] = animal;
    delete[] animals;
    animals = newAnimals;
    size++;
}

void Keeper::removeAnimal(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range.");
    }
    Base** newAnimals = new Base*[size - 1];
    for (int i = 0, j = 0; i < size; ++i) {
        if (i != index) {
            newAnimals[j++] = animals[i];
        } else {
            delete animals[i]; // удаляем удаляемый объект
        }
    }
    delete[] animals;
    animals = newAnimals;
    size--;
}

void Keeper::displayAnimals() const {
    for (int i = 0; i < size; ++i) {
        animals[i]->display();
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::out);
    if (!outFile) {
        throw std::runtime_error("Could not open file for writing.");
    }
    outFile << size << "\n"; // Сохраняем количество объектов
    for (int i = 0; i < size; ++i) {
        animals[i]->save(outFile); // Сохраняем каждый объект
    }
    outFile.close();
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::in);
    if (!inFile) {
        throw std::runtime_error("Could not open file for reading.");
    }
    for (int i = 0; i < size; i++){
        removeAnimal(i);
    }
    inFile >> size;
    inFile.ignore(); // Игнорируем символ новой строки после числа
    animals = new Base*[size];
    for (int i = 0; i < size; ++i) {
        std::string type;
        std::getline(inFile, type);
        if (type == "Fish") {
            animals[i] = new Fish();
        } else if (type == "Bird") {
            animals[i] = new Bird();
        } else if (type == "Cat") {
            animals[i] = new Cat();
        }
        animals[i]->load(inFile); // Загружаем каждую сущность
    }
    inFile.close();
}
