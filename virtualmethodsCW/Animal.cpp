#include "Animal.h"

size_t Animal::lastId = 0;

void Animal::setName(const string& name)
{
    if (!name.empty())
        this->name = name;
}

void Animal::setAge(const size_t& age)
{
    this->age = age;
}

const string& Animal::getName() const
{
    return this->name;
}

const size_t& Animal::getAge() const
{
    return this->age;
}

void Animal::show() const
{
    cout << "Animal ID   :: " << id << endl;
    cout << "Name        :: " << name << endl;
    cout << "Age         :: " << age << endl;
    type();
    sound();
}

Animal::Animal(const string& name, const size_t& age)
{
    setName(name);
    setAge(age);
    id = ++lastId;
    cout << ">>>>> Ctor Animal Id --> " << id << endl;
}

Animal::~Animal()
{
    cout << ">>>>> Dtor Animal Id --> " << id << endl;
}