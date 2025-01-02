/* Quadratic primes
Problem 27

Euler discovered the remarkable quadratic formula:

n² + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

    n² + an + b, where |a| < 1000 and |b| < 1000

    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |−4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
*/
// b must be prime (as when n=0, answer = b

#include <iostream>
#include <new>
#include "../primelist.h"

using namespace std;

int main()
{
    long int highest_prime = 100*100+100*1000+1000;

    primelist myprimes(10000000);
    myprimes.setprime(1);

    int a = -1000;
    int b = 2;
    int longest_sequence = 0;
    int best_a = 0;
    int best_b = 0;
if (a<1000) cout << "a < 1000";
    while (a < 1000)
    {
        int prime_index = 1;
        while(b < 1000)
        {
            b = myprimes.returnprime(prime_index);
            //cout << "b = " << b << endl;
            int n = 0;
            int current_seq = 0;

            while (n*n+n*a+b > 1 && myprimes.isprime(n*n+n*a+b))
            {
                current_seq++;
                n++;
            }
            if (current_seq > longest_sequence)
            {
                longest_sequence = current_seq;
                best_a = a;
                best_b = b;
                cout << n << "^2 + " << a << "*" << n << " + " << b << " = " << n*n+n*a+b << endl;
            }
            prime_index++;
        }
        a++;
        b = 0;
        //if (a<1000) cout << "a still < 1000";
    }

    cout << "Longest sequence: " << longest_sequence << endl;
    cout << "a = " << best_a << "  b = " << best_b << endl;
    cout << "a * b = " << best_a * best_b << endl;

    return 0;
}
