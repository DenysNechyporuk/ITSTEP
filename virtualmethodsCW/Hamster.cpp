#include "Hamster.h"

Hamster::Hamster(const string& name, const size_t& age)
    : Animal(name, age)
{
    cout << ">>>>> Ctor Hamster Id --> " << id << endl;
}

Hamster::~Hamster()
{
    cout << ">>>>> Dtor Hamster Id --> " << id << endl;
}

void Hamster::sound() const
{
    cout << "Sound :: Squeak" << endl;
}

void Hamster::type() const
{
    cout << "Type  :: Hamster" << endl;
}