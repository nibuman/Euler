#include "IntegerFunc.h"

/*
 Greatest Common Divisor gcd(a, b)

In mathematics, the greatest common divisor (gcd), also known as the greatest common factor (gcf)
or highest common factor (hcf), of two or more non-zero integers, is the largest positive integer
that divides the numbers without a remainder. For example, the GCD of 8 and 12 is 4.
*/

using namespace std;

long long int gcd(long long int a, long long int b)
{
	long long int lowest = 0, highest = 0;
	unsigned int remainder = 1;
	
	if(a>b){
		highest = a;
		lowest = b;
	}
	else{
		highest = b;
		lowest = a;
	}
	
/*
	 The Euclidean algorithm uses the division algorithm in combination with the observation that
	 the gcd of two numbers also divides their difference: divide 48 by 18 to get a quotient of 2 and
	 a remainder of 12. Then divide 18 by 12 to get a quotient of 1 and a remainder of 6. Then divide
	 12 by 6 to get a remainder of 0, which means that 6 is the gcd.
*/
	
	while(remainder>0){
		remainder = highest%lowest;
		highest = lowest;
		lowest = remainder;
	}

	return highest;
}
	