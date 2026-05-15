#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    Array<int> arr(5, 5);
    cout << "IsEmpty :: " << arr.IsEmpty() << endl;

    arr.Add(10);
    arr.Add(20);
    arr.Add(30);
    arr.Print(); 

    arr.SetAt(1, 99);
    arr.Print(); 

    cout << "GetAt(0) :: " << arr.GetAt(0) << endl;
    cout << "GetUpperBound :: " << arr.GetUpperBound() << endl;
    cout << "GetSize :: " << arr.GetSize() << endl;

    arr.FreeExtra();
    arr.Print(); 

    arr.InsertAt(1, 55);
    arr.Print(); 

    arr.RemoveAt(2);
    arr.Print(); 

    Array<int> arr2;
    arr2.Add(100);
    arr2.Add(200);
    arr.Append(arr2);
    arr.Print(); 

    Array<int> arr3 = arr;
    arr3.Print();

    arr.RemoveAll();
    cout << "IsEmpty :: " << arr.IsEmpty() << endl;

    Array<double> dArr(2, 2);
    dArr.Add(1.1);
    dArr.Add(2.2);
    dArr.Add(3.3);
    dArr.Print();

}