#include "IntegerFunc.h"
#include <cmath>
#include <iostream>
/*
In number theory, given an integer a and a positive integer n with gcd(a,n) = 1, 
the multiplicative order of a modulo n is the smallest positive integer k with

    ak ≡ 1 (modulo n).

The order of a (mod n) is usually written ordn a, or On(a).

For example, to determine the multiplicative order of 4 modulo 7,
we compute 42 = 16 ≡ 2 (mod 7) and 43 = 64 ≡ 1 (mod 7), so ord7(4) = 3.
see: http://en.wikipedia.org/wiki/Multiplicative_order
*/

using namespace std;

int multorder(long long int testnum, int modnum)
{
	int k=1;
	while (modulo(pow(testnum, k), modnum)!=1){
		//cout << k << " " << modulo(pow(testnum, k), modnum) << endl;
		if(pow(testnum, k)>100000000){
			cout << "could not find mult order of " << testnum << ", " << modnum << " (currently power " << k << ")"<<endl;
			return 0;
		}
		k++;
	}
	return k;
}