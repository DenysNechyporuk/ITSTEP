#include <iostream>
#include "Fortress.h"
using namespace std;

void main()
{
    Fortress fortress(3, 100, 50);

    fortress.displayStatus();

    cout << endl << "--- Archer fires 3 times ---" << endl;
    fortress.fireArcher();
    fortress.fireArcher();
    fortress.fireArcher();

    cout << endl << "--- Ranger fires 2 times ---" << endl;
    fortress.fireRanger();
    fortress.fireRanger();

    cout << endl << "--- Catapult fires ---" << endl;
    fortress.fireCatapult();

    cout << endl;
    fortress.displayStatus();

}