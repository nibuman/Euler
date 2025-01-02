#include <iostream>
#include "primelist.h"

/*
Problem 10
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

using namespace std;

int main()
{
	long long int primetotal;
	int primelimit;
	
	cout << "Problem 10" << endl;
	cout << "Enter limit: ";
	cin >> primelimit;
		
	primelist myprimes(primelimit);
	myprimes.setprime(1);

	primetotal = myprimes.getcurrentprime();

	while(myprimes.nextprime()){
		primetotal = primetotal + myprimes.getcurrentprime();
	}

	cout << "Sum of primes = " << primetotal << endl;
	
	return 0;
}