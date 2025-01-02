#include <iostream>
#include <cmath>

/*
Problem 5
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

using namespace std;

int highnum;

int main()
{
	cout << "Problem 5" << endl << "Enter highest number : ";
	cin >> highnum;
	bool evenlydivisible = false;
	int currentnumber = 0;
	
	while (!evenlydivisible){
		currentnumber = currentnumber + highnum; // the number must be a factor of highnum so increase by this
		evenlydivisible = true;
		for (int n=3; n<=highnum; n=n+1){
			if (currentnumber % n != 0){
				evenlydivisible = false;
				n=highnum+1;
			}
		}
	}
	cout << currentnumber << endl;
	return 0;
}