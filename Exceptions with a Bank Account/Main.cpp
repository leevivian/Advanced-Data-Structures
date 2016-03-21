/*	Name: Vivian Lee
	Compiler: Microsoft Visual Studio Express 2015

	Description: A file that contains the main method and 
	tests various cases of amounts deposited or withdrawn to produce 
	successful results and failed results (which result in exceptions).*/

#include <iostream>
#include <stdexcept>
#include "Account.h"
#include "AccountExceptions.h"

using namespace std;

// Main function that contains various cases of deposits and withdrawals
int main() {
	// Sets the account to have a default amount of $1000
	Account currentBal(1000);
	cout << "Account's Current Balance: $" << currentBal.getBalance() << endl;

	// 1) Demonstrates a successful deposit of money.
	try {
		currentBal.deposit(500);
		cout << "\nAccount's New Balance After Deposit: $" << currentBal.getBalance() << endl;
	} catch (exception& e) {
		cerr << e.what() << endl;
	}

	// 1.1) Tests the consequence of a negative amount of money.
	try {
		currentBal.deposit(-1);
	} catch (exception& e) {
		cerr << e.what() << endl;
	}

	// 2) Demonstrates a successful withdrawal of money.
	try {
		currentBal.withdraw(500);
		cout << "\nAccount's New Balance After Withdrawal: $" << currentBal.getBalance() << endl;
	} catch (exception& e) {
		cerr << e.what() << endl;
	}

	// 2.1) Tests the consequence of overdrawing.
	try {
		currentBal.withdraw(50000);
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}

	// 2.2) Tests the consequence of withdrawing using a negative amount.
	try {
		currentBal.withdraw(-1);
	} catch (exception& e) {
		cerr << e.what();
	}

	return 0;

}