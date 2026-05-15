#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
    Dog(const string& name = "NoName", const size_t& age = 0);
    ~Dog();
    void sound() const override;
    void type() const override;
};