#include "Square.h"

Square::Square(double side)
{
    this->side = side;
}

void Square::setSide(double side)
{
    this->side = side;
}

double Square::getSide() const
{
    return side;
}

double Square::square() const
{
    return side * side;
}

double Square::length() const
{
    return 4 * side;
}