#pragma once
#include "IDevice.h"

class TV : public IDevice
{
    bool isOn;
    int volume;
    int channel;
    int maxVolume;
    int maxChannels;

public:
    TV(int maxVolume = 100, int maxChannels = 200)
        : isOn{ false }, volume{ 10 }, channel{ 1 },
        maxVolume{ maxVolume }, maxChannels{ maxChannels }
    {
    }

    void power() override
    {
        isOn = !isOn;
        cout << "TV :: " << (isOn ? "ON" : "OFF") << endl;
    }

    void plus() override
    {
        if (!isOn) { cout << "TV is off" << endl; return; }
        if (volume >= maxVolume) { cout << "TV :: Max volume reached" << endl; return; }
        volume++;
        cout << "TV :: Volume = " << volume << endl;
    }

    void minus() override
    {
        if (!isOn) { cout << "TV is off" << endl; return; }
        if (volume <= 0) { cout << "TV :: Min volume reached" << endl; return; }
        volume--;
        cout << "TV :: Volume = " << volume << endl;
    }

    void next() override
    {
        if (!isOn) { cout << "TV is off" << endl; return; }
        if (channel >= maxChannels) { cout << "TV :: Last channel" << endl; return; }
        channel++;
        cout << "TV :: Channel = " << channel << endl;
    }

    void prev() override
    {
        if (!isOn) { cout << "TV is off" << endl; return; }
        if (channel <= 1) { cout << "TV :: First channel" << endl; return; }
        channel--;
        cout << "TV :: Channel = " << channel << endl;
    }

    void showInfo() const override
    {
        cout << "TV :: " << (isOn ? "ON" : "OFF")
            << " | Channel = " << channel
            << " | Volume = " << volume << endl;
    }
};