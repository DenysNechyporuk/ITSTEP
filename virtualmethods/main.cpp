#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Cylinder.h"
using namespace std;

void main()
{
    Shape* shapes[3];
    shapes[0] = new Point(1, 2);
    shapes[1] = new Circle(0, 0, 5);
    shapes[2] = new Cylinder(0, 0, 3, 10);

    for (int i = 0; i < 3; i++)
    {
        shapes[i]->printShapeName();
        shapes[i]->print();
        cout << "Area   :: " << shapes[i]->area() << endl;
        cout << "Volume :: " << shapes[i]->volume() << endl;
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
        delete shapes[i];

}