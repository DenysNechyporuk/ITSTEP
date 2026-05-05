#include <iostream>
#include "String.h"
using std::cout;
using std::cin;
using std::endl;

void main()
{
	String s1("Microsoft");
	String s2("Windows");

	String s3 = s1 * s2;
	cout << "intersect :: "; s3.print();

	String s4 = s1 / s2;
	cout << "difference :: "; s4.print();

	String s5 = s1 + s2;
	cout << "concat :: "; s5.print();

	String s6 = s1 + "Windows";
	cout << "concat char* :: "; s6.print();

	String s7 = "asdfg" + s1;
	cout << "char* + String :: "; s7.print();

	String s8("Abcd");
	++s8;
	cout << "++s8 :: "; s8.print();

	String s9("Abcd");
	s9++;
	cout << "s9++ :: "; s9.print();

	String s10("Windows");
	String s11 = !s10;
	cout << "!s10 :: "; s11.print();

	String a("apple");
	String b("banana");
	cout << "a == b :: " << (a == b) << endl;
	cout << "a != b :: " << (a != b) << endl;
	cout << "a <  b :: " << (a < b) << endl;
	cout << "a >  b :: " << (a > b) << endl;
	cout << "a <= b :: " << (a <= b) << endl;
	cout << "a >= b :: " << (a >= b) << endl;

}