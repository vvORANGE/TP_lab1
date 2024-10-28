#include <iostream>
#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

int main() {
    Keeper keeper;
    int choice;

    do {
        std::cout << "1. Add Fish\n2. Add Bird\n3. Add Cat\n4. Remove Animal\n5. Edit Animal\n6. Display Animals\n7. Save to File\n8. Load from File\n0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string breed, color, foodType;
                std::cout << "Enter breed, color, food type: ";
                std::cin >> breed >> color >> foodType;
                keeper.addAnimal(new Fish(breed, color, foodType));
                break;
            }
            case 2: {
                std::string breed, color, foodType, habitat;
                std::cout << "Enter breed, color, food type, habitat: ";
                std::cin >> breed >> color >> foodType >> habitat;
                keeper.addAnimal(new Bird(breed, color, foodType, habitat));
                break;
            }
            case 3: {
                std::string breed, color, ownerName, nickname;
                std::cout << "Enter breed, color, owner name, nickname: ";
                std::cin >> breed >> color >> ownerName >> nickname;
                keeper.addAnimal(new Cat(breed, color, ownerName, nickname));
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                try {
                    keeper.removeAnimal(index);
                } catch (const std::out_of_range& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 5:{
                int index;
                std::cout << "Enter index to edit: ";
                std::cin >> index;
                try {
                    keeper.editAnimal(index);
                } catch (const std::out_of_range& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 6:
                keeper.displayAnimals();
                break;
            case 7: {
                std::string filename;
                std::cout << "Enter filename to save: ";
                std::cin >> filename;
                try {
                    keeper.saveToFile(filename);
                } catch (const std::runtime_error& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 8: {
                std::string filename;
                std::cout << "Enter filename to load: ";
                std::cin >> filename;
                try {
                    keeper.loadFromFile(filename);
                } catch (const std::runtime_error& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
