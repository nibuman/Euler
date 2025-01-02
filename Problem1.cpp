#include <iostream>
using namespace std;

//If we list all the natural numbers below 10 that are multiples of 3 or 5
// we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.

int main ()
{
	int total;
	int i;
	
	total=0;
	
	for (i=0; i<1000; i=i+1){
		if(i%3==0)total = total + i; //Add any multiples of 3
		if(i%5==0 && i%3!=0) total = total + i; //Add any multiples of 5 removing any duplicates
		}
	
	cout << "Total = " << total << endl;
	
	return 0;
	
}		