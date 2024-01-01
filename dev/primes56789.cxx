/*
 * primes56789.cxx
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
 * soln 3284144505
 */


#include <iostream>
#include <cstdint>
#include <vector>
#include <array>
#include <queue>

using namespace std;

bool MillerRabin(uint64_t n);

int main(int argc, char **argv)
{
	uint64_t n,p,r,d,t,sum=0;
	// x-check array
	array<uint64_t,5>check;
	for(uint64_t x = 0; x != 5; ++x) check[x]=x+5;
	
	// Construct a vector of primes to search, 725163167 -> 729927007 inclusive.
	//  vp(size)=233193
	vector<uint64_t> vp;
	for(uint64_t n = 725209891; n != 729909891; n += 100000) if(MillerRabin(n)) vp.push_back(n);
	cout << "vp(size)=" << vp.size() << endl;
	
	vp = {729809891};
	for(uint64_t p : vp){
		sum=0;
		queue<uint64_t> q;
		for(uint64_t x = 0; x != 5; ++x) q.push(0);
		n = 10;
		t = 1;
		while(1){
			r = n % p;
			d = n / p;
			//cout << d << ":" << r << "  ";
			sum += d;
			q.pop();
			q.push(d);
			n = r*10;
			if(r == 1) break;
			t++;
		}
		
		//cout << "\np = " << p << " t = " << t << " sum=" << sum << "\t";
		
		if(t == (p-1)) {
			
			array<uint64_t,5> ending;
			array<uint64_t,5>::iterator i = ending.begin();
			while(!q.empty()){
				*(i++) = q.front();
				q.pop();
			}
			//~ for(auto x : check) cout<<x;
			//~ cout << "  ";
			//~ for(auto x : ending) cout<<x;
			//~ cout << endl;
			if(ending==check){
				cout << "Prime: "<< p <<  " cyclic number ending 56789" << endl;
				cout << "Digit sum = " << sum << endl;
			}
			
		}
	
	}

	return 0;
}

