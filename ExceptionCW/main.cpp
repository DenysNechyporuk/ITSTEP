#include <iostream>
#include "Rectangle.h"
using namespace std;

void tryCreate(double w, double l)
{
    try
    {
        Rectangle r(w, l);
        r.display();
    }
    catch (NegativeWidthException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << " :: bad value = " << ex.getBadSide() << endl;
    }
    catch (NegativeLengthException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << " :: bad value = " << ex.getBadSide() << endl;
    }
    catch (ZeroWidthException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << " :: bad value = " << ex.getBadSide() << endl;
    }
    catch (ZeroLengthException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << " :: bad value = " << ex.getBadSide() << endl;
    }
    catch (MyException ex)
    {
        cout << ex.what() << " :: bad value = " << ex.getBadSide() << endl;
    }
    catch (...)
    {
        cout << "Run default catch" << endl;
    }
}

void main()
{
    tryCreate(5.5, 3.2);
    tryCreate(-2.0, 3.0);
    tryCreate(4.0, -1.5);
    tryCreate(0.0, 3.0);
    tryCreate(3.0, 0.0);

}