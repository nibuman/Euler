#include <iostream>
#include "IntegerFunc.h"

/*  AKS primality test Algorithm
 From http://en.wikipedia.org/wiki/AKS_primality_test
 Input: integer n > 1.

    1) If n = a^b for integers a > 0 and b > 1, output composite.
    2) Find the smallest r such that or(n) > log2(n).
    3) If 1 < gcd(a,n) < n for some a ≤ r, output composite.
    4) If n ≤ r, output prime.
    5) For a = 1 to [sqrt(phi(r).log(n)] do
     if (X+a)^n≠ X^n+a (mod X^r − 1,n), output composite;
	6) Output prime.

Here or(n) is the multiplicative order of n modulo r, log is the binary logarithm, and
 phi(r) is Euler's totient function of r.

If n is a prime number, the algorithm will always return prime: since n is prime,steps 1
and 3 will never return composite. Step 5 will also never return composite, because (2)
is true for all prime numbers n. Therefore, the algorithm will return prime either in 
step 4 or in step 6.Conversely, if n is composite, the algorithm will always return 
composite: if the algorithm returns prime, then this will occur in either step 4 or step 6. 
In the first case, since n ≤ r, n has a factor a ≤ r such that 1 < gcd(a,n) < n, 
which will return composite. The remaining possibility is that the algorithm returns prime in step 6. 
In the article,[1] it is proved that this will not happen, 
because the multiple equalities tested in step 5 are sufficient to guarantee that the output is composite.
 */

using namespace std;

int aksprimetest(long long int testnum)
{
}