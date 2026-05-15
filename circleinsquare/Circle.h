#pragma once

class Circle
{
protected:
    double radius;
public:
    Circle(double radius = 1.0);
    void setRadius(double radius);
    double getRadius() const;
    double square() const;
    double length() const;
};