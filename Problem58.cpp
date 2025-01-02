/*
Problem 58
Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal,
but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime;
that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed.
If this process is continued, what is the side length of the square spiral for which the ratio of primes
along both diagonals first falls below 10%?
*/

#include <iostream>
#include "primelist.h"
#include <cstring>
#define spiralsize 13400 //set to 13400


using namespace std;

bool ne[spiralsize], se[spiralsize], sw[spiralsize], nw[spiralsize];
long long int populatespiral(bool *diagonal, int startinc, bool testprime);
bool printhighestnum();
primelist myprimes(750000000); // 750000000 works fine

int main(int argc, char *argv[])
{
	/*string myargs;
	myargs = argv[1];
	cout << "argc = " << argc << "  argv[1]=" << argv[1] << endl;
	if(argc>1 && myargs=="highestprime") {
		printhighestnum();
		return 0;
	}
	*/
	long double primetally=3, tally=5;
	long long int sidelength=3, position=0;
	double ratio=0.6;
	
	populatespiral(se, 8, true);
	populatespiral(ne, 2, true);
	populatespiral(sw, 6, true);
	populatespiral(nw, 4, true);

	while(ratio>0.1){
		
		position++;
		if(position>spiralsize){
			cout << "Increase spiral size" << endl;
			return 0;
		}
		tally=tally+4;
		sidelength = sidelength+2;
		if(ne[position]) primetally++;
		if(se[position]) primetally++;
		if(sw[position]) primetally++;
		if(nw[position]) primetally++;
		ratio = primetally/tally;
		cout<<"Size: " << sidelength << "  Primes: " << primetally << " Total: "<< tally;
		cout<< "  Spiralsize: " << position << "   Ratio: " << ratio <<  endl;
	} 
		
	return 0;
}

bool printhighestnum()
{
	long long int highestnum;
	highestnum = populatespiral(se, 8, false);
	cout << "For a spiral of size " << spiralsize << " highest se number is " << highestnum << endl;
	highestnum = populatespiral(ne, 2, false);
	cout << "For a spiral of size " << spiralsize << " highest ne number is " << highestnum << endl;
	highestnum = populatespiral(sw, 6, false);
	cout << "For a spiral of size " << spiralsize << " highest sw number is " << highestnum << endl;
	highestnum = populatespiral(nw, 4, false);
	cout << "For a spiral of size " << spiralsize << " highest nw number is " << highestnum << endl;
	return true;
}

long long int populatespiral(bool *diagonal, int startinc, bool testprime)
{

	int increment=startinc;
	long long int current=0, prev=1;
	
	for(long long int n=0; n<spiralsize; n++){
		current=prev+increment;
		if(testprime && myprimes.isprime(current)){
			diagonal[n]=true;
		} else diagonal[n]=false;
		//cout << "n: " << n << "  Number: " << current << "   Prime: " << diagonal[n] << endl;
		prev = current;
		increment=increment+8;
	}

	return current;
}
		