#pragma once
#include "Animal.h"

class Cat : public Animal
{
public:
    Cat(const string& name = "NoName", const size_t& age = 0);
    ~Cat();
    void sound() const override;
    void type() const override;
};