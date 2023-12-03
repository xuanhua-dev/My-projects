#include <istream>
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Program: The purpose of this program is to calculate ticket sales, allocated expenses, amount profit from the game.
// Process: Obtain input from user: lower deck ticket price, upper dock ticket price and compute ticket sales, expenses, profits, 
//          then and outputs the amount of money from ticket sales, fot expenses and profits
// Result:  Display details of the ticket sales, expenses and profits.
//
//Class:    CS2010
//Section:  1003
//Term:     Fall 2023
//Author:   Xuan Hua
// 
//Reflection: Personally, I think this assignment is not really hard, it helps me review what I have studied in chapter 1 and 2.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#include <iostream>
using namespace std;
int main() {
	double sale;  // declare variables for sales, expenses and profits
	double expense;
	double profit;
	int upperTicket;
	int lowerTicket;

	const double upperCost = 5.75; // declare constant variables of ticket price for upper and lower decks
	const double lowerCost = 15.25;
	
	cout << "How many lower deck tickets were sold: " << flush;  // output the prompt for user to enter the lower deck tickets were sold
	cin >> lowerTicket; // input lower deck tickets were sold

	cout << "How many upper deck tickets were sold: " << flush; // output the prompt for user to enter the upper deck tickets were sold
	cin >> upperTicket;  // input upper deck tickets were sold

	sale = upperCost * upperTicket + lowerCost * lowerTicket; // compute sales from the tickets, expenses, profits
	expense = sale * 30 / 100;
	profit = sale * 70 / 100;

	cout << endl;
	cout << "Ticket Sales: $" << sale << endl; // output the amount of money from ticket sales, expenses and profits
	cout << "    Expenses: $" << expense << endl;
	cout << "     Profits: $" << profit << flush;


	return 0;
}