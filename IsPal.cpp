//Checks to see whether a 5 or 6 digit integer
//is a palindrome

#include <cmath>
#include "IntegerFunc.h"

using namespace std;

bool ispal(int current){
	
	int a[6];
	int n;

	//Assign each digit of 'current' to the array
	for (n=0; n<6; n++){
		a[n] = current/pow(10,5-n);
		if (a[n]>0){
			current = current-(a[n]*pow(10,5-n));
		}
	}
	//Test for numbers of 5 digits
	if(a[0]==0){
		if(a[1]==a[5] && a[2]==a[4]){
			return true;
		}
	} 
	// test for numbers of 6 digits
	else{
		if(a[0]==a[5] && a[1]==a[4] && a[2]==a[3]){
			return true;
		}
	}

	return false;
}
	