#pragma once

class Square
{
protected:
    double side;
public:
    Square(double side = 1.0);
    void setSide(double side);
    double getSide() const;
    double square() const;
    double length() const;
};