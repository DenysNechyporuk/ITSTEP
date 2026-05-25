#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

void main()
{
    DoublyLinkedList<int> list;

    cout << "AddToTail :: 1 2 3 4 5" << endl;
    list.AddToTail(1);
    list.AddToTail(2);
    list.AddToTail(3);
    list.AddToTail(4);
    list.AddToTail(5);
    list.Show();

    cout << "AddToHead :: 0" << endl;
    list.AddToHead(0);
    list.Show();

    cout << "DeleteFromHead" << endl;
    list.DeleteFromHead();
    list.Show();

    cout << "DeleteFromTail" << endl;
    list.DeleteFromTail();
    list.Show();

    cout << "InsertAt position 2 :: value 99" << endl;
    list.InsertAt(2, 99);
    list.Show();

    cout << "DeleteAt position 2" << endl;
    list.DeleteAt(2);
    list.Show();

    cout << "Find :: 3" << endl;
    auto node = list.Find(3);
    if (node != nullptr)
        cout << "Found :: " << node->data << endl;
    else
        cout << "Not found" << endl;

    cout << "Find :: 999" << endl;
    node = list.Find(999);
    if (node != nullptr)
        cout << "Found :: " << node->data << endl;
    else
        cout << "Not found :: NULL" << endl;

    cout << "AddToTail :: 3 (duplicate)" << endl;
    list.AddToTail(3);
    list.Show();

    cout << "FindAndReplace :: 3 -> 33" << endl;
    int replaced = list.FindAndReplace(3, 33);
    if (replaced != -1)
        cout << "Replaced :: " << replaced << " elements" << endl;
    else
        cout << "Not found :: -1" << endl;
    list.Show();

    cout << "Reverse" << endl;
    list.Reverse();
    list.Show();

    cout << "DeleteAll" << endl;
    list.DeleteAll();
    list.Show();

}