#include <iostream>
#include "IntegerFunc.h"

using namespace std;

int main()
{
	int test;
	test = modulo(16,7);
	cout << "16 modulo 7 = " << test << endl;

	test = modulo(64,7);
	cout << "64 modulo 7 = " << test << endl;

	test = multorder(4,7);
	cout << "multorder(4, 7) = " << test << endl;

	test = gcd(8,12);
	cout << "gcd(8,12) = " << test << endl;

	test = gcd(48,18);
	cout << "gcd(48,18) = " << test << endl;


	return 0;
}