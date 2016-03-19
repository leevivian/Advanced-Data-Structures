/*	Name: Vivian Lee
	Compiler: Microsoft Visual Studio Express 2015

	Description:  This file contains a default constructor for the
	polynomial and other methods corresponding to manipulating
	the polynomial. */

#include <iostream>
#include <string>
#include "Polynomial.h"

using namespace std;

// Constructor that creates a basic polynomial that is of exponent 1
// and coefficient equal to 1.
Polynomial::Polynomial() {
	degPoly = 1;
	coeffPoly = new int[degPoly];
	for (int i = 0; i < degPoly; i++) {
		coeffPoly[i] = 1;
	}
}

// Gets an entire polynomial by interacting with the user to obtain the
// degree and coefficient of each term in the polynomial.
void getPolynomial(Polynomial & polynomial) {
	int degree = 0;
	int highestDeg = 0;
	int coefficient = 0;
	int i = 0;
	vector<int> coefficients;
	string input;

	// Asks for the maximum degree in the polynomial to create appropriate
	// amount of terms
	while (true) {
		cout << "\nWhat is the maximum degree of your polynomial?: ";
		getline(cin, input);
		stringstream myStream(input);
		if (myStream >> degree) {
			highestDeg = degree + 1;
			break;
		}
		// If an invalid character is entered, the user will be prompted to
		// re-enter the input.
		cout << "\nInvalid input; try again: " << endl;
	}
	do {
		// Asks for the coefficient of each existing term
		while (true) {
			cout << "\nEnter the coefficient of the x^" << i << " term: ";
			getline(cin, input);

			stringstream myStream(input);
			if (myStream >> coefficient)
				break;
			cout << "\nInvalid input; try again: " << endl;
		}
		coefficients.push_back(coefficient);
		i++;
	} while (i < degree + 1);

	Polynomial newPoly(highestDeg, coefficients);
	polynomial = newPoly;
}

// Constructor that creates a polynomial using the input of a specific degree
// and coefficient, received from the user.
Polynomial::Polynomial(const int degree, const vector<int> coefficient) {
	degPoly = degree;
	coeffPoly = new int[degPoly];
	for (int i = 0; i < degree; i++) {
		coeffPoly[i] = coefficient[i];
	}
}

// Method that returns the highest degree within the polynomial
int Polynomial::degree() const {
	return degPoly;
}

// Method that returns the coefficient of the term that the user specifies
// via the exponent he/she input.
int Polynomial::coefficient(const int power) const {
	int poly_coeff = 0;
	poly_coeff = coeffPoly[power];
	return poly_coeff; 
}

// Method that replaces the coefficient of the term that the user specifies
// via the exponent he/she input.
void Polynomial::changeCoefficient(const int newCoefficient, const int power) {
	if (power > degPoly) {
		cout << "A term with the specified degree does not exist within your polynomial." << endl;
	}
	else {
		// The current coefficient at the specified exponoent
		// gets set to the newly determined coefficient 
		coeffPoly[power] = newCoefficient;
	}
}

// Method that multiplies a polynomial by a specified integer from user input.
void multiplyPolynomial(Polynomial & polynomial, int integer) {
	cout << "\nMultiplication: ";
	cout << integer << " * (";
	print(polynomial);
	cout << ") = ";
	polynomial.multiply(integer);
}

// Multiply operation within Polynomial class, called from multiplyPolynomial
void Polynomial::multiply(const int integer) const {
	for (int i = 0; i < degPoly; i++) {
		// Multiplies each term's coefficient by the given integer
		coeffPoly[i] = integer * coeffPoly[i];
	}
}

// Method that adds two polynomials together
void addPolynomial(Polynomial & firstPoly, Polynomial & secondPoly) {
	cout << "\nAddition: ";
	print(firstPoly);
	cout << " + ";
	print(secondPoly);
	cout << " = ";
	firstPoly.add(secondPoly);
}

// Add operation within Polynomial class, called from addPolynomial
void Polynomial::add(const Polynomial secondPoly) {
	// Determines which polynomial has the higher degree
	int largerDeg = (degPoly > secondPoly.degPoly) ? degPoly : secondPoly.degPoly;
	degPoly = largerDeg; 
	// Add together the corresponding terms with the same degree
	for (int i = 0; i < largerDeg; i++) {
		coeffPoly[i] = coeffPoly[i] + secondPoly.coeffPoly[i];	
	}
}
// Method for printing out polynomials
void print(Polynomial polynomial) {
	for (int i = polynomial.degree(); i > 1; i--) {
		if (polynomial.coeffPoly[i - 1] > 0) {	
			cout << polynomial.coeffPoly[i - 1] << "x^" << i - 1 << " + ";
		}
		//For printing negative numbers
		else if (polynomial.coeffPoly[i - 1] < 0) {
			cout << " " << polynomial.coeffPoly[i - 1] << "x^" << i - 1;
		}
		else {
			cout << "";
		}
	}
	// Prints the x^0 term, if it is not 0
	if (polynomial.coeffPoly[0] != 0)
		cout << " " << polynomial.coeffPoly[0];
}

// Method for negating the polynomial
void negatePolynomial(Polynomial & polynomial) {
	cout << "\nYour current polynomial is: ";
	print(polynomial);
	cout << "\nYour new negated polynomial is: ";
	polynomial = -polynomial;
}

// Overloads the negation operator
Polynomial Polynomial::operator -() const {
	// Set a new polynomial that is labeled as negated
	Polynomial negation;
	negation.degPoly = degPoly;
	negation.coeffPoly = new int[degPoly];
	// For loop that negates each existing term's coefficient
	for (int i = 0; i < degPoly; i++) {
		negation.coeffPoly[i] = coeffPoly[i] * -1;
	}
	return negation;
}


