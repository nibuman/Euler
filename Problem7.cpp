#include <iostream>
#include "primelist.h"

/*
Problem 7
28 December 2001

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?
*/

using namespace std;

int main ()
{
	int target = 10001; //the prime to look for
	int size = 200000; //how many numbers to check for primeness
	
	primelist mylist(size);
	cout<< "Prime " << target << " is " << mylist.returnprime(target) << endl;
	
return 0;
}
