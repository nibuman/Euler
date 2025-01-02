#include <iostream>
#include "primelist.h"

/*
Problem 50
TThe prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/

using namespace std;

int main(){
    long long int primetotal=0;
	int primelimit;
	int noofterms=0;
	int currentmax=0;
	int primeindex = 1;

	cout << "Problem 50" << endl;
	cout << "Enter limit: ";
	cin >> primelimit;


	primelist myprimes(primelimit);
	myprimes.setprime(primeindex);

    while(myprimes.getcurrentprime()<0.7*primelimit){

        	while(primetotal<primelimit){
            noofterms++;
            primetotal += myprimes.getcurrentprime();
            // cout << myprimes.getcurrentprime() << endl;
            myprimes.nextprime();
            if(primetotal<primelimit && myprimes.isprime(primetotal)){
                if(noofterms>currentmax){
                    cout << "Current Total = " << primetotal << "  Length = " << noofterms << endl;
                    currentmax = noofterms;
                }
            }
            }
        primeindex++;
        myprimes.setprime(primeindex);
        //cout << "Setting new prime... = " << myprimes.getcurrentprime() << endl;
        noofterms=primetotal=0;

    }

};
