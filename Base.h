#ifndef BASE_H
#define BASE_H

#include <string>

class Base {
public:
    virtual ~Base() {}
    virtual void display() const = 0; // Чисто виртуальная функция для отображения информации
    virtual void save(std::ofstream& out) const = 0; // Сохранение объекта
    virtual void load(std::ifstream& in) = 0; // Загрузка объекта
    virtual void edit () = 0; // Редактирование объекта
};

#endif // BASE_H
