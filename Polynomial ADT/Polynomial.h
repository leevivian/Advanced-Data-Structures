/*	Name: Vivian Lee
	Compiler: Microsoft Visual Studio Express 2015

	Description:  This header file contains header guards
	and declarations for each function being called in main. It also
	specifies what is public and what is private.*/

#include <vector>
#include <sstream>

using namespace std;

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

class Polynomial {
// The private variables for the polynomials are the degrees and 
// corresponding coefficients
private:
	int degPoly;
	int* coeffPoly;

public:
	// One default constructor for creating a polynomial of no terms
	Polynomial();
	// Constructor that creates a new polynomial based on the given degree
	// and coefficient from getPolynomial
	Polynomial(const int degree, const vector<int> coefficient);

	// Returns the highest degree within the user's polynomial
	int degree() const;
	// Returns the coefficient of the term whose power is specified
	// by the user
	int coefficient(const int power) const;
	// Changes the coefficient of the term whose power is specified 
	// by the user. The polynomial's coefficient is set to the 
	// new coefficient, is also specified by the user.
	void changeCoefficient(const int newCoefficient, const int power);
	// Multiplies the polynomial by an integer that is specified by the user
	void multiply(const int integer) const;
	// Adds together the like terms of two polynomials
	void add(const Polynomial polynomial_2);
	// Prints a polynomial
	friend void print(const Polynomial poly);
	// Overloads the negation operator
	Polynomial operator- () const;
};

#endif /* POLYNOMIAL_H_ */