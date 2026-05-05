#include <iostream>
#include "drib.h"
using std::cout;
using std::endl;

int main()
{
	Fraction f1(1, 2);
	Fraction f2(1, 3);

	f1.print();
	f2.print();

	Fraction f3 = f1 + f2;
	cout << "f1 + f2 :: "; f3.print();

	Fraction f4 = f1 - f2;
	cout << "f1 - f2 :: "; f4.print();

	Fraction f5 = f1 * f2;
	cout << "f1 * f2 :: "; f5.print();

	Fraction f6 = f1 / f2;
	cout << "f1 / f2 :: "; f6.print();

	Fraction f7(3, 4);
	++f7;
	cout << "++f7 :: "; f7.print();
	f7++;
	cout << "f7++ :: "; f7.print();

	Fraction f8(3, 4);
	--f8;
	cout << "--f8 :: "; f8.print();
	f8--;
	cout << "f8-- :: "; f8.print();

	Fraction f9(1, -2);
	cout << "1 / -2 :: "; f9.print();

	cout << "f1 == f2 :: " << (f1 == f2) << endl;
	cout << "f1 != f2 :: " << (f1 != f2) << endl;
	cout << "f1 > f2 :: " << (f1 > f2) << endl;
	cout << "f1 < f2 :: " << (f1 < f2) << endl;

	return 0;
}