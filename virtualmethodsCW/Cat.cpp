#include "Cat.h"

Cat::Cat(const string& name, const size_t& age)
    : Animal(name, age)
{
    cout << ">>>>> Ctor Cat Id --> " << id << endl;
}

Cat::~Cat()
{
    cout << ">>>>> Dtor Cat Id --> " << id << endl;
}

void Cat::sound() const
{
    cout << "Sound :: Meow" << endl;
}

void Cat::type() const
{
    cout << "Type  :: Cat" << endl;
}