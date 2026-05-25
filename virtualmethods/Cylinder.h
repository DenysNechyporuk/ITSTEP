#pragma once
#include "Circle.h"

class Cylinder : public Circle
{
    double height;

public:
    Cylinder(double x = 0, double y = 0, double radius = 0, double height = 0)
        : Circle(x, y, radius), height{ height } {
    }

    double area() const override
    {
        return 2 * 3.14159 * radius * (radius + height);
    }

    double volume() const override
    {
        return 3.14159 * radius * radius * height;
    }

    void printShapeName() const override
    {
        cout << "Cylinder" << endl;
    }

    void print() const override
    {
        cout << "Cylinder :: center (" << x << ", " << y << ") | radius = " << radius << " | height = " << height << endl;
    }
};