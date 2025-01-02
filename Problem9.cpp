#include <iostream>

using namespace std;

//Problem 9

//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//a2 + b2 = c2
//For example, 32 + 42 = 9 + 16 = 25 = 52.
//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.

int main()
{
	int a, b, c;
	a=0;
	b=0;
	c=1000;
	
	for(a=1; a<400;a++){
		for(b=a+1; b<c;b++){
		c=1000-a-b;
		if (a*a+b*b==c*c){
			cout << "a + b + c = " << a << " + " << b << " + " << c << " = " << a+b+c << endl;
			cout << "a2 + b2 = c2 = " << a*a << " + " << b*b << " = " << c*c << endl;
			cout << "Answer: abc = " << a*b*c << endl;
			}
		}
	}
	
	return 0;
}
	
		
		