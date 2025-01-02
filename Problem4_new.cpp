#include <iostream>
#include "IntegerFunc.h"

using namespace std;

//Problem 4

//A palindromic number reads the same both ways. 
//The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3-digit numbers.

int main()
{	
	int largestpal=0;
	int a;
	int b;

	for (a=100; a<1000; a++){
		for (b=100; b<1000; b++){
			if(ispal(a*b)){
				if(a*b > largestpal){
					largestpal=a*b;
					cout << a << " * " << b << " = " << a*b << endl;
				}
			} 
		}
	}
	return 0;
}