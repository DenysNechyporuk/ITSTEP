#include <iostream>
#include "List.h"
using namespace std;

void printFromHead(Node<int>* head)
{
    Node<int>* curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}


void main()
{
    List<int> l1;
    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(3);
    l1.pushBack(4);
    cout << "l1 :: ";
    l1.print();

    List<int> l2;
    l2.pushBack(3);
    l2.pushBack(4);
    l2.pushBack(5);
    l2.pushBack(6);
    cout << "l2 :: ";
    l2.print();

    Node<int>* cloned = l1.clone();
    cout << "clone l1 :: ";
    printFromHead(cloned);

    Node<int>* joined = l1 + l2;
    cout << "l1 + l2  :: ";
    printFromHead(joined);

    Node<int>* common = l1 * l2;
    cout << "l1 * l2  :: ";
    printFromHead(common);

}