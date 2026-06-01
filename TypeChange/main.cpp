#include <iostream>
#include "Son.h"
using namespace std;

void callAllDynamicCast(Grandpa* arr[], int size)
{
    cout << "=== dynamic_cast ===" << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i]->Sleep();

        Daddy* d = dynamic_cast<Daddy*>(arr[i]);
        if (d != nullptr)
            d->Walk();

        Son* s = dynamic_cast<Son*>(arr[i]);
        if (s != nullptr)
            s->Play();

        cout << endl;
    }
}

void callAllTypeid(Grandpa* arr[], int size)
{
    cout << "=== typeid + static_cast ===" << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i]->Sleep();

        if (typeid(*arr[i]) == typeid(Daddy) || typeid(*arr[i]) == typeid(Son))
        {
            Daddy* d = static_cast<Daddy*>(arr[i]);
            d->Walk();
        }

        if (typeid(*arr[i]) == typeid(Son))
        {
            Son* s = static_cast<Son*>(arr[i]);
            s->Play();
        }

        cout << endl;
    }
}

void main()
{
    Grandpa* arr[3];
    arr[0] = new Grandpa();
    arr[1] = new Daddy();
    arr[2] = new Son();

    callAllDynamicCast(arr, 3);
    callAllTypeid(arr, 3);

    for (int i = 0; i < 3; i++)
        delete arr[i];

}