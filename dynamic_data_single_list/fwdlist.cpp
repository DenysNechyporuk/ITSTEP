#include <iostream>
#include "fwdlist.h"
using namespace std;

void main() {
	fwdlist<int> list;
	list.print();
	for (size_t i = 0; i < 3; i++)
	{
		list.addHead(i * 10);
		list.print();
	}
	cout << endl << "_____________Removing head_____________"<<endl;
	while (!list.isEmpty()) {
		list.removeHead();
		list.print();
	}
	cout << "Add again :: " << endl;
	list.addHead(100);
	list.addHead(200);
	list.addHead(300);
	list.print();

	list.clear();
	list.print();
}