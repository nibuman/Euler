#include <iostream>

/*
PROBLEM 6
The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

using namespace std;

int main()
{
	long int sumofsquares=0, squareofsum=0;
	int sumofnumbers=0;
	
	for (int n=1; n<101; n++){
		sumofnumbers = sumofnumbers+n;
		sumofsquares = sumofsquares + (n*n);
	}
	
	squareofsum = sumofnumbers*sumofnumbers;
	cout << "Square of sum = " << squareofsum << endl;
	cout << "Sum of squares = " << sumofsquares << endl;
	cout << "Difference = " << (squareofsum - sumofsquares) << endl;
}
		