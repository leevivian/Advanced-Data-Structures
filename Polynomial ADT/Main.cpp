/*	Name: Vivian Lee
	Compiler: Microsoft Visual Studio Express 2015

	Description: The main file asks the user to choose how he/she
	would like to manipulate the polynomial. All the different cases
	are listed here, and they call getPolynomial to create a polynomial
	to work with. For some cases, the user will be prompted to enter
	additional information. */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Polynomial.h"

using namespace std;

void getPolynomial(Polynomial &);
void multiplyPolynomial(Polynomial &, int integer);
void addPolynomial(Polynomial &, Polynomial &);
void negatePolynomial(Polynomial &);

int main() {
	bool repeat = true;
	string replay;
	Polynomial userInput;

	// User chooses an option for manipulating a polynomial
	while (repeat == true) {
		string input;
		int option;
		cout << "\nChoose which option you'd to execute:\n"
			"1. Return the highest degree within the polynomial\n"
			"2. Return the coefficient of a term within the polynomial\n"
			"3. Replace the coefficient of a term within the polynomial\n"
			"4. Multiply the polynomial by an integer\n"
			"5. Add two polynomials\n"
			"6. Print the polynomial\n"
			"7. Negate the polynomial\n" << endl;
	while (true) {
		cout << "\nOption number: ";
		getline(cin, input);
		stringstream myStream(input);
		if (myStream >> option) {
			break;
		}
		// If the user enters an invalid character(s), they are prompted to re-enter
		// their input.
		cout << "\nInvalid input; try again: " << endl;
	}
	// Returns the highest degree within the polynomial.
	if (option == 1) {	
		getPolynomial(userInput);
		cout << "\nHighest degree is: " << userInput.degree() - 1 << endl;
	}
	// Returns the coefficient of the term that is specified by the user's input of 
	// the desired exponent.
	if (option == 2) {	
		getPolynomial(userInput);
		int exponent = 0;
		while (true) {
			cout << "\nEnter the polynomial degree whose coefficient you'd like to return: ";
			getline(cin, input);
			stringstream newStream(input);
			if (newStream >> exponent) {
				break;
			}
			cout << "\nInvalid input; try again: " << endl;
		}
		cout << "\nYour coefficient is: " << userInput.coefficient(exponent) << endl;
	}
	// Changes the coefficient at a power that is specified by the user's input.
	if (option == 3) {	
		getPolynomial(userInput);
		cout << "\nYour current polynomial is: ";
		print(userInput);
		int newCoefficient;
		int power;
		while (true) {
			cout << "\nEnter the polynomial degree whose coefficient you'd like to change: ";
			getline(cin, input);
			stringstream newStream(input);
			if (newStream >> power) {
				break;
			}
			cout << "\nInvalid input; try again: " << endl;
		}
		while (true) {
			cout << "\nEnter its new coefficient value: ";
			getline(cin, input);
			stringstream newStream(input);
			if (newStream >> newCoefficient) {
				break;
			}
			cout << "\nInvalid input; try again: " << endl;
		}
		userInput.changeCoefficient(newCoefficient, power);
		cout << "\nYour polynomial is now: ";
		print(userInput);
	}
	// Multiplies the user's polynomial by their specified integer via input
	if (option == 4) {	
		getPolynomial(userInput);
		cout << "\nYour current polynomial is: ";
		print(userInput);
		int integer = 0;
		while (true) {
			cout << "\nEnter the value you would like to multiply your polynomial with: ";
			getline(cin, input);
			stringstream newStream(input);
			if (newStream >> integer) {
				break;
			}
			cout << "\nInvalid input; try again: " << endl;
		}
		multiplyPolynomial(userInput, integer);
		print(userInput);
	}
	// Adds two polynomials that are obtained via user input
	if (option == 5) {	
		getPolynomial(userInput);
		cout << "\nFirst polynomial: ";
		// Prints the first polynomial
		print(userInput);
		Polynomial userInput2;
		getPolynomial(userInput2);
		cout << "\nSecond polynomial: ";
		// Prints the second polynomial
		print(userInput);
		addPolynomial(userInput, userInput2);
		// Prints the added result
		print(userInput);
	}
	// Prints the polynomial that's available from user interaction in
	// the getPolynomial method.
	if (option == 6) {	
		getPolynomial(userInput);
		cout << "\nYour polynomial is: ";
		print(userInput);
	}
	// Negates the user's polynomial
	if (option == 7) {	
		getPolynomial(userInput);
		negatePolynomial(userInput);
		print(userInput);
	}
	// Asks user if they would like to run through the program again
	cout << "\nWould you like to play again? (y/n) \n";
	getline(cin, replay);
		if (replay == "y") {
			repeat = true;
		}
		else {
			repeat = false;
		}
	} return 0;
}

