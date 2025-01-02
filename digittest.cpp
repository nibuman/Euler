#include <iostream>
#include "digit.h"
#include "digitarray2.h"

using namespace std;

int main()
{
	digit a(9);
	digit b(4);
	digit c;
	digit carryover;

	c=a+b;
	carryover = c.getcarryover();
	cout << "Printing a+b...  ";
	a.print();
	cout << " ";
	b.print();
	cout<< " ";
	c.print();
	cout<< " carryover ";
	carryover.print();
	cout << endl;
	c=a*b;
	carryover = c.getcarryover();
	cout << "Printing a*b...  ";
	a.print();
	cout << " ";
	b.print();
	cout<< " ";
	c.print();
	cout<< " carryover ";
	carryover.print();
	cout << endl;
	a=a*b;
	carryover = a.getcarryover();
	cout << "Printing a=a+b...  ";
	a.print();
	cout<< " carryover ";
	carryover.print();
	cout << endl;
	a=a*b;
	carryover = a.getcarryover();
	cout << "Printing a=a+b...  ";
	a.print();
	cout<< " carryover ";
	carryover.print();
	cout << endl;

	digitarray testarray(10);
	testarray.setvalue("1234567890");
	testarray.print();

	digitarray testing1(8);
	testing1.setvalue("12345678");
	testing1.print();
	digitarray testing2(1);
	testing2.setvalue("1");
	testing2.print();

	digitarray testing3;
	testing3 = testing1+testing2;
	testing3.print();
	return 0;
	
}