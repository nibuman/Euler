#include <iostream>
#include <cmath>

using namespace std;

//Problem 4

//A palindromic number reads the same both ways. 
//The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3-digit numbers.

bool ispal(int current);

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

bool ispal(int current){
	
	int a[6];
	int n;
	
	//cout << current << endl;

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
	//cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[5] << endl;
	return false;
}
	
	
	
