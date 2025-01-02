//Sieve of Eratosthenes Function
//Builds a list of prime numbers
#include "IntegerFunc.h"

using namespace std;

bool *primeSoE(const int limit)
{
	static bool sievearray[22];
	int currentprime = 2;
	
	for (int n=0; n<(limit+1); n++){
		sievearray[n]=true;
		}
	sievearray[0]=false;
	sievearray[1]=false;
	
	for (int n=0; n<(limit+1); n++){
		if (sievearray[n]){
			currentprime=n;
			for(int m = (2*currentprime); m<(limit+1); m=m+currentprime){
				sievearray[m]=false;
			}
		}
	}
	
	return &sievearray[0];
}