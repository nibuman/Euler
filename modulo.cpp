#include <iostream>
#include "IntegerFunc.h"

 //returns testnum (modulo modnum) e.g. modulo(16, 7) = 2
using namespace std;

int modulo(long long int testnum, int modnum)
{
	long long int counter=0;
	while(counter < testnum){
		counter = counter + modnum;
	}
	return testnum-counter+modnum;
	
}