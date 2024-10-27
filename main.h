#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "keeper.h"
#include "fish.h"

class Base {
public:
    virtual ~Base() = default;
    virtual void save(std::ofstream &ofs) const = 0;
    virtual void load(std::ifstream &ifs) = 0;
    virtual std::string getInfo() const = 0;
};