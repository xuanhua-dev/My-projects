//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: The purpose of this program is to create a CLR console application
// Process: The process of solving the problem is to take the inputs as a letter from the user
// to check whether the user's input same as the letters in secret word
//
// Class: CS2010
// Section: 1003
// Term: Fall 2023
// Author: Xuan Hua
//
// Reflection: This program is quiet complex and hard, but I find out it help me apply my C++ knowledge to create a fun game.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// declare libraries
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <cctype>

using namespace std;


// additional functions to output the horizontal bar in drawSnowman function
void horizontalline(int time) {
	char horizontalline = static_cast <char> (196);
	int i = 0;
	while (i < time) {
		cout << horizontalline;
		++i;
	}
}

// main function
int loadDictionary(string dict[]) { // load the dictionary of words from the data file into an array and declare dict[] as string array

	fstream infile;  // declare the infile variable as fstream class
	int wordcount = 0;   // declare wordcount as int variable to count word from the dictionary
	int i = 0; // declare i as int variable

	infile.open("pgm7.txt");  // open file "pgm7.txt"



	if (!infile.is_open()) {  // check whether the file opens or not

		cout << "Could not open file";

		return 1;
	}

	while (!infile.eof()) { // while loop to read input from the file and put them into the dict array


		if (!infile.fail()) { // if it fails to input words from the file to the array, it will output "could not assign data"
			infile >> dict[i];  // input data from the file to dict[] array
			++wordcount; // count words
			++i; // help to input data to appropriate elements in dict [] array
		}

		else {
			cout << "could not assign data"; // if it fails to assign data, output "could not assign data"
		}
	}

	infile.close(); // close file

	return wordcount; // return how many words in the file
}

void drawSnowman(int turn) {  // function to draw a snowman
	int time = 0;
	char verticalbar = static_cast <char> (179); // declare and initialize the verticalbar as char variable to draw the vertical bar

	char horizontalbar = static_cast <char> (196); // declare and initialize the horizontalbar as char variable to draw the horizontalline distinct from the same horizontalline function above

	char altitudeline1 = static_cast <char> (193); // declare and initialize the altitudeline1 as char variable to draw the altitude line with the horizontal line at the bottom

	char rightAngleline1 = static_cast <char> (218); // declare and initialize the rightAngleline1 as char variable to draw the upper right angle on the left side

	char rightAngleline2 = static_cast <char> (191); // declare and initialize the rightAngleline2 as char variable to draw the upper right angle on the right side

	char plusSign = static_cast <char> (197); // declare and initialize the plusSign as char variable to draw the plus sign

	char rightAngleline3 = static_cast <char> (192); // declare and initialize the rightAngleline3 as char variable to draw the lower left right angle

	char rightAngleline4 = static_cast <char> (217); // declare and initialize the rightAngleline4 as char variable to draw the lower left right angle

	char parallelline = static_cast <char> (186); // declare and initialize the parallelline as char variable to draw 2 parallel lines

	char leftfoot = static_cast <char> (188);  // declare and initialize the leftfoot as char variable to draw the left food of the snown man

	char rightfoot = static_cast <char> (200); // declare and initialize the rightfoot as char variable to draw the right food of the snown man

	if (turn >= 1) { // draw the hat

		cout << setw(6) << setfill(' ') << "" << rightAngleline1;
		time = 3;
		horizontalline(time);
		cout << rightAngleline2 << "\n";

		cout << setw(7) << setfill(' ') << verticalbar << setw(4) << setfill(' ') << verticalbar << "\n";

		cout << setw(5) << setfill(' ') << "" << horizontalbar << plusSign;
		time = 3;
		horizontalline(time);
		cout << plusSign << horizontalbar << "\n";


	}

	if (turn >= 2) { // draw the head

		cout << setw(11) << setfill(' ') << "|* *|" << "\n";
		cout << setw(7) << setfill(' ') << verticalbar << " | " << verticalbar << "\n";
		cout << setw(6) << setfill(' ') << rightAngleline1 << altitudeline1;
		horizontalline(3);
		cout << altitudeline1 << rightAngleline2 << "\n";
	}


	if (turn == 3) {  // draw the upper part of body additionally
		cout << setw(6) << setfill(' ') << "|" << setw(6) << setfill(' ') << "|" << "\n";
		cout << setw(6) << setfill(' ') << "|" << "  @  " << "|" << "\n";
		cout << setw(6) << setfill(' ') << verticalbar << setw(6) << setfill(' ') << verticalbar << "\n";
		cout << setw(5) << setfill(' ') << rightAngleline1 << altitudeline1;
		horizontalline(5);
		cout << altitudeline1 << rightAngleline2 << "\n";

	}

	if (turn == 4) { // draw the left hand additionally

		cout << setw(6) << setfill(' ') << "/|" << setw(6) << setfill(' ') << "|" << "\n";
		cout << setw(6) << setfill(' ') << "/ |" << "  @  " << "|" << "\n";
		cout << setw(5) << setfill(' ') << "/  " << verticalbar << setw(6) << setfill(' ') << verticalbar << "\n";
		cout << setw(5) << setfill(' ') << rightAngleline1 << altitudeline1;
		horizontalline(5);
		cout << altitudeline1 << rightAngleline2 << "\n";

	}

	if (turn >= 5) { // draw the right hand additionally

		cout << setw(6) << setfill(' ') << "/|" << setw(7) << setfill(' ') << "|\\" << "\n";
		cout << setw(6) << setfill(' ') << "/ |" << "  @  " << "| \\" << "\n";
		cout << setw(5) << setfill(' ') << "/  " << verticalbar << setw(6) << setfill(' ') << verticalbar << "  \\" << "\n";
		cout << setw(5) << setfill(' ') << rightAngleline1 << altitudeline1;
		horizontalline(5);
		cout << altitudeline1 << rightAngleline2 << "\n";

	}

	if (turn >= 6) { // draw the lower part of body additionally

		cout << setw(5) << setfill(' ') << "|" << setw(8) << setfill(' ') << "|" << "\n";
		cout << setw(5) << setfill(' ') << "|" << "   @   " << "|" << "\n";
		cout << setw(5) << setfill(' ') << verticalbar << setw(8) << setfill(' ') << verticalbar << "\n";
		cout << setw(5) << setfill(' ') << rightAngleline3;
		horizontalline(7);
		cout << rightAngleline4 << "\n";
	}
	
	if (turn == 7) { // draw the left foot additionally

		cout << setw(7) << setfill(' ') << parallelline << "\n";
		cout << setw(7) << setfill(' ') << leftfoot << "\n";

	}

	if (turn >= 8) { // draw the right foot additionally

		cout << setw(7) << setfill(' ') << parallelline << setw(4) << setfill(' ') << parallelline << "\n";
		cout << setw(7) << setfill(' ') << leftfoot << setw(4) << setfill(' ') << rightfoot << "\n";
	}
}

