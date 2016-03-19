/*	Name: Vivian Lee
	Compiler: Microsoft Visual Studio Express 2015

 Description: This is the driver file that contains the
 main method, which calls different functions to input values into a
 vector, sorts the vector, and prints out its values. It also asks if
 the user would like to run the program again.*/

#include "Header.h"

/* Calls the functions readData, printVector, and selectionSort. 
Prompts user about running the program again after printing the 
sorted vector. */
int main() {
	bool repeat = true;
	string answer;
	vector <int> intVector;

	while (repeat == true) {

		readData(intVector);
		printVector(intVector);
		selectionSort(intVector);
		printVector(intVector);

		cout << "Would you like to play again? (y/n) \n";

		getline(cin, answer);
		if (answer == "y") {
			repeat = true;
			// Vector is cleared so that it doesn't contain the values
			// of the previous vector.
			intVector.clear();
		}
		else {
			repeat = false;
		}
	}
	return 0;
}