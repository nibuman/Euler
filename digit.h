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

#ifndef _DIGIT_H_
#define _DIGIT_H_

class digit
{
public:
	digit(char initialdigit);
	digit();
	digit(char initialdigit, char initialcarryover);
	bool setdigit(char setdigit);
	char getdigitaschar();
	digit getcarryover();
	char getcarryoverchar();
	digit operator=(digit digit2);
	digit operator+(digit digit2);
	digit operator*(digit digit2);
	int getdigitasint();
	void print();
	bool IsEven();
protected:

private:
	char thisdigit;
	char carryover;
};

#endif // _DIGIT_H_
