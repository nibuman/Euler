#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include "digitarray.h"

//A common security method used for online banking is to ask the user for three 
//random characters from a passcode. For example, if the passcode was 531278, 
//they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

//The text file, Problem79.txt, contains fifty successful login attempts.

//Given that the three characters are always asked for in order, 
//analyse the file so as to determine the shortest possible secret passcode of unknown length.

using namespace std;

int *listfromfile(char *keyfile);
const int attempts = 50;
const int codelength = 8;

int main()
{
	int *liststart, *list;
	digitarray key[attempts];
	digitarray fullcode(100000, codelength);
	bool invalidkey = false;
	int counter;
	int numberstats[10], numbercount[10], numbertotal[10];
	
		
	liststart = listfromfile("Problem79.txt"); //All the numbers from keylog file read into this array

	list = liststart;

	//Digitarray object treats an integer as an array of separate digits i.e. 879 is 8, 7, 9.
	//All the integeters from keylog file are created as separate digitarray objects.
	
	for(int n=0; n<attempts; n++){
		key[n].size(3);
		key[n].changenum(*list);
		key[n].print();
		list++;
	}
//Brute force cracker. Checks every number for a given length of code (set as the constant 'codelength')
	for (int code=73100000; code<73200000; code++){
		fullcode.changenum(code);
		invalidkey = false;		
		for(int thiskey = 0; thiskey<attempts; thiskey++){
			counter = 0;
			for(int n=0; n<codelength; n++){
				if(fullcode.position(n)==key[thiskey].position(counter) && counter<3) counter++;				
				}
			if (counter<3) {
				invalidkey = true;
				thiskey = attempts;
			}
	
		}
		if (!invalidkey) cout << "  Code: " << code <<endl;
	
	}

	//Analyses statistics of where the digits appear: -1 point for 1st, 0 points for 2nd, +1 point for each 3rd position
	for (int n=0; n<10; n++){
		numberstats[n]=0;
		numbercount[n]=0;
		numbertotal[n]=0;
	}
	
	for(int thiskey = 0; thiskey<attempts; thiskey++){
		numberstats[key[thiskey].position(0)]--;
		numberstats[key[thiskey].position(2)]++;
		for (int n=0; n<3; n++){
			numbercount[key[thiskey].position(n)]++;
		}
	}

	for(int n=0; n<10; n++){
		cout << n << "  ";
	}
	cout << endl;
	for(int n=0; n<10; n++){
		cout << numberstats[n] << " ";
	}
	cout << endl;
	for(int n=0; n<10; n++){
		cout << numbercount[n] << " ";
	}
	cout << endl;
	for(int n=0; n<10; n++){
		cout << numbercount[n]*numberstats[n] << " ";
	}
	cout << endl;
	
	return 0;
}

int *listfromfile(char *keyfile)
{
//Reads content of file into an array (tries[]) and return pointer to first position
	static int tries[attempts];

	ifstream key(keyfile);
	if(!key){
		cout << "Could not open key log file" << endl;
		}
	for(int x=0; x<attempts;x++){
		key >> tries[x];
		}
	
	return &tries[0];
}	