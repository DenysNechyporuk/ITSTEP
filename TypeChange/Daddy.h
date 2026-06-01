#pragma once
#include "Grandpa.h"

class Daddy : public Grandpa
{
public:
    void Sleep() const override
    {
        cout << "Daddy is sleeping" << endl;
    }
    virtual void Walk() const
    {
        cout << "Daddy is walking" << endl;
    }
};