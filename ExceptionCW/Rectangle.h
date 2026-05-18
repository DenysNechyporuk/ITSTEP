#pragma once
#include <iostream>
#include "Exceptions.h"
using namespace std;

class Rectangle
{
    double width;
    double length;
public:
    Rectangle(const double& width, const double& length)
        : width{ 0 }, length{ 0 }
    {
        setWidth(width);
        setLength(length);
    }
    void setWidth(const double& width)
    {
        if (width < 0)
            throw NegativeWidthException("Width is negative", width);
        if (width == 0)
            throw ZeroWidthException("Width is zero", width);
        this->width = width;
    }
    void setLength(const double& length)
    {
        if (length < 0)
            throw NegativeLengthException("Length is negative", length);
        if (length == 0)
            throw ZeroLengthException("Length is zero", length);
        this->length = length;
    }
    void display() const
    {
        cout << "Rectangle :: width = " << width << ", length = " << length << endl;
    }
};