#pragma once
#include "ArcherTower.h"
#include "Catapult.h"

class Fortress : protected ArcherTower, protected Catapult
{
    int wallThickness;
    int gateCondition;
    int garrison;

protected:
    void shoot() override
    {
        ArcherTower::shoot();
    }

public:
    Fortress(int wallThickness, int gateCondition, int garrison)
        : wallThickness{ wallThickness },
        gateCondition{ gateCondition },
        garrison{ garrison }
    {
        giveAmmo("Arrow", 4);
        Catapult::giveAmmo("Stone", 10);
    }

    void fireArcher()
    {
        shootArcher();
    }

    void fireRanger()
    {
        shootRanger();
    }

    void fireCatapult()
    {
        Catapult::shoot();
    }

    void displayStatus() const
    {
        cout << "=== Fortress Status ===" << endl;
        cout << "Wall thickness :: " << wallThickness << " m" << endl;
        cout << "Gate condition :: " << gateCondition << " %" << endl;
        cout << "Garrison :: " << garrison << " soldiers" << endl;
        cout << "Arrows left :: " << getAmmoCount() << endl;
        cout << "=======================" << endl;
    }
};