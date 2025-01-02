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

#ifndef _DIGITARRAY_H_
#define _DIGITARRAY_H_


class digitarray
{
public:
	digitarray(int thisnumber, int arrsize);
	digitarray(int thisnumber);
	digitarray();
	bool print();
	void changenum(int x);
	int position(int x);
	void size(int n);

protected:

private:
	int thisarray[12];
	void assignarray(int x);
	int arraysize;

};

#endif // _DIGITARRAY_H_
