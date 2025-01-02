#include <iostream>
#include "primelist.h"
#include <cmath>

using namespace std;

long long int targetnum=600851475143;
int highestnum = 200000; //highest number to try as factor in this run
primelist myprimes(highestnum);

long long int primefactor(long long int remainder);

int main(){
	long long int p1=0, p2=0, p3=0;
	long long int r1=0, r2=0, r3=0;

	p1=primefactor(targetnum);
	
	if (p1){
		r1 = targetnum / p1;		
		cout << p1 << "(p) * " << r1 <<" = " << targetnum << endl;
		p2 = primefactor(r1);
		if(p2){
			r2 = r1/p2;
			if (r2<highestnum && myprimes.isprime(r2)){
				cout << p1 << "(p) * " << p2 << "(p) * " << r2 <<"(p) = " << targetnum << endl;
			} else 	cout << p1 << "(p) * " << p2 << "(p) * " << r2 <<" = " << targetnum << endl;
			p3 = primefactor(r2);
			if (p3){
				r3 = r2/p3;
				if (r3<highestnum && myprimes.isprime(r3)){
					cout << p1 << "(p) * " << p2 << "(p) * " << p3 << "(p) * " << r3 <<"(p) = " << targetnum << endl;
				} else 	cout << p1 << "(p) * " << p2 << "(p) * " << p3 << "(p) * " << r3 <<" = " << targetnum << endl;
			} else {
				cout << r2 << " has no prime factors < " << highestnum << endl;
			}				
		}	else {
			cout << r1 << " has no prime factors < " << highestnum << endl;
		}		
	}	else {
		cout << targetnum << " has no prime factors < " << highestnum << endl;
	}

	
				
	return 0;
}

long long int primefactor (long long int remainder){
	
	for(int n=3; n<highestnum; n=n+2){
		if(remainder%n==0 && myprimes.isprime(n)){
			return n;
		}
	}
	return 0;
}