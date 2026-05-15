#include "CircleInSquare.h"

CircleInSquare::CircleInSquare(double radius)
    : Circle(radius), Square(radius * 2)
{
}

void CircleInSquare::setRadius(double radius)
{
    Circle::setRadius(radius);
    Square::setSide(radius * 2);
}

void CircleInSquare::setSide(double side)
{
    Square::setSide(side);
    Circle::setRadius(side / 2);
}

double CircleInSquare::totalLength() const
{
    return Circle::length() + Square::length();
}

double CircleInSquare::partSquare() const
{
    return Square::square() - Circle::square();
}