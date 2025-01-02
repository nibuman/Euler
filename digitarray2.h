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

#ifndef _DIGITARRAY2_H_
#define _DIGITARRAY2_H_

class digitarray
{
public:
	digitarray();
	digitarray(int arraysize);
	~digitarray();

	void print();

	digit getdigit(int index);
	char getdigitaschar(int index);
	int getsize();
	int getarrayasint();

	bool setvalue(char *valaschar);
	bool setvalue(int valasint);
	bool setdigit(int index, char digitvalue);
	bool reversedigits();
	bool carryover;
	bool isreverse();
	bool containsevendigits();
	bool hastrailingzero();
	bool P145_sumdigitsnoteven();
	void increment();

	digitarray operator+(digitarray array2);
	digitarray operator*(digitarray array2);
	digitarray operator=(digitarray array2);
	digitarray operator++();

protected:

private:
	int size;
	digit *thisarray;
	bool createarray();
	bool assignintarray();
	void carryoverzip(digit *ziparray, int zipsize);
    bool iseven(int &thisint);
};

#endif // _DIGITARRAY2_H_
