#pragma once
#include "Shooter.h"

class Ranger : virtual public Shooter
{
protected:
    Ranger() {}

    void shoot() override
    {
        cout << "[Ranger] ";
        Shooter::shoot();
    }
};