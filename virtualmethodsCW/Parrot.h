#pragma once
#include "Animal.h"

class Parrot : public Animal
{
public:
    Parrot(const string& name = "NoName", const size_t& age = 0);
    ~Parrot();
    void sound() const override;
    void type() const override;
};