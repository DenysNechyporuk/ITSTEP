#include "Dog.h"

Dog::Dog(const string& name, const size_t& age)
    : Animal(name, age)
{
    cout << ">>>>> Ctor Dog Id --> " << id << endl;
}

Dog::~Dog()
{
    cout << ">>>>> Dtor Dog Id --> " << id << endl;
}

void Dog::sound() const
{
    cout << "Sound :: Woof" << endl;
}

void Dog::type() const
{
    cout << "Type  :: Dog" << endl;
}