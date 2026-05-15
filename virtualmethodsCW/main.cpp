#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"
#include "Hamster.h"
using namespace std;

void main()
{
    Animal* arr[] = {
        new Cat("Murka", 2),
        new Dog("Rex", 5),
        new Parrot("Kesha", 3),
        new Hamster("Pufik", 1)
    };

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "------- show() -------" << endl;
    for (int i = 0; i < size; i++)
        arr[i]->show();

    cout << "------- sound() ------" << endl;
    for (int i = 0; i < size; i++)
        arr[i]->sound();

    cout << "------- type() -------" << endl;
    for (int i = 0; i < size; i++)
        arr[i]->type();

    cout << "------- delete -------" << endl;
    for (int i = 0; i < size; i++)
        delete arr[i];

}