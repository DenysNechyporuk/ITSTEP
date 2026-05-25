#pragma once
#include "Point.h"

class Circle : public Point
{
protected:
    double radius;

public:
    Circle(double x = 0, double y = 0, double radius = 0)
        : Point(x, y), radius{ radius } {
    }

    double volume() const override { return 0.0; }

    double area() const override
    {
        return 3.14159 * radius * radius;
    }

    void printShapeName() const override
    {
        cout << "Circle" << endl;
    }

    void print() const override
    {
        cout << "Circle :: center (" << x << ", " << y << ") | radius = " << radius << endl;
    }
};