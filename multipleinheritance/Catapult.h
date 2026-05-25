#pragma once
#include "Shooter.h"

class Catapult : virtual public Shooter
{
protected:
    Catapult() {}

    void shoot() override
    {
        cout << "[Catapult] ";
        Shooter::shoot();
    }
};