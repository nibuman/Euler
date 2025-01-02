/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * digitarray2.cc
 * Copyright (C) Nick Bushby 2011 <nick@bushbyweb.co.uk>
 *
 * digitarray2.cc is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * digitarray2.cc is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "digit.h"
#include "digitarray2.h"
#include "math.h"

#include <iostream>
#include <new>

using namespace std;


digitarray::digitarray()
{
    size=0;
    carryover = false;
}
digitarray::digitarray(int arraysize)
{
    size = arraysize;
    carryover = false;
    createarray();
}

bool digitarray::setvalue(int valasint)
{
    //This implementation first determines the size of the integer and sets the array to that size;

    //Determine size of number
    int currentsize = 1;
    int tempint = valasint/pow(10,currentsize);
    while(tempint)
    {
        currentsize++;
        tempint = valasint/pow(10,currentsize);
    }

    if(currentsize != size)
    {
        if(size) delete []thisarray;
        //create array
        size = currentsize;
        createarray();
    }



    //read digits into array
    int mult = pow(10, size-1);
    int currentdigit;
    for(int n=0; n<size; n++)
    {
        currentdigit = valasint / mult;
        thisarray[n].setdigit(currentdigit);
        valasint = valasint - (currentdigit * mult);
        mult = mult /10;
    }
    return true;
}

digitarray::~digitarray()
{
    cout << "Digitarray Destructor called" << endl;
    if(size) delete []thisarray;
    cout << "Digitarray Destructed" << endl;
}

bool digitarray::setvalue(char *valaschar)
{
    int n=0;
    while(valaschar[n] && n<(size+1))
    {
        thisarray[n].setdigit(valaschar[n]-48);
        n++;
    }
    return true;
}

bool digitarray::createarray()
{
    try
    {
        thisarray = new digit[size+1];
    }
    catch (bad_alloc xa)
    {
        cout << "Allocation Failure\n";
        return false;
    }
    return true;
}

char digitarray::getdigitaschar(int index)
{
    char emptydigit(0);
    if (index < size)
    {
        return thisarray[index].getdigitaschar();
    }
    else
    {
        cout << "Tried to get digit with index " << index << " when digitarray is only size " << size << endl;
        return emptydigit;
    }

}

digit digitarray::getdigit(int index)
{
    digit emptydigit(0);
    if (index < size)
    {
        return thisarray[index];
    }
    else
    {
        cout << "Tried to get digit with index " << index << " when digitarray is only size " << size << endl;
        return emptydigit;
    }
}

digitarray digitarray::operator+(digitarray arrayB)
{
    int sizeA, sizeB, biggest, smallest, pre_lastdigit, post_lastdigit;


    //make sum array (arrayC) as big as the largest of the 2 arrays being summed
    sizeA = size;
    sizeB = arrayB.getsize();
    if(sizeA > sizeB)
    {
        smallest = sizeB;
        biggest = sizeA;
    }
    else
    {
        smallest = sizeA;
        biggest = sizeB;
    }

    digitarray arrayC(biggest);
    digit tempC;

    //sum each digit
    for(int c=0; c<biggest; c++)
    {
        tempC = thisarray[c]+arrayB.getdigit(c);
        arrayC.setdigit(c, tempC.getdigitaschar());
        cout<<"c"<<c;
        for(int co=c; co<biggest-1; co++)
        {
            tempC = arrayB.getdigit(co).getcarryover()+arrayB.getdigit(co+1);
            arrayB.setdigit(co, tempC.getdigitaschar());
            cout<<" co"<<co;
        }
    }
    arrayC.print();
    return arrayC;

}

digitarray digitarray::operator=(digitarray array2)
{

    size = array2.getsize();
    createarray();
    digit tempdigit;

    for(int n=0; n<size; n++)
    {
        thisarray[n].setdigit(array2.getdigitaschar(n));
    }

    return *this;
}


int digitarray::getsize()
{
    return size;
}
bool digitarray::setdigit(int index, char digitvalue)
{
    thisarray[index].setdigit(digitvalue);
}
void digitarray::print()
{
    for(int n=0; n<size; n++)
    {
        thisarray[n].print();
    }
    cout << endl;
}

digitarray digitarray::operator*(digitarray arrayB)
{
    // TODO: Add implementation here
}
digitarray digitarray::operator++()
{
//TODO
}
bool digitarray::assignintarray()
{
    // TODO: Add implementation here
}

bool digitarray::reversedigits()
{

    for(int n=0; n<(size/2); n++)
    {
        int p = size-1-n;
        char d1 = getdigitaschar(n);
        char d2 = getdigitaschar(p);
        setdigit(n, d2);
        setdigit(p, d1);
    }

}

bool digitarray::iseven(int &thisint)
{
    if(thisint==0 || thisint==2 || thisint==4 || thisint==6 || thisint==8) return true;
    return false;
}

bool digitarray::P145_sumdigitsnoteven()
{
    int carryov=0;
    int sum = 0;

    for(int n=0; n<size; n++)
    {
        int p = size-1-n;
        sum = getdigit(n).getdigitasint() + getdigit(p).getdigitasint() + carryov;
        carryov = 0;
        if(sum>9)
        {
            carryov = 1;
            sum = sum -10;
        }
        if(iseven(sum)) return false;
    }

    return true;

}

void digitarray::increment()
{
    int carryov = 0;
    int inc = 0;
    int index = size-1;
    /*for (int n =0; n<size; n++)
    {
        cout<< "index: " << n << "  value: " << getdigit(n).getdigitasint() << endl;
    }
*/
    int current = getdigit(index).getdigitasint();
    current++;
    if(current > 9)
    {
        carryov = 1;
        current = current-10;
    }
    setdigit(index, current);
    index--;
    while (carryov && index >=0)
    {

        current = getdigit(index).getdigitasint();
        current = current + carryov;
        carryov = 0;
        if(current > 9)
        {
            carryov = 1;
            current = current-10;
        }
        setdigit(index, current);
        index--;

    }

    if(carryov) setvalue(getarrayasint() + pow(10,size));
    //cout << "Current value = " << getarrayasint() << endl;
}

int digitarray::getarrayasint()
{
    int total=0;
    int mult=1;
    for(int n=(size-1); n>=0; n--)
    {
        total+= getdigit(n).getdigitasint()*mult;
        mult*=10;
    }
    return total;
}

bool digitarray::containsevendigits()
{

    for(int n=0; n<(size); n++)
    {
        if(getdigit(n).IsEven()) return true;
    }
    return false;
}

bool digitarray::hastrailingzero()
{
    //cout<< "  size  " << size << "  digitasint" << getdigit(size-1).getdigitasint() << "\n";
    if(getdigit(size-1).getdigitasint())
    {
        //cout<<"false"<<"\n";
        return false;
    }
    //cout<<"true"<<"\n";
    return true;
}
