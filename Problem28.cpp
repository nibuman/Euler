/*
Problem 28

Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

*/

#define spiralsize 501
#include <iostream>

using namespace std;

long long int populatespiral(int startinc);

int main()
{
	long long int total = 1;
	int sidelength;

	sidelength = (2*(spiralsize-1))+1;
	
	total = total + populatespiral(2);
	total = total + populatespiral(8);
	total = total + populatespiral(4);
	total = total + populatespiral(6);
	cout << "For a spiralsize " << spiralsize << " (sidelength " << sidelength << ") total = " << total << endl;
	return 0;
}


long long int populatespiral(int startinc)
{
	int increment=startinc;
	long long int current=1, prev=1, tally=0;
	
	
	for(long long int n=1; n<spiralsize; n++){
		current=prev+increment;	
		tally = tally + current;
		cout << "n: " << n << "  Number: " << current << endl;
		prev = current;
		increment=increment+8;
	}

	return tally;
}
		