//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Assignment:      Program 2
// Program:         XuanH_Pgm2
// Due date:        09/24/2023
// Purpose:         The purpose of this program is to calculate monthly loan payments
// Enter & Process: Obtain input from user: amount of loan, type of loan, length of loan and compute monthly payment.
// Results:         Display details of the loan along with the calculated payment, total paid over the life of the loan, and total interest paid.
//
// Class:           CS2010
// Section:         1003
// Time:            12:30 pm
// Term:            Fall 2023
// Author:          Xuan Hua
// 
// Reflection:      I think that this assignment is quite complex. Specially, it takes me lots of time to use boolean variable in this assignment.
//                  However, I can revise most of the knowledge I learned in zyBook.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <iomanip>
#include "XuanH_Pgm2.h"
using namespace std;

int main() {

	double amountLoan; // declare the double, int variables
	int numLength;
	int numMonth;
	int numYear;
	double interestRate{};
	double monthlyPay;
	double totalPay;
	double interestPaid;
	double interestperMon;

	string typeLoan; // declare typeLoan as string variable

	bool isamountCorrect; // declare bool variables
	bool istypeCorrect;
	bool islengthCorrect;
	bool amountCorrect;
	bool typeCorrect;
	bool lengthCorrect{};

	const double monthRate36 = 7.29;  // declare interest rate of morgage and auto loan as constant variables
	const double monthRate48 = 8.10;
	const double monthRate60 = 7.99;
	const double yearRate15 = 5.51;
	const double yearRate20 = 6.46;
	const double yearRate30 = 7.21;

	std::cout << "Enter amount to borrow: $" << flush; 
	cin >> amountLoan;                                  // input amount of loan want to borrow
	isamountCorrect = (amountLoan > 0);   // check whether amount of loan input is correct
	if (isamountCorrect) {
		amountCorrect = true;
		std::cout << "Enter type of loan (Enter: Auto or Home): " << flush;
		cin >> typeLoan;                                                        // input type of loan
		istypeCorrect = ((typeLoan == "Auto") || (typeLoan == "auto") || (typeLoan == "Home") || (typeLoan == "home") );   // check whether the type of loan input is correct
		if (istypeCorrect) {
			typeCorrect = true;
			if (typeLoan == "Auto" || typeLoan == "auto") {								// check wheter the input is Auto (auto) or another input
				std::cout << "Enter number of months (Enter: 36, 48, or 60): " << flush;
				cin >> numMonth;														 // input length of loan (number of month)
				numLength = numMonth;
				islengthCorrect = ((numLength == 36) || (numLength == 48) || (numLength == 60));	// check whether length of loan (number of month) input is correct
				if (islengthCorrect) {									
					lengthCorrect = true;

				}
			}
			else if ( (typeLoan == "Home") || (typeLoan == "home") ) {								// check wheter the input is Home (home) or another input
				std::cout << "Enter number of years (Enter: 15, 20, or 30): " << flush;
				cin >> numYear;															// input length of loan (number of year)
				numLength = numYear;
				islengthCorrect = ((numLength == 15) || (numLength == 20) || (numLength == 30));    //  check whether length of loan (number of year) input is correct
				if (islengthCorrect) {
					lengthCorrect = true;
				}
			}
			else {
				lengthCorrect = false;
			}
		}
		else {
			typeCorrect = false;
		}
	}
	else {
		amountCorrect = false;
	}

	if ( (amountCorrect == true) && (typeCorrect == true) && (lengthCorrect == true) ) {
		if ( (typeLoan == "Auto") || (typeLoan == "auto") ) {			// check type of loan to assign interest rate to each number of month
			if (numLength == 36) {
				interestRate = monthRate36;
			}
			else if (numLength == 48) {
				interestRate = monthRate48;
			}
			else if (numLength == 60) {
				interestRate = monthRate60;
			}
		}
		if ( (typeLoan == "Home") || (typeLoan == "home") ) {			// check type of loan to assign interest rate to each number of year
				if (numLength == 15) {
					interestRate = yearRate15;
				}
				else if (numLength == 20) {
					interestRate = yearRate20;
				}
				else if (numLength == 30) {
					interestRate = yearRate30;
				}
			numLength = numLength * 12;
		}
		if (amountLoan >= 200000) {							// make sure + 2.5% for interest rate when amount of loan is larger or same as $200,000
			interestRate = (interestRate + 2.5);
		}

		interestperMon = (interestRate / 100) / 12;				// calculate the interest per month
		monthlyPay = ((interestperMon * pow((1 + interestperMon), numLength))) / ((pow((1 + interestperMon), numLength) - 1)) * amountLoan;  // calculate the payment per month
		totalPay = monthlyPay * numLength;  // calculate total pay
		interestPaid = totalPay - amountLoan;   // calculate payment for interest


		std::cout << endl;
		std::cout << left << setw(4) << setfill('-') << ("") << " Loan Report for Auto Loan " << left << setw(4) << setfill('-') << ("") << endl;			// output the loan report section
		std::cout << endl;
		std::cout << setfill(' ');
		std::cout << setprecision(2) << fixed;
		std::cout << left << setw(24) << "Loan Amount:" << "$" << right << setw(10) << amountLoan << endl;		// output amount of loan
		std::cout << left << setw(24) << "Annual Interest Rate:" << "%" << right << setw(10) << interestRate << endl;  // output annual interest rate
		std::cout << left << setw(25) << "Number of Payments" << right << setw(10) << numLength << endl;		// output number of payments
		std::cout << left << setw(24) << "Monthly Payment:" << "$" << right << setw(10) << monthlyPay << endl;	     // output monthly payment
		std::cout << left << setw(24) << "Total Payment:" << "$" << right << setw(10) << totalPay << endl;      // output total payment
		std::cout << left << setw(24) << "Interest Paid:" << "$" << right << setw(10) << interestPaid << endl;     // output interest paid
	}
	else {
		std::cout << left << setw(18) << setfill('-') << ("") << " Error " << left << setw(18) << setfill('-') << ("") << endl; // output error for wrong input
		std::cout << "Something went wrong. Invalid input provided." << endl;
		std::cout << setw(42) << setfill('-') << flush;
	}

return 0;
}