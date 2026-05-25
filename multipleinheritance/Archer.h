#pragma once
#include "Shooter.h"

class Archer : virtual public Shooter
{
protected:
    Archer() {}

    void shoot() override
    {
        cout << "[Archer] ";
        Shooter::shoot();
    }
};