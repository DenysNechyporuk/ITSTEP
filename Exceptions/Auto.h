#pragma once
#include <iostream>
#include "AutoExceptions.h"
using namespace std;

class Auto
{
    string number;
    double maxSpeed;
    double currentSpeed;

    bool isValidNumber(const string& num) const
    {
        if (num.length() != 8)
            return false;
        for (int i = 0; i < 2; i++)
            if (!isalpha(num[i]))
                return false;
        for (int i = 2; i < 6; i++)
            if (!isdigit(num[i]))
                return false;
        for (int i = 6; i < 8; i++)
            if (!isalpha(num[i]))
                return false;
        return true;
    }

public:
    Auto(const string& number, double maxSpeed, double currentSpeed = 0)
        : number{ "" }, maxSpeed{ 0 }, currentSpeed{ 0 }
    {
        setNumber(number);
        setMaxSpeed(maxSpeed);
        setCurrentSpeed(currentSpeed);
    }

    void setNumber(const string& number)
    {
        if (!isValidNumber(number))
            throw InvalidNumberException("Invalid car number", 0);
        this->number = number;
    }

    void setMaxSpeed(double maxSpeed)
    {
        if (maxSpeed > 360)
            throw WrongMaxSpeedException("Max speed exceeds 360", maxSpeed);
        this->maxSpeed = maxSpeed;
    }

    void setCurrentSpeed(double currentSpeed)
    {
        if (currentSpeed > maxSpeed)
            throw WrongSpeedException("Speed exceeds maximum", currentSpeed);
        this->currentSpeed = currentSpeed;
    }

    string getNumber() const { return number; }
    double getMaxSpeed() const { return maxSpeed; }
    double getCurrentSpeed() const { return currentSpeed; }

    void accelerate(double delta = 5)
    {
        double newSpeed = currentSpeed + delta;
        if (newSpeed > maxSpeed)
            throw WrongSpeedException("Speed exceeds maximum", newSpeed);
        currentSpeed = newSpeed;
    }

    void decelerate(double delta = 5)
    {
        currentSpeed -= delta;
        if (currentSpeed < 0)
            currentSpeed = 0;
    }

    void display() const
    {
        cout << "Number :: " << number
            << " | Max speed :: " << maxSpeed
            << " | Current speed :: " << currentSpeed << endl;
    }
};