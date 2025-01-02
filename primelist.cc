/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * primelist.cc
 * Copyright (C) Nick Bushby 2011 <nick@bushbyweb.co.uk>
 *
 * primelist.cc is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * primelist.cc is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "primelist.h"
#include <iostream>
#include <new>
#include <cassert>

/*
 Creates a Sieve of Eratosthenes to find prime numbers
 */

using namespace std;

// maxnumber is how big the sieve should be (i.e. the highest number to be checked for 'primeness'

primelist::primelist(long long int maxnumber)
{
	limit = maxnumber;
	createsieve(); //function that actually creates the sieve
}

int primelist::createsieve()
{
	//needs to dynamically allocate memory for the array that will hold the sieve
	//as for some applications may need to be very large

	//The sieve itself is stored as a boolean array where if array[n]=false then n is not prime
	//if array[n]=true then n is prime

	try {
		sievearray = new bool [limit+1];
	} catch (bad_alloc xa) {
		cout << "Allocation Failure\n";
		return 1;
	}
	long long int currentprime = 2;

	for (long long int n=0; n<(limit+1); n++){
		sievearray[n]=true;
	}
	sievearray[0]=false; //by convention 0 and 1 are not primes
	sievearray[1]=false;

	for (long long int n=0; n<(limit+1); n++){
		if (sievearray[n]){
			currentprime=n;
			if ((currentprime*currentprime) < (limit+1)){ //only need to start counting at currentprime^2 because numbers below this already dealt with
				for(long long int m = (currentprime*currentprime); m<(limit+1); m=m+currentprime){
                //cout << "m = " << m << endl;
				sievearray[m]=false;
				}
			}
		}
	}
	cout << "Created sieve" << endl;
	return 0;
}

primelist::~primelist(){
	//free up the memory allocated to the sieve
	delete []sievearray;
}

long long int primelist::returnprime(long long int primeindex) //returns the given prime i.e. returnprime(4) will return the 4th prime number
{
	long long int counter=0;
	for (long long int n=0; n<(limit+1); n++){
		if(sievearray[n]){
			counter++;
		}
		if (counter==primeindex){
			//cout << "Prime " << primeindex << " is " << n << endl;
			return n;
		}
	}
	cout << "Got as far as prime number " << counter << endl;
	return 0;
}

bool primelist::isprime(long long int thisprime){
	assert(thisprime<limit);
	if(sievearray[thisprime]){
		return true;
	}

	/*if(thisprime>limit) testprime(thisprime);
	else if(sievearray[thisprimaime]) return true;
*/
	return false;
}

bool primelist::setprime(long long int primeindex)
{
	long long int tempprime = returnprime(primeindex);

	if(tempprime) {
		currentprimeindex = primeindex;
		currentprime = tempprime;
		return true;
	}
	return false;
}

bool primelist::nextprime()
{
	for (long long int n=currentprime+1; n<=limit; n++){
		if(sievearray[n]){
			currentprime = n;
			currentprimeindex++;
			return true;
		}
	}
	return false;
}



long long int primelist::getcurrentprime()
{
	return currentprime;
}
