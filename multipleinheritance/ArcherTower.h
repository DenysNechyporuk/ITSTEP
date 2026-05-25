#pragma once
#include "Archer.h"
#include "Ranger.h"

class ArcherTower : protected Archer, protected Ranger
{
protected:
    ArcherTower() {}

    void shoot() override
    {
        Archer::shoot();
    }

    void shootArcher()
    {
        Archer::shoot();
    }

    void shootRanger()
    {
        Ranger::shoot();
    }
};