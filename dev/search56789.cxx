/*
 * recip.cxx
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
 * 
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
	queue<uint64_t> q;
	
	//p = 725163167;
	//p = 72516;
	
	vector<uint64_t> vp = {725158747,725158757,725158853,725158871,725158901,725158909,725158937,725158961,725158963,725158999};
	// p = 1033;
	
	// Given p, establish the correct value for n.
	//~ n = p;
	//~ t = 1;
	//~ do{
		//~ n /= 10;
		//~ t *= 10;
	//~ }while(n>1);
	//~ cout << "t:" << t << endl;
	for(uint64_t p : vp){
		for(uint64_t x = 0; x != 5; ++x) q.push(0);
		cout << "p = " << p << " 1/p = " << double(1.0/double(p)) << endl;
		n = 10;
		t = 1;
		while(1){
		r = n % p;
		d = n / p;
		//cout << d << " ";
		sum += d;
		q.pop();
		q.push(d);
		if((r == 1)&&(t > 1)) break;
		n = r*10;
		t++;
		}
		cout << "t = " << t << " sum=" << sum << endl;
		
		//~ if(t = (p-1)) {
			//~ cout << "cyclic number." << endl;
		//~ }
		while(!q.empty()){
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}

	return 0;
}

