/*	Name: Vivian Lee
	Compiler: Microsoft Visual Studio Express 2015 

	Description: This is the driver file that contains the 
	main method, which receives the user's input and calls
	different functions to get the least frequent letter
	and its frequency, unique words and their frequencies,
	and the most frequent word and its frequency. It also
	prompts the user on whether or not they would like to
	run the program again with another input. */

#include "Header.h"

/* The main method which receives the user's input 
	 and calls the fucntions that have been
	 implemented in 1-1Functions.cpp. */
int main()
{
	string input;
	string replay;

	int count = 0;
	bool repeat = true;

	while (repeat == true) {
		cout << "Type in your string\n";
		getline(cin, input);

		getLeastFreqLetter(input);

		cout << "\nFrequency of Each Unique Word: " << endl;
		countWord *wordFreq = countWordFreq(input);
	
		cout << "\nWould you like to play again? (y/n) \n";
		getline(cin, replay);
		if (replay == "y") {
			repeat = true;
		} else {
			repeat = false;
		}
	} return 0;
}