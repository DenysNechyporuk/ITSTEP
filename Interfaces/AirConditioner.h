#pragma once
#include "IDevice.h"

class AirConditioner : public IDevice
{
public:
    enum Mode { HEAT, COOL, TURBO, SLEEP };

private:
    bool isOn;
    int temperature;
    Mode mode;
    int minTemp;
    int maxTemp;

    string modeName(Mode m) const
    {
        if (m == HEAT)  return "Heat";
        if (m == COOL)  return "Cool";
        if (m == TURBO) return "Turbo";
        return "Sleep";
    }

public:
    AirConditioner(int minTemp = 16, int maxTemp = 25)
        : isOn{ false }, temperature{ 20 }, mode{ COOL },
        minTemp{ minTemp }, maxTemp{ maxTemp }
    {
    }

    void power() override
    {
        isOn = !isOn;
        cout << "AirConditioner :: " << (isOn ? "ON" : "OFF") << endl;
    }

    void plus() override
    {
        if (!isOn) { cout << "AirConditioner is off" << endl; return; }
        if (temperature >= maxTemp) { cout << "AirConditioner :: Max temp reached" << endl; return; }
        temperature++;
        cout << "AirConditioner :: Temperature = " << temperature << endl;
    }

    void minus() override
    {
        if (!isOn) { cout << "AirConditioner is off" << endl; return; }
        if (temperature <= minTemp) { cout << "AirConditioner :: Min temp reached" << endl; return; }
        temperature--;
        cout << "AirConditioner :: Temperature = " << temperature << endl;
    }

    void next() override
    {
        if (!isOn) { cout << "AirConditioner is off" << endl; return; }
        mode = static_cast<Mode>((mode + 1) % 4);
        cout << "AirConditioner :: Mode = " << modeName(mode) << endl;
    }

    void prev() override
    {
        if (!isOn) { cout << "AirConditioner is off" << endl; return; }
        mode = static_cast<Mode>((mode + 3) % 4);
        cout << "AirConditioner :: Mode = " << modeName(mode) << endl;
    }

    void showInfo() const override
    {
        cout << "AirConditioner :: " << (isOn ? "ON" : "OFF")
            << " | Temp = " << temperature
            << " | Mode = " << modeName(mode) << endl;
    }
};