//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Assignment: Program 6
// Program:    HuaX_pgm5
// Due date:   11/1/2023
// Purpose:    The purpose of this program is to read the grade of three different chapters of a class, analyze the grades
//			   by computing the total grades, finding the average, highst, lowest, and computing the ABC rate of the class.
// 
// Input:	   Obtain input as grades of three different chapters from roster.txt
// 
// Process:	   From the grades, use file I/O to open file and take information, then use function, arrays, for loops
//			   to calculate and present the grades in different format.
// 
// Output:     Output two tables and a summary. The first table indicates the grades of three different chapters and total grade of each student.
//			   The second table shows the percentage of three different chapters and total grade based on the maximum score of 50.
//			   Last one is the summary including the average, highest, lowest score, 
//
// Class:           CS2010
// Section:         1003
// Time:            10:00 pm
// Term:            Fall 2023
// Author:          Xuan Hua
// 
// Reflection:      I think that this assignment is quite complex. Specially, it takes me lots of time to use the combiniation of function and array in this assignment.
//                  However, I can revise most of the knowledge I learned in zyBook.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE_CLASS = 21; // declare and initialize SIZE_CLASS as global array.

// declare defined function readRosterAndComputeTotal to input all the grades of 3 chapters into 3 array
void readRosterAndComputeTotal (double chap1[], double chap2[], double chap3[], double totalGrade[], int arraysize) {  
	
	fstream infile;  // declare infile as fstream class
	int i;  // declare i as interger variable
	infile.open("roster.txt");   // open file roster.txt

	if (!infile.is_open()) {    // check the file whether is open or not
		cout << "could not open file";
	}

	for (i = 0; i < arraysize; ++i) {  // run loop to assign grades into 3 arrays
		infile >> chap1[i];
		infile >> chap2[i];
		infile >> chap3[i];
		if (infile.fail()) {   // check assignment is fail or not
			cout << "could not assign data";
			break;

		}

	}
	
	for (i = 0; i < arraysize; ++i) {   // assign total grade of 3 chapters into totalGrade variable
		totalGrade[i] = chap1[i] + chap2[i] + chap3[i];
	}

	infile.close();  // close file roster.txt
}

// declare printRoster as defined function to create the table of 3 chapters and the total grade
void printRoster(double chap1[], double chap2[], double chap3[], double totalGrade[], int arraysize) {

	int i;
	int studentNumber;  // declare studentNumber as int variable to count number of student in the file

	// output the base of table
	cout << "The original Roster:" << endl;
	cout << "Student #" << setw (7) << "Ch01" << setw(10) << "Ch02" << setw(10) << "Ch03" << setw(11) << "Total" << endl;
	cout << setw(50) << setfill('-') << "";
	cout << setfill(' ') << endl;

	for (i = 0; i < arraysize; ++i) {   // output the list of grades
		studentNumber = i + 1;
		cout << fixed << setprecision(2);
		cout << setw(2) << left << studentNumber << setw (15) << right << chap1[i] << setw(10) << chap2[i] << setw(10) << chap3[i] << setw(10)
			<< totalGrade[i] << endl;

	}

	cout << setw(50) << setfill('*') << "" << setfill(' ') << endl << endl;
}

// declare convertToPercentage as defined variable to transfer grades into percentage

void convertToPercentage(double chap1[], double chap2[], double chap3[], double totalGrade[], int arraysize) {

	int i;

	for (i = 0; i < arraysize; ++i) {   // loop to assign calculated percentage of grades into three array which contain the grades
		chap1[i] = chap1[i] / 15 * 100;
		chap2[i] = chap2[i] / 15 * 100;
		chap3[i] = chap3[i] / 20 * 100;
	}

	for (i = 0; i < arraysize; ++i) {    // loop to assign calculated percentage of total grades into totalGrade array
		totalGrade[i] = totalGrade[i] / 50 * 100;
	}

}

// declare printConvertedRosterWithLetterGrade as defined function to arrange grade for every student 
// and create the table representing all the grades in percentage form and rank

void printConvertedRosterWithLetterGrade(double chap1[], double chap2[], double chap3[], double totalGrade[], int arraysize) {
	string letterGrade [SIZE_CLASS];  // declare letterGrade as string variable to rank of every student
	int i;
	int studentNumber;

	// arrange rank for each student based on total grade

	for (i = 0; i < arraysize; ++i) {
		if (totalGrade [i] >= 92) {
			letterGrade [i] = "A";
		}
		
		else if (totalGrade[i] >= 82) {
			letterGrade [i] = "B";
		}

		else if (totalGrade[i] >= 72) {
			letterGrade [i] = "C";
		}

		else if (totalGrade[i] >= 62) {
			letterGrade [i] = "D";
		}

		else if (totalGrade[i] < 62) {
			letterGrade [i] = "F";
		}
	}

	// output the base of percent grade table
	cout << "The converted roster wih letter grade:" << endl;
	cout << "Student #" << setw (7) << "Ch01" << setw(10) << "Ch02" << setw(10) << "Ch03" << setw(11) << "Total" << setw(17) << "Letter Grade" << endl;
	cout << setw(64) << setfill('-') << "";
	cout << setfill(' ') << endl;

	for (i = 0; i < arraysize; ++i) {
		studentNumber = i + 1;
		cout << fixed << setprecision(2);
		cout << setw(12) << left << studentNumber;
		cout << setw(6) << left << chap1[i] << setw (4) << left << "%" << setw(6) << left << chap2[i] << setw (4) << left << "%" 
			<< setw(6) << left << chap3[i] << setw (4) << left << "%" << setw(6)<< totalGrade[i] << setw (4) << "%" << setw (4) << letterGrade [i] << endl;

	}

	cout << setw(64) << setfill('*') << "" << setfill(' ') << endl << endl;
}

// declare computeAvgGrade as defined function to output average total grade

double computeAvgGrade(double totalGrade[], int arraysize) {
	double avgGrade = 0;
	int i;
	for (i = 0; i < arraysize; ++i) {
		avgGrade = (avgGrade + totalGrade[i] );
	}
	return avgGrade / arraysize;
}

// declare findHighestScore defined function to output the highest total grade

double findHighestScore(double totalGrade [],int arraysize) {
	double maxScore = totalGrade[0];
	int i;

	for (i = 0; i < arraysize; ++i) {
		if (totalGrade [i]> maxScore) {
			maxScore = totalGrade[i];
		}
	}

	return maxScore;
}

// declare findLowestScore to output the lowest score based on total grade

double findLowestScore(double totalGrade[], int arraysize) {
	double minScore = totalGrade[0];
	int i;

	for (i = 0; i < arraysize; ++i) {
		if (totalGrade[i] < minScore) {
			minScore = totalGrade[i];
		}
	}

	return minScore;
}

// output computeABCRate defined function to output the ABC rate of the class

double 	computeABCRate(double totalGrade[], int arraysize) {
	int i;
	double abcRate = 0;  // declare and initialize abcRate as double variable = 0 to output ABC rate of the class

	for (i = 0; i < arraysize; ++i) {
		if (totalGrade[i] >= 72 ) {
			abcRate = abcRate + 1;
		}
	}

	return abcRate / SIZE_CLASS * 100;
}

int main() {
	const int arraysize = 21;   // declare arraysize as const int variable and initialize as 21
	double chap1 [arraysize];   // declare chap1 as double array to store grades of chapter 1
	double chap2 [arraysize];   // declare chap2 as double array to store grades of chapter 2
	double chap3 [arraysize];   // declare chap3 as double array to store grades of chapter 3
	double totalGrade [arraysize];    // declare totalGrade as double array to store total grades

	readRosterAndComputeTotal ( chap1, chap2, chap3, totalGrade, arraysize );   // declare caller of readRosterAndComputeTotal function

	printRoster(chap1, chap2, chap3, totalGrade, arraysize);  // declare caller of printRoster function

	convertToPercentage(chap1, chap2, chap3, totalGrade, arraysize); // declare caller of convertToPercentage function

	printConvertedRosterWithLetterGrade(chap1, chap2, chap3, totalGrade, arraysize);  // declare caller of printConvertedRosterWithLetterGrade function

	cout << "The average total score of the class is "   // output the average total score of the class
		<< computeAvgGrade(totalGrade, arraysize)
		<< "%" << endl;

	cout << "The highest score is "  // output the highest score
		<< findHighestScore(totalGrade, arraysize) << "%" << endl;
	
	cout << "The lowest score is "  // output the lowest score
		<< findLowestScore(totalGrade, arraysize) << "%" << endl;

	cout << "The ABC rate of the class is "  // output the ABC rate of the class
		<< computeABCRate(totalGrade, arraysize) << "%" << endl;

	return 0;
}