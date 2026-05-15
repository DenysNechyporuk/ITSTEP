#pragma once
#include <iostream>
using namespace std;

class Pet {
protected:
    string name;
    string characteristics;
public:
    Pet(string name, string characteristics);
    void display();
};