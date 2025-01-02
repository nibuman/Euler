#include <iostream>
#include "digit.h"
#include "digitarray2.h"

using namespace std;

int main()
{
	int power;
	int thissum;

	cout << "Power = ";
	cin >> power;
	

	digitarray big_exp(400);
	digitarray two(1);

	two.setvalue("2");
	big_exp.setvalue("2");
	
	for(int n=1; n<power; n++){
		big_exp = big_exp * two;
	}

	big_exp.print();
	thissum = big_exp.sumofdigits();

	cout << "Sum = " << thissum << endl;

	return 0;
}
		