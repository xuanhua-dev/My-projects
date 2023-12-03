//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Assignment: Program 5
// Program:    HuaX_pgm5
// Due date:   10/23/2023
// Purpose:    The purpose of this program is to do analysis of TSLA stock price in the month of August of 2023
// Input:	   Obtain input such as price, date from pgm5.txt
// Process:	   From the price and date, use file I/O to open file and take information, then use parallel arrays, for loops to indicate date and price.
// Output:     Output price, date, average price, maximum price, minimum price
//
// Class:           CS2010
// Section:         1003
// Time:            12:30 pm
// Term:            Fall 2023
// Author:          Xuan Hua
// 
// Reflection:      I think that this assignment is quite complex. Specially, it takes me lots of time to use parallel array in this assignment.
//                  However, I can revise most of the knowledge I learned in zyBook.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int main() {

	ifstream infile; // declare infile as stream class to access file

	const int MAX_TRADINGDAYS = 23; // declare and initialize MAX_TRADINGDAYS as const int variable which is the element numbers of array

	double price [MAX_TRADINGDAYS]; // declare price as double variable

	string date [MAX_TRADINGDAYS]; // declare date as string array
	string maxpriceDate;  // declare maxpriceDate as string variable which is date has the maximum price in August
	string minpriceDate;  // declare minpriceDate as string variable which is date has the minimum price in August

	int numDays;  // declare numDays as int variable which is the numbers of trading date
	int maxnumDays = 0;  // declare maxnumDays as int variable which is the number of trading date has the hight price
	int minnumDays = 0;  // declare minnumDays as int variable which is the number of trading date has the low price

	double maxPrice = 0;  // declare maxPrice as double variable which is the maximum price in August
	double minPrice = 0;  // declare minPrice as double variable which is the minimum price in August
	double averagePrice = 0; // declare averagePrice as double variable which is the average price in August
	
	int i; // declare i as int variable to use as loop counting and array element in loop

	infile.open("pgm5.txt");  // open file

	// check whether the file is open or not
	if (!infile.is_open()) {
		cout << "Could not open file";
		return 1;
	}

	// loop run until the end of file
	while (!infile.eof()) {

		// loop to assign i variable to array
		for (i = 0; i < 23 ; ++i) {

			// take date from the file
			infile >> date[i];
			if (infile.fail()) {  // check is the assignment fail or not
					cout << "could not assign the data";
					break;
			}

			// check date to replace numbers as words of month
			if (date[i].substr(0, 2) == "01") {
				date[i].replace(0, 3, "Jan-");
			}

			else if (date[i].substr(0, 2) == "02") {
				date[i].replace(0, 3, "Feb-");
			}

			else if (date[i].substr(0, 2) == "03") {
				date[i].replace(0, 3, "Mar-");
			}

			else if (date[i].substr(0, 2) == "04") {
				date[i].replace(0, 3, "Apr-");
			}

			else if (date[i].substr(0, 2) == "05") {
				date[i].replace(0, 3, "May-");
			}

			else if (date[i].substr(0, 2) == "06") {
				date[i].replace(0, 3, "Jul-");
			}

			else if (date[i].substr(0, 2) == "07") {
				date[i].replace(0, 3, "Jun-");
			}

			else if ( date[i].substr (0,2) == "08") {
				date[i].replace(0, 3, "Aug-");
			}

			else if (date[i].substr(0, 2) == "09") {
				date[i].replace(0, 3, "Sep-");
			}

			else if (date[i].substr(0, 2) == "10") {
				date[i].replace(0, 3, "Oct-");
			}

			else if (date[i].substr(0, 2) == "11") {
				date[i].replace(0, 3, "Nov-");
			}

			else if (date[i].substr(0, 2) == "12") {
				date[i].replace(0, 3, "Dec-");
			}

			// take price from the file
			infile >> price[i];  // assign the price from the file

			if (infile.fail()) {
				cout << "could not assign the data"; // check the price assignment from the file
				break;
			}

			price[i] = fabs(price[i]); // make the price positive due to typos in the file

			// compare value to find maximum & minimum price, date, trading number day
			if (i == 0) {
				maxPrice = price[0];
				maxpriceDate = date[i];
				maxnumDays = i + 1;

				minPrice = price[0];
				minpriceDate = date[i];
				minnumDays = i + 1;

			}
			if (price[i] > maxPrice) {
				maxPrice = price[i];
				maxpriceDate = date[i];
				maxnumDays = i + 1;
			}
			if (price[i] < minPrice) {
				minPrice = price[i];
				minpriceDate = date[i];
				minnumDays = i + 1;
			}

			numDays = i + 1;

			// calculate average price of August;
			averagePrice = averagePrice + price[i];

			if (i == 22) {
				averagePrice = averagePrice / MAX_TRADINGDAYS;
			}
			

			// output trading number days; date; price; average price; maximum & minimum price, date, trading number day
			cout << "Day " << numDays  << " ";

			cout << date[i];

			cout << " TSLA was trading at $" << price[i] << endl;

		}

		cout << "TSLA was trading as high as " << maxPrice << " on Day " << maxnumDays << " " << maxpriceDate << "." << endl;
		cout << "TSLA was trading as low as " << minPrice << " on Day " << minnumDays << " " << minpriceDate << "." << endl;
		cout << "The 23" << "-day average price in August of TSLA is " << fixed << setprecision (2) << averagePrice << "." << endl;

		break;

	}

	infile.close();

	return 0;
}