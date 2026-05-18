#include <iostream>
#include "Queue.h"
using namespace std;

void main()
{
    Queue<int> q;
    cout << "isEmpty :: " <<boolalpha<< q.isEmpty() << endl;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.print();

    cout << "getItem :: " << q.getItem() << endl;
    cout << "getN    :: " << q.getN() << endl;

    cout << "pop     :: " << q.pop() << endl;
    q.print();

    cout << "pop     :: " << q.pop() << endl;
    q.print();

    Queue<int> q2 = q;
    q2.push(99);
    cout << "q2 :: ";
    q2.print();

    Queue<int> q3;
    q3 = q2;
    cout << "q3 :: ";
    q3.print();

    q.clear();
    cout << "isEmpty after clear :: " << boolalpha << q.isEmpty() << endl;
}