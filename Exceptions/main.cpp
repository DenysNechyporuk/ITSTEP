#include <iostream>
#include "Auto.h"
using namespace std;

void main()
{
    try
    {
        Auto car("AB1234CD", 200, 0);
        car.display();

        cout << "Accelerating 3 times..." << endl;
        car.accelerate();
        car.accelerate();
        car.accelerate();
        car.display();

        cout << "Decelerating..." << endl;
        car.decelerate();
        car.display();
    }
    catch (WrongSpeedException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << " :: bad value = " << ex.getBadValue() << endl;
    }
    catch (WrongMaxSpeedException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << " :: bad value = " << ex.getBadValue() << endl;
    }
    catch (InvalidNumberException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << endl;
    }
    catch (MyException ex)
    {
        cout << ex.what() << " :: bad value = " << ex.getBadValue() << endl;
    }

    cout << endl;


    try
    {
        Auto car("INVALID1", 200);
        car.display();
    }
    catch (WrongSpeedException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << " :: bad value = " << ex.getBadValue() << endl;
    }
    catch (WrongMaxSpeedException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << " :: bad value = " << ex.getBadValue() << endl;
    }
    catch (InvalidNumberException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << endl;
    }
    catch (MyException ex)
    {
        cout << ex.what() << " :: bad value = " << ex.getBadValue() << endl;
    }

    cout << endl;

    try
    {
        Auto car("AB1234CD", 400);
        car.display();
    }
    catch (WrongSpeedException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << " :: bad value = " << ex.getBadValue() << endl;
    }
    catch (WrongMaxSpeedException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << " :: bad value = " << ex.getBadValue() << endl;
    }
    catch (InvalidNumberException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << endl;
    }
    catch (MyException ex)
    {
        cout << ex.what() << " :: bad value = " << ex.getBadValue() << endl;
    }

    cout << endl;


    try
    {
        Auto car("AB1234CD", 200);
        car.accelerate(250);
        car.display();
    }
    catch (WrongSpeedException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << " :: bad value = " << ex.getBadValue() << endl;
    }
    catch (WrongMaxSpeedException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << " :: bad value = " << ex.getBadValue() << endl;
    }
    catch (InvalidNumberException ex)
    {
        cout << "Exception " << typeid(ex).name() << " was caught" << endl;
        cout << ex.what() << endl;
    }
    catch (MyException ex)
    {
        cout << ex.what() << " :: bad value = " << ex.getBadValue() << endl;
    }
}