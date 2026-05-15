#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List<int> list;
	for (size_t i = 0; i < 3; i++)
	{
		list.addHead(rand() % 10 + 1);
		list.print();
	}
	list.printR();
	for (size_t i = 0; i < 3; i++)
	{
		list.addTail(rand() % 10 + 1);
		list.print();
	}
	list.printR();

	/*cout << "Remove all :: " << endl;
	while (!list.isEmpty())
	{
		list.removeHead();
		list.print();
		list.printR();
	}*/
	list.removeData(1);
	list.print();
	list.printR();

	cout << "--- removeTail ---" << endl;
	list.removeTail();
	list.print();
	list.printR();

	cout << "--- copy ctor ---" << endl;
	List<int> list2(list);
	list2.print();
	list2.printR();

	cout << "--- operator= ---" << endl;
	List<int> list3;
	list3 = list;
	list3.print();
	list3.printR();

	cout << "--- dtor test ---" << endl;
	{
		List<int> listTemp;
		listTemp.addHead(99);
		listTemp.addHead(88);
		listTemp.print();
	}

	cout << "--- delByIndex ---" << endl;
	list.delByIndex(0);
	list.print();
	list.delByIndex(1);
	list.print();

	cout << "--- insByIndex ---" << endl;
	list.insByIndex(0, 100);
	list.print();
	list.insByIndex(2, 200);
	list.print();

	cout << "--- operator[] ---" << endl;
	cout << "list[0] = " << list[0] << endl;
	cout << "list[1] = " << list[1] << endl;

	cout << "--- clear ---" << endl;
	list.clear();
	list.print();
}
