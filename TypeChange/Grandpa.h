#pragma once
#include <iostream>
using namespace std;

class Grandpa
{
public:
    virtual void Sleep() const
    {
        cout << "Grandpa Ivan is sleeping" << endl;
    }
    virtual ~Grandpa() {}
};