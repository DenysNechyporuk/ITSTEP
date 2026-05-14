#include <iostream>
#include "Circle.h"
#include "Square.h"
#include "CircleInSquare.h"
using namespace std;

void main()
{
    Circle c(5.0);
    cout << "Circle ::" << endl;
    cout << "  radius :: " << c.getRadius() << endl;
    cout << "  square :: " << c.square() << endl;
    cout << "  length :: " << c.length() << endl;

    Square s(4.0);
    cout << "Square :: " << endl;
    cout << "  side   :: " << s.getSide() << endl;
    cout << "  square :: " << s.square() << endl;
    cout << "  length :: " << s.length() << endl;

    CircleInSquare cis(3.0);
    cout << "CircleInSquare (radius = 3) ::" << endl;
    cout << "  radius      :: " << cis.getRadius() << endl;
    cout << "  side        :: " << cis.getSide() << endl;
    cout << "  totalLength :: " << cis.totalLength() << endl;
    cout << "  partSquare  :: " << cis.partSquare() << endl;

    cis.setSide(10.0);
    cout << "After setSide(10) ::" << endl;
    cout << "  radius      :: " << cis.getRadius() << endl;
    cout << "  side        :: " << cis.getSide() << endl;
    cout << "  totalLength :: " << cis.totalLength() << endl;
    cout << "  partSquare  :: " << cis.partSquare() << endl;
}