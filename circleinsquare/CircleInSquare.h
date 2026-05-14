#pragma once
#include "Circle.h"
#include "Square.h"

class CircleInSquare : public Circle, public Square
{
public:
    CircleInSquare(double radius = 1.0);
    void setRadius(double radius);
    void setSide(double side);
    double totalLength() const;
    double partSquare() const;
};