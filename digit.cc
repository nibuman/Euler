/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * digit.cc
 * Copyright (C) Nick Bushby 2011 <nick@bushbyweb.co.uk>
 *
 * digit.cc is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * digit.cc is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "digit.h"
#include <iostream>

using namespace std;

digit::digit(char initialdigit)
{
    setdigit(initialdigit);
    carryover=0;
}

bool digit::setdigit(char setdigit)
{
    if(setdigit<10)
    {
        thisdigit=setdigit;
        return true;
    }
    else
    {
        cout << "Invalid digit: " << setdigit << endl;
        return false;
    }
}
digit::digit(char initialdigit, char carryovertemp)
{
    setdigit(initialdigit);
    carryover=carryovertemp;
}

digit::digit()
{
    carryover = 0;
    thisdigit=0;
}
char digit::getdigitaschar()
{
    return thisdigit;
}

void digit::print()
{
    char printtemp;
    printtemp = thisdigit+48;
    cout << printtemp;
}

digit digit::getcarryover()
{
    digit thiscarryover(carryover);
    return thiscarryover;
}

char digit::getcarryoverchar()
{
    return carryover;
}
digit digit::operator=(digit digit2)
{
    thisdigit = digit2.getdigitaschar();
    carryover = digit2.getcarryoverchar();

    return *this;
}

digit digit::operator+(digit digit2)
{
    char addtemp, sum, carryovertemp;

    sum = thisdigit+digit2.getdigitaschar();

    if(sum>9)
    {
        carryovertemp = 1;
        addtemp = sum-10; //for a sum of 2 digits, highest possible number is 18
    }
    else
    {
        carryovertemp = 0;
        addtemp = sum;
    }

    digit temp(addtemp, carryovertemp);
    return temp;
}

digit digit::operator*(digit digit2)
{
    char timestemp, product, carryovertemp;

    product = thisdigit*digit2.getdigitaschar();

    if(product>9)
    {
        carryovertemp = product/10; //carryover must be between 1-8
        timestemp = product-(10*carryovertemp); //for a product of 2 digits, highest possible number is 81
    }
    else
    {
        carryovertemp = 0;
        timestemp = product;
    }

    digit temp(timestemp, carryovertemp);
    return temp;
}
int digit::getdigitasint()
{
    int intd = thisdigit;
    if(intd<0 || intd>9)
    {
        cout << "Error returning digit as integer: " << thisdigit << endl;
        return 0;
    }
    return intd;
}
 bool digit::IsEven()
 {
 if(getdigitasint()==0 || getdigitasint()==2 || getdigitasint()==4 || getdigitasint()==6 || getdigitasint()==8) return true;
 return false;
 }