// Randomly select an index to the dictionary array (number
// between 0 and the number of words-1. Load the
// char array representing the secret word with letters of the // selected randomly secret word.
int setSecretWord(char secret[], string dict[], int wordcount) { 

	string randomword; // declare randomword to help the word randomnized from the dict[] array
	int i; // declare i as int variable

	randomword = dict[(rand() % wordcount)]; // input the randomized word to randomword variable

	// put the randomword to secret[] array
	for (i = 0; i < randomword.size(); ++i) {
		secret[i] = randomword.at(i);
	}


	return randomword.size(); // return the length of secretword
}
// Initialize each element of the char array of guessed letters
void initGuess(char guesses[], int secretlen) {
	int i;

	for (i = 0; i < secretlen; ++i) {
		guesses[i] = 95;
	}


}

// Get next guess from the player via the console window
char getGuess() {

	char letterGuess; // declare letterGuess as char variable
	string userGuess = ""; // declare userGuess as string variable and initialize/reset the variable to blank
	int i; // declare i as int variable
	bool rightInput = false; // declare rightInput as bool variable to verify the user's input in the right format

	cout << "Enter your guess:";
	getline (cin, userGuess); // take all the user's input in 1 time

	letterGuess = userGuess.at(0); // initialize letterGuess as the letter in the first index of userGuess

	if ((userGuess.length() == 1) && (isalpha(letterGuess))) { // verify the user's input in the right format
		rightInput = true;
	}
	else {
		rightInput = false;
	}

	while (rightInput == false) { // if user's input is false, then suggest to input again
		cout << "Wrong input. Only enter 1 letter.\nPlease enter again\n\n";
		cout << "Enter your guess:";
		getline(cin, userGuess);
		letterGuess = userGuess.at(0);

		if ((userGuess.length() == 1) && (isalpha(letterGuess))) {
			rightInput = true;
		}
		else {
			rightInput = false;
		}
	}


	if ((letterGuess >= 'A') && (letterGuess <= 'Z')) { // make sure that all the types of letter are appropriate to input
		letterGuess = tolower(letterGuess);
	}

	
	return letterGuess; // return the user's input
}

// Place the correctly guessed letter in the array of guessed
// letters in their correct spot.
bool recordGuess(char secret[], char guesses[], char letter, int secretlen) {
	int i;
	int have = 0; // declare have as int variable to check whether the user's input right or not

	// loop to compare user's input with the letters in secret[] array
	for (i = 0; i < secretlen; ++i) {
		if (secret[i] == letter) {

			guesses[i] = letter;
			++have;
		}
	}

	if (have > 0) { // if there is a same letter return true
		return true;
	}
	else {
		return false;
	}

}

// Show current game status, i.e., each guessed letter is
// shown in its correct position within the secret word.
// Letters that have not been guessed yet are shown as " _ "
// to indicate missing letters.
void showStatus(char guesses[], int secretlen) {
	int i;
	for (i = 0; i < secretlen; ++i) { // loop to show the status of the game

		cout << guesses[i] << " ";

	}
	cout << endl;
}

bool isWin(char guesses[], int secretlen) { // this function is to check whether the user win or not
	int i;
	int letterCount = 0;
	for (i = 0; i < secretlen; ++i) { // check how many letter in guess[] array
		if (isalpha(guesses[i])) {
			++letterCount;
		}
	}

	if (letterCount == secretlen) { // check whether the number of letter in guess[] array same as the letter initialize for secretlen variabe
		return true;
	}

	else if (letterCount != secretlen)  {
		return false;
	}
}

void showSecret(char secret[], int secretlen) { // function to reveal the secret word
	int i;
	cout << endl;
	for (i = 0; i < secretlen; ++i) { // loop to show the whole word in secret [] array

		cout << secret[i] << " ";

	}
	cout << endl;
}

void bubbleSort(string dictionary[], int size) { // function to sort the dict[] array in descending order
	int i;
	int j;
	string tempWord;

	for (i = 0; i < size-1; ++i) {

		for (j = 0; j < size-2-i; ++j) {
			if (dictionary[j] < dictionary[j + 1]) {
				tempWord = dictionary[j];
				dictionary[j] = dictionary[j + 1];
				dictionary[j + 1] = tempWord;
			}
		}
	}
}

int main() {
	char userInput = 'u';

	do {			// outer do-while loop to ask if the player wants to play again

		const int element = 100;
		const int lengthWord = 25;

		// string array
		string dict[element];


		// char array
		char secret[lengthWord];
		char guesses[lengthWord];
		char letter;

		// int variables
		int wordcount;
		int turn = 0;
		int secretlen;

		// bool variables
		bool correctWord;
		bool win;


		wordcount = loadDictionary(dict); // input the dictionary

		bubbleSort(dict, wordcount);

		system("cls"); // clear console

		secretlen = setSecretWord(secret, dict, wordcount); // put the word in secret[] and return wordcount

		initGuess(guesses, secretlen); // blank the guess array

		showStatus(guesses, secretlen); // show the blank


		do {					// inner loop to control the game

			letter = getGuess();  // input the letter's user

			correctWord = recordGuess(secret, guesses, letter, secretlen);

			if (correctWord == false) {
				++turn;
			}

			if ((turn > 0) && (correctWord == false)) {
				drawSnowman(turn);
				
			}

			win = isWin(guesses, secretlen);


			if ((win == false) && (turn > 8)) {
				showSecret(secret, secretlen);
				win = true;
			}

			if ((win == false) && (turn <= 8)) {
				showStatus(guesses, secretlen);
			}

		} while (win == false);

		if ((win == true) && (turn <= 8)) { // if user win output Congrats. You win!!.
			cout << setw(20) << setfill('-') << "";
			cout << "\nCongrats. You win!!.\n";
			cout << setw(20) << setfill('-') << "";
		}
		else {										 // if user lose output Game over. You lost.
			cout << setw(20) << setfill('-') << "";
			cout << "\nGame over. You lost.\n";
			cout << setw(20) << setfill('-') << "";
		}

		cout << endl << "Play again? [Y = play again]"; // if user want to play again press y or Y

		cin >> userInput;
		cin.ignore(); // make sure that y or Y input does not affect the system in the next round ( getGuess function )
	} while ((userInput == 'y') || (userInput == 'Y'));







	return 0;
}