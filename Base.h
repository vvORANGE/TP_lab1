#ifndef BASE_H
#define BASE_H

#include <string>

class Base {
public:
    virtual ~Base() {}
    virtual void display() const = 0; // Чисто виртуальная функция для отображения информации
};

#endif // BASE_H
