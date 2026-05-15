#include "Parrot.h"

Parrot::Parrot(const string& name, const size_t& age)
    : Animal(name, age)
{
    cout << ">>>>> Ctor Parrot Id --> " << id << endl;
}

Parrot::~Parrot()
{
    cout << ">>>>> Dtor Parrot Id --> " << id << endl;
}

void Parrot::sound() const
{
    cout << "Sound :: Hello!" << endl;
}

void Parrot::type() const
{
    cout << "Type  :: Parrot" << endl;
}