/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * primelist.cc
 * Copyright (C) Nick Bushby 2011 <nick@bushbyweb.co.uk>
 *
 * primelist.cc is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * primelist.cc is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _PRIMELIST_H_
#define _PRIMELIST_H_

class primelist
{
public:
	primelist(long long int maxnumber);
	long long int returnprime(long long int primeindex);
	~primelist();
	bool isprime(long long int thisprime);
	bool setprime(long long int primeindex);
	bool nextprime();
	long long int getcurrentprime();

protected:

private:
	bool *sievearray;
    //bool testprime(long long integer testnumber);
	int createsieve();
	long long int limit;
	long long int currentprime; //Returns the current prime number
	long long int currentprimeindex; //The nth prime e.g. if currentprimeindex = 3 then currentprime = 5

};

#endif // _PRIMELIST_H_
