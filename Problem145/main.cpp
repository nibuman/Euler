/*How many reversible numbers are there below one-billion?
Problem 145

Some positive integers n have the property that the sum [ n + reverse(n) ] consists entirely of odd (decimal) digits.
For instance, 36 + 63 = 99 and 409 + 904 = 1313.
We will call such numbers reversible; so 36, 63, 409, and 904 are reversible.
Leading zeroes are not allowed in either n or reverse(n).

There are 120 reversible numbers below one-thousand.

How many reversible numbers are there below one-billion (109)?
*/

#include <iostream>
#include "../digit.h"
#include "../digitarray2.h"
#include "math.h"
#include <new>


using namespace std;

int main()
{
    int topnumberexp =9; //the highest number to search to a 10^x. i.e. 3 = 1000
    int revn=0;
    int sumofints=0;
    int revcount=0;
    digitarray rarray;
    digitarray sum_array;
    rarray.setvalue(0);

    for(int n=1; n<pow(10, topnumberexp); n++)
    {
        rarray.increment();
        if(!rarray.hastrailingzero() && rarray.P145_sumdigitsnoteven()) revcount++;
    }
    cout << "For numbers up to 10^" << topnumberexp << ", reversible numbers = " << revcount << endl;
    return 1;
}

