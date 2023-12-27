/*
 * construct.cxx
 * 
 * Copyright 2023 Mike <mike@fedora38-2.home>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * Using Wikipedia construct
 * base = 10
 * prime = various > 5
 */


#include <iostream>
#include <cstdint>

using namespace std;
using u64=uint64_t;

int main(int argc, char **argv)
{
	const u64 base = 10;	// base
	u64 p = 7;				// prime
	
	u64 t = 0;
	u64 r = 1;
	u64 digit,x,n = 0;
	do {
		t += 1;
		x = r * base;
		digit = x / base;
		cout << "d:" << digit << "  ";
		r = x % p;
		n = n*base + digit;
		cout << "n:" << n << endl;		
	} while(r != 1);
	return 0;
}

