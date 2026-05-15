#pragma once
#include "Animal.h"

class Hamster : public Animal
{
public:
    Hamster(const string& name = "NoName", const size_t& age = 0);
    ~Hamster();
    void sound() const override;
    void type() const override;
};