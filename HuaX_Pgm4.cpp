//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Assignment:  Program 4
// Program:     HuaX_Pgm3.cpp
// Due date:    10/16/2023
// Purpose:     The purpose of this program is to implement a process to validate a checksum typically used
//				for validating International Standard Book Number(ISBN) numbers
// Input:       Obtain inputs from the file NBSn.csv which are NBSN code
// Process:     From inputs, process to validate the right code
// Output:      Display yes if it is the right code / no if it is the wrong code
// Class:       CS2010
// Section:     1003
// Time:        11:58 pm
// Term:        Fall 2023
// Author:      Xuan Hua
// 
// Reflection:  I think that this assignment is quite complex. Specially, it takes me lots of time to use loop function in this assignment.
//              However, I can revise most of the knowledge I learned in zyBook.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int main() {
	ifstream inFS; // declare the variable inFS to enter and read the file
	ofstream outFS;  // declare the variable outFS to write on the file

	string isbn;  // declare string variables to contain the code in the file
	string takeOut;
	string numString;

	int i;  // declare iteration variable.
	int numChosen; // declare each number in the code in int variable
	int lastNum;  // declare the check degit in int variable

	cout << setw(20) << left << "ISBN" << "Is Valid?" << endl;  // create the table for ISBN and valid code
	cout << setw(40) << setfill('-') << "" << endl;
	cout << setfill(' ');

	inFS.open("ISBNs.csv");   // open the ISBNs.csv file
	if (!inFS.is_open()) {    // check whether it is open or not
		cout << "could not open ISBNs";
		return 1;
	}
	outFS.open("outISBNs.csv"); // create and open the outISBNs.csv to write the whole table after validation
	if (!outFS.is_open()) {
		cout << "could not open outISBNs";
		return 1;
	}



	while (!inFS.eof()) {   // loop to check is it at the end of file until the end to exit the loop
		int sum = 0;   // declare and initialize sum int variable = 0
		inFS >> isbn;   // input value from the file to isbn

		if (inFS.fail()) {  // check is it fail to assign value to isbn or not
			cout << "could not access data from ISBNs";
			break;
		}


		takeOut = isbn.substr(0, 13);  // assign all che digit under string variable of takeOut


		for (i = 0; i < 13; ++i) { // loop to take all the digits from the file and assign to the table
			numString = takeOut.at(i);
			numChosen = stoi(numString);

			if ((i % 2 == 0) && (i != 12)) {
				cout << numChosen;
				outFS << numChosen;
				sum = sum + (numChosen * 1);
				if (i == 2 || i == 4 || i == 6) {
					cout << "-";
					outFS << "-";
				}
			}

			if (i % 2 != 0) {
				cout << numChosen;
				outFS << numChosen;
				sum = sum + (numChosen * 3);
			}
		}
				
			cout << "-" << numChosen; // the number 13 or index 12
			outFS << "-" << numChosen;

			// calculation to validate the each line of code
			if (sum % 10 != 0) {
				sum = 10 - sum % 10;
			}
			else {
				sum = sum % 10;
			}

			lastNum = numChosen;
			if (sum == lastNum) {
				cout << "   Yes" << endl;
				outFS << "   Yes" << endl;
			}
			else {
				cout << "   No" << endl;
				outFS << "   No" << endl;
			}
			

	}

	outFS.close();
	inFS.close();
	return 0;
}