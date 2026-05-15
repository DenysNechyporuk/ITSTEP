#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Animal abstract
{
public:
    void setName(const string& name);
    void setAge(const size_t& age);
    const string& getName() const;
    const size_t& getAge() const;
    virtual void sound() const = 0;
    virtual void type() const = 0;
    virtual void show() const;
    Animal(const string& name = "NoName", const size_t& age = 0);
    virtual ~Animal();
private:
    string name;
    size_t age;
    static size_t lastId;
protected:
    size_t id;
};