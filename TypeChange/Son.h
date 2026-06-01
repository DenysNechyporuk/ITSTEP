#pragma once
#include "Daddy.h"

class Son : public Daddy
{
public:
    void Sleep() const override
    {
        cout << "Son is sleeping" << endl;
    }
    void Walk() const override
    {
        cout << "Son is walking" << endl;
    }
    virtual void Play() const
    {
        cout << "Son is playing" << endl;
    }
};