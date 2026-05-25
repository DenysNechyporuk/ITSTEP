#pragma once
#include "Shape.h"

class Point : public Shape
{
protected:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0) : x{ x }, y{ y } {}

    double area() const override { return 0.0; }
    double volume() const override { return 0.0; }

    void printShapeName() const override
    {
        cout << "Point" << endl;
    }

    void print() const override
    {
        cout << "Point :: (" << x << ", " << y << ")" << endl;
    }
};