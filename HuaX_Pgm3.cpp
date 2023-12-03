//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Assignment:  Program 3
// Program:     HuaX_Pgm3.cpp
// Due date:    10/09/2023
// Purpose:     The purpose of this program is to calculate the payment for choices of coffee mixing with one of three coffee strength.
// Input:       Obtain input from user: choice of coffee, coffee strength.
// Process:     From input of choice of coffee and coffee strength, the program calculate the payment for user's coffee.
// Output:      Display details of the price of coffee, owe if user doesn't pay enough, money change if user has excessive pay.
// Class:       CS2010
// Section:     1003
// Time:        12:30 pm
// Term:        Fall 2023
// Author:      Xuan Hua
// 
// Reflection:  I think that this assignment is quite complex. Specially, it takes me lots of time to use loop function in this assignment.
//              However, I can revise most of the knowledge I learned in zyBook.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	const double brewedPrice = 2.93;      // declare and initialize basic of coffee as constant variables
	const double espressoPrice = 4.39;
	const double cappuchinoPrice = 4.99;
	const double lattePrice = 5.47;

	string userChoice;      // declare all necessary variables for choice of coffee and coffee strength
	string coffeeChoice;
	string userStrength;
	string coffeeStrength;

	double coffeeCost;           // declare all necessary variables for payment
	double basiccoffeePrice = 0;
	double additionCost;
	double amountPaid = 0;
	double owe;
	double change;

	int space;

	while ( (userChoice != "q") && (userChoice != "Q") ) {
		cout << setw(44) << setfill('-') << "" << endl;
		cout << setfill(' ');

		cout << "B - Brewed" << setw(10) << brewedPrice << endl;     // output the menu of coffee for user to choose
		cout << "E - Espresso" << setw(8) << espressoPrice << endl;
		cout << "C - Cappucinno" << setw(6) << cappuchinoPrice << endl;
		cout << "L - Latte" << setw(11) << lattePrice << endl;
		cout << "Q - Quit" << endl;

		cout << setw(44) << setfill('-') << "" << endl;
		cout << setfill(' ');

		cout << "Enter your choice of coffee: ";     // input choice of coffee as userChoice variable
		cin >> userChoice;

			while ((userChoice != "b") && (userChoice != "B") && (userChoice != "e") && (userChoice != "E") && (userChoice != "c") && (userChoice != "C") && (userChoice != "l") && (userChoice != "L") && (userChoice != "q") && (userChoice != "Q")) {
				cout << "Invalid choice of coffee" << endl;          // validate choice of coffee
				cout << "Enter your choice of coffee: ";
				cin >> userChoice;
			}
			if ((userChoice == "b") || (userChoice == "B")) {
				coffeeChoice = "Brewed";
				basiccoffeePrice = brewedPrice;
			}
			else if ((userChoice == "e") || (userChoice == "E")) {
				coffeeChoice = "Espresso";
				basiccoffeePrice = espressoPrice;
			}
			else if ((userChoice == "c") || (userChoice == "C")) {
				coffeeChoice = "Cappucinno";
				basiccoffeePrice = cappuchinoPrice;
			}
			else if ((userChoice == "l") || (userChoice == "L")) {
				coffeeChoice = "Latte";
				basiccoffeePrice = lattePrice;
			}
			else if ((userChoice == "q") || (userChoice == "Q")) {     // quit the program
				cout << "Goodbye" << endl;
				break;
			}

			cout << setw(44) << setfill('-') << "" << endl;
			cout << setfill(' ');

			cout << "1 - Light, 2 - Regular, 3 - Dark: " << endl;    // list coffee strength

			cout << setw(44) << setfill('-') << "" << setfill(' ') << endl;
			cout << setfill(' ');

			cout << "Select your coffee strength: "; // input coffee strength
			cin >> userStrength;

			while ((userStrength != "1") && (userStrength != "2") && (userStrength != "3")) {      // validate coffe strength
				cout << "Invalid coffee strength" << endl;
				cout << "Select your coffee strength: ";
				cin >> userStrength;
			}

			if (userStrength == "1") {       // input userStrength for coffee strength and additional cost for each type
				coffeeStrength = "Light";
				additionCost = 0;
			}

			else if (userStrength == "2") {
				coffeeStrength = "Regular";
				additionCost = 0;
			}

			else if (userStrength == "3") {
				coffeeStrength = "Dark";
				additionCost = 0.23;
			}
			
			cout << endl << endl;



			cout << setw(44) << setfill('-') << "" << endl;
			cout << setfill(' ');

			coffeeCost = basiccoffeePrice + additionCost;        // calculate the cost of coffee
			owe = coffeeCost;         // firstly initialize owe as coffee cost

			cout << "You have ordered a " << coffeeStrength << " " << coffeeChoice << endl;     // output what kind of coffee ordered and the cost of it
			cout << "Your coffee will cost $" << coffeeCost << endl;

			cout << setw(44) << setfill('-') << "" << endl;
			cout << setfill(' ');

			cout << "Please enter amount paid: ";     // input the amount paid
			cin >> amountPaid;

			if (amountPaid > owe) {
				change = amountPaid - owe;           // calculate the change if amount paid is greater than the coffee cost
				cout << "Your change is: $" << change;   // output the change
			}

			while (amountPaid < owe) {
				owe = owe - amountPaid;       // calculate the owe if amount paid is smaller than the coffee cost
				cout << "You still owe: $" << owe << endl;    // output the owe
				cout << "Please enter amount paid: ";    // input the next amount paid if the previous one is not enough for the coffee cost
				cin >> amountPaid;

				if (amountPaid > owe) {
					change = amountPaid - owe;    // calculate and output the change if the later amount paid is greater than owe
					static_cast <int> (change);
					cout << "Your change is: $" << change;
					break;
				}
				else if (amountPaid == owe) {
					break;
				}
			}
			cout << endl;
			cout << setw(44) << setfill('-') << "" << endl;
			cout << setfill(' ');
			for (space = 0; space < 12; ++space) {
				cout << endl;
			}
	}

	return 0;
}
