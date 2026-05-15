#include "Circle.h"

const double PI = 3.14;

Circle::Circle(double radius)
{
    this->radius = radius;
}

void Circle::setRadius(double radius)
{
    this->radius = radius;
}

double Circle::getRadius() const
{
    return radius;
}

double Circle::square() const
{
    return PI * radius * radius;
}

double Circle::length() const
{
    return 2 * PI * radius;
}