// Name: Nicholas Rosas
// Date: 12-17-15
// CSS-1 Fa15 Final Exam Prog 1
#include <iostream>
#include <vector>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

void fillVector(vector<string>& PW, ifstream& A_in);
/*
	Summary: Function fills a vector with values read from a file
	Precondition: Empty vector, file reader
	Postcondition: Filled vector
*/
void writeToFile(vector<string>& password, ofstream& A_out);
/*
	Summary: Function writes values stored in a vector to the output file
	Precondition: Vector either filled or not, output file stream
	Postcondition: Output file writes
*/
bool isCrackedPW(string currentPW, vector<string>& crackPW);
/*
	Summary: Function checks to see if a password is a password that has been cracked
	Precondition: Current password, vector (list) of passwords that have been cracked
	Postcondition: Returns true/false if password is cracked (true) or not cracked (false)
*/

int main()
{
	const int SIZE = 6;
	string possible[SIZE] = {"zymogenic","aboral","Santa","password1","Password!",
							  "ambystomidae"};
	vector<string>crackedPW;
	vector<string>goodPW;
	ifstream fin;
	ofstream fout;

	fin.open("passwords.txt");
	fout.open("good_words.txt");
	
	if(fin.fail() || fout.fail())
	{
		cout << "Error opening file\n";
		exit(1);
	}
	
	fillVector(crackedPW, fin);
	
	for(int ix = 0; ix < SIZE; ix++)
	{
		if(isCrackedPW(possible[ix], crackedPW))
		{
			continue;
		}
		else
		{
			goodPW.push_back(possible[ix]);
		}
	}

	writeToFile(goodPW, fout);
	
	
	fin.close();
	fout.close();

	return 0;
}


//*************************************
void fillVector(vector<string>& PW, ifstream& A_in)
{
	string str;
		
	while(A_in >> str)
	{
		PW.push_back(str);
	}

	
}// end fill Vector(_)
//*************************************
void writeToFile(vector<string>& password, ofstream& A_out)
{
	A_out << "Nicholas Rosas" << endl << endl;
	for(int ix = 0; ix < password.size(); ix++)
	{
		A_out << password[ix] << endl;
	}

} // end writeToFile()
//*************************************
bool isCrackedPW(string currentPW, vector<string>& crackPW)
{
	for(int ix = 0; ix < crackPW.size(); ix++)
	{
		if(currentPW == crackPW[ix])
		{
			return true;
		}
	}
	return false;

} // end isCrackedPW()
 
