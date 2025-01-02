/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * digitarray.cc
 * Copyright (C) Nick Bushby 2011 <nick@bushbyweb.co.uk>
 * 
 * digitarray.cc is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * digitarray.cc is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "digitarray.h"
#include <cmath>
#include <iostream>

using namespace std;

digitarray::digitarray(int thisnumber, int arrsize)
{
	arraysize = arrsize;
	assignarray(thisnumber);
}

digitarray::digitarray(int thisnumber)
{
	arraysize=0;
	assignarray(thisnumber);
}

digitarray::digitarray()
{
	arraysize=0;
	assignarray(0);
}

void digitarray::changenum(int x)
{
	assignarray(x);
}
bool digitarray::print()
{
	int s;
	if (arraysize<1||arraysize>12){
		s = 12;
	} 
	else {
		s=arraysize;
	}
	
	for(int n=0; n<s; n++){
		cout << thisarray[n] << "  ";
	}
	cout << endl;
	
	return true;
}
	
void digitarray::assignarray(int x)
{
	int s;
	int current = x;

	if (arraysize<1||arraysize>12){
		s = 12;
	} 
	else {
		s = arraysize;
	}
		
	for (int n=0; n<s; n++){
		thisarray[n] = current/pow(10,(s-1-n));
		if (thisarray[n]>0){
			current = current-(thisarray[n]*pow(10,(s-1-n)));
		}
	}
}

int digitarray::position(int x)
{
	return thisarray[x];
}

void digitarray::size(int n)
{
	arraysize=n;
}
