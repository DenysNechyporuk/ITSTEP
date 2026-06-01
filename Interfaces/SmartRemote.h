#pragma once
#include "IDevice.h"

class SmartRemote
{
    IDevice* current;

public:
    SmartRemote(IDevice* device = nullptr) : current{ device } {}

    void setDevice(IDevice* device)
    {
        current = device;
        cout << "SmartRemote :: Device changed" << endl;
    }

    void showCurrentDevice() const
    {
        if (current == nullptr) { cout << "SmartRemote :: No device" << endl; return; }
        current->showInfo();
    }

    void power() { if (current) current->power(); }
    void plus() { if (current) current->plus(); }
    void minus() { if (current) current->minus(); }
    void next() { if (current) current->next(); }
    void prev() { if (current) current->prev(); }
};