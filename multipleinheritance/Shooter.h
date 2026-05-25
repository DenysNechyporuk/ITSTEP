#pragma once
#include <iostream>
using namespace std;

class Shooter
{
    string ammoName;
    int ammoCount;

protected:
    Shooter() : ammoName{ "none" }, ammoCount{ 0 } {}

    virtual void shoot()
    {
        if (ammoCount <= 0)
        {
            cout << "No ammo left!" << endl;
            return;
        }
        ammoCount--;
        cout << "Shot with :: " << ammoName << " | Ammo left :: " << ammoCount << endl;
    }

    void giveAmmo(const string& name, int count)
    {
        ammoName = name;
        ammoCount = count;
    }

    string getAmmoName() const { return ammoName; }
    int getAmmoCount() const { return ammoCount; }
};