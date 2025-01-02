#include <iostream>
#include <fstream>
#include "digit.h"
#include "digitarray2.h"

using namespace std;

char *listfromfile(char *filename);
const int num_arrays = 100; //the number of 50-digit integers to read in from the file
const int array_length = 51;

int main()
{
	digitarray myintegers[100];
	char *listofintegers = listfromfile("Problem13.txt");
	int currentpos = 0;
	while(*listofintegers){
		cout<<listofintegers[currentpos];
	}
}

char *listfromfile(char *filename)
{
//Reads content of file into an array (tries[]) and return pointer to first position
	static char lines[array_length][num_arrays];
	for(int a=0; a<array_length; a++){
		for(int b=0; b<num_arrays; b++){
			lines[a][b] = 0;
		}
	}
	
	ifstream key(filename);
	if(!key){
		cout << "Could not open key log file" << endl;
		}
	for(int x=0; x<num_arrays;x++){
		key >> lines[x];
		}
	
	return &lines[0][0];
}
