#include <iostream>
#include "math.h"

using namespace std;

bool IsPerfectSquare(long int &sq);

int main()
{
    long int a,b,c,d,e,f=0;
    long int x,y,z=0;
    long int a_sq, b_sq, c_sq, d_sq, e_sq, f_sq=0;
    long int smallest_sum=0;


    for(a=3; a<1000; a++)
    {
        a_sq = a*a;
        //c=sqrt(a_sq/2)-1; // c>f so to make sure c always greater only need to start here.
        c=1;
        f=0;
        while (c<a)
        {
            c++;
            c_sq = c*c;
            f_sq = a_sq - c_sq;
            if(IsPerfectSquare(f_sq))
            {
                f=sqrt(f_sq);
                b=0;
                while (b<c)
                {
                    b++;
                    b_sq = b*b;
                    d_sq = b_sq + f_sq;
                    if(IsPerfectSquare(d_sq))
                    {
                        d=sqrt(d_sq);
                        e_sq = a_sq - d_sq;
                        if(IsPerfectSquare(e_sq))
                        {
                            e = sqrt(e_sq);

                            if((a_sq - b_sq) == (e_sq + f_sq) && (e_sq-f_sq)==(c_sq-d_sq) && (a_sq+b_sq)==(c_sq+d_sq))
                            {
                                x=(a_sq+b_sq)/2;
                                y=(a_sq-b_sq)/2;
                                z=(e_sq-f_sq)/2;

                                if(x>0 && y>0 && z>0 && x>y && y>z && IsPerfectSquare(a_sq) && IsPerfectSquare(b_sq) && IsPerfectSquare(c_sq) && IsPerfectSquare(d_sq) && IsPerfectSquare(e_sq) && IsPerfectSquare(f_sq))
                                {
                                    long int sum = x+y+z;
                                    if(sum<smallest_sum || !smallest_sum) smallest_sum=sum;

                                    cout<< "a=" << a << " b=" << b << " c=" << c << " d=" << d << " e=" << e << " f=" << f << endl;
                                    cout<< "a2=" << a_sq << " b2=" << b_sq << " c2=" << c_sq << " d2=" << d_sq << " e2=" << e_sq << " f2=" << f_sq << endl;
                                    cout<< "x=" << x << " y=" << y << " z=" << z << endl;
                                    cout<< "sum =" << sum << endl;
                                    int sq_sqrt=sqrt(x+y);
                                    long int sq = sq_sqrt*sq_sqrt;
                                    cout << "x+y=" << x+y << " sqrt(x+y)=" << sq_sqrt << "  sq2=" << sq << endl;
                                    if(sq==(x+y)) cout << "TRUE" << endl;

                                }
                            }
                        }
                    }


                }
            }
        }


    }
    cout << "Smallest = " << smallest_sum << endl;
    return 0;
}

bool IsPerfectSquare(long int &sq)
{
    int sq_sqrt=sqrt(sq);
    /*long double rnd_sq_sqrt = rint(sq_sqrt);
    if(rnd_sq_sqrt==sq_sqrt && sq) return true;*/
    if(sq_sqrt*sq_sqrt == sq) return true;

    return false;

}
