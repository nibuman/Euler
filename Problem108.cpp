/* Problem 108 - Diophantine Equation
 
 In the following equation x, y, and n are positive integers.
1/x + 1/y = 1/n

For n = 4 there are exactly three distinct solutions:
1/5 + 1/20 = 1/4
1/6 + 1/12 = 1/4
1/8 + 1/8 = 1/4

What is the least value of n for which the number of distinct solutions exceeds one-thousand?
*/

#include <iostream>

using namespace std;

const int increment = 1;
long long int diophantine_solutions (long long int this_n); //find how many solutions to the diophantine equation for a given n;
long long int find_n(long long int starting_n); //find likely values of n

int main()
{
	long long int set_n = 1, try_n = 1130;
	long long int solutions = 0;

	/*cout << "Enter n: ";
	cin >> set_n;

	solutions = diophantine_solutions(set_n);

	cout << "Number of distinct solutions = " << solutions << endl;
	*/

	while(solutions<1000){
		
		set_n = find_n(try_n);
		solutions = diophantine_solutions(set_n);

		cout << "Trying n = " << set_n << "  Solutions = " << solutions << endl;
		try_n = set_n + 1;
		//cout << "Next one to try = " << try_n << endl;
	}
	
	return 0;
}

long long int find_n(long long int starting_n)
{
	//Try to find some likely values of n such that nx (denominator) is divisible by the most integers
	//i.e. nx = n(n+1) = n2+n is divisible by 2,3,4,5,6,7....

	long long int n, nprod=0;
	bool is_divisible = false;
	n = starting_n;
	nprod = (n*n)+n;
	
	while(!is_divisible){
		is_divisible=true;
		
		if(nprod%2) is_divisible = false;
		if(nprod%3) is_divisible = false;
		if(nprod%4) is_divisible = false;
		if(nprod%5) is_divisible = false;
		if(nprod%6) is_divisible = false;
		if(nprod%7) is_divisible = false;
		//if(nprod%8) is_divisible = false;
		if(nprod%9) is_divisible = false;
		
		nprod+= (2*n)+2;
		n++;
	 
	}
	//cout << nprod<< endl;
	return n-1;
		
	
}

long long int diophantine_solutions (long long int max_n){
	long long int solutions_count = 0;
	long long int n, x, denominator, numerator;
	
	/* 1/y = 1/n - 1/x = x-n / xn
	 	=> When x increments i.e. x = x+1
		1/y = ((x+1) - n) / (x+1)n = (x - n + 1) / nx + n = numerator / denominator */

	n = max_n;
	x = n+1;
	denominator = n * x;
	numerator = x - n;
	//cout << "denominator = " << denominator << "  numerator = " << numerator << "  d mod n = " << denominator%numerator << endl;
		
	for (int x1 = x; x1<=(2*n); x1++){
		if(!(denominator%numerator)){
			solutions_count++;
		}
		numerator++;
		denominator+=n;
	}

	return solutions_count;
}
	

	
	


