/*  Problem 59
Each character on a computer is assigned a unique code and the preferred standard is ASCII 
(American Standard Code for Information Interchange). For example, uppercase A = 65, asterisk (*) = 42,
and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte 
with a given value, taken from a secret key. The advantage with the XOR function is that using the 
same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. 
If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. 
The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters. 
Using cipher1.txt, a file containing the encrypted ASCII codes, and the knowledge that the plain text 
must contain common English words, decrypt the message and find the sum of the ASCII values in the original text.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <streambuf>


using namespace std;

const int MAX_SIZE = 1250;

int encryptedint[MAX_SIZE];
char encryptedstring[MAX_SIZE];
char decryptedstring[MAX_SIZE];
char password[3];

int listlength=0;
bool listfromfile(char *filename);
bool decrypt();
void print();
int sum();

int main()
{	
	if(!listfromfile("Problem59.txt")){
		cout << "Error... exiting." << endl;
		return 1;
	}
	
	for(int n=0; n<=listlength; n++){
		encryptedstring[n] = encryptedint[n];
		cout << encryptedstring[n] << " ";
	}

	for(char a1 = 'a'; a1 <='z'; a1++){
		password[0]=a1;
		for(char a2 = 'a'; a2 <='z'; a2++){
			password[1]=a2;
			for(char a3 = 'a'; a3 <='z'; a3++){
				password[2]=a3;
				if(decrypt()){
					print();
					int total = sum();
					cout << "The sum of ASCII values = " << total << endl;
				}				
			}
		}
	}

	
				
	return 0;
}

int sum()
{
	int total = 0;
	for(int n=0; n<=listlength; n++){
		total += decryptedstring[n];
	}
	return total;
}
bool decrypt()
{
	int counter = 0;
	for(int n=0; n<=listlength; n++){
		decryptedstring[n] = password[counter] ^ encryptedstring[n];
		//cout << "D: " << decryptedstring[n] << "  P: " << password[counter] << "  E: " << encryptedstring[n] << endl;
		if(decryptedstring[n] < ' ' || decryptedstring[n] > 'z'){
			//cout << "nope!";
			return false;
		}
		if(counter==2) {
			counter=0;
		} else counter++;
	}
	return true;
}

void print()
{
	for(int n=0; n<=listlength; n++){
		cout << decryptedstring[n];
	}
	cout << endl;
	
}
bool listfromfile(char *filename)
{	
	char comma;
	listlength = 0;
	
	ifstream csv_file(filename);
	if(!csv_file){
		cout << "Could not open file.\n";
		return false;
	}
	
	while(csv_file){
		csv_file >> encryptedint[listlength];
		csv_file >> comma;
		listlength++;
	}
	listlength--;
	cout << endl << "Length of list = " << listlength << endl;	
	return true;
	
}
