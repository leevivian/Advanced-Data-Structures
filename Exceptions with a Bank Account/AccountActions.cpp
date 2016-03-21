/*	Name: Vivian Lee
	Compiler: Microsoft Visual Studio Express 2015

	Description: A file that includes the implementation of
	account deposit and withdrawals. */

#include <iostream>
#include <stdexcept>
#include "Account.h"
#include "AccountExceptions.h"

using namespace std;

// Function that is responsible for deposits. If the amount passed in is greater 
// than zero (positive amount), then that specific amount is added to
// the existing balance. If the amount is less than zero (negative amount),
// then the Exception_Negative_Deposit is thrown.
double Account::deposit(double amount)throw(Exception_Negative_Deposit) {
	Exception_Negative_Deposit negDeposit;

	if (amount > 0) {
		cout << "\nSuccessful deposit of $" << amount;
		balance += amount;
	} else {
		cout << "\nFailed to deposit $" << amount;
		throw negDeposit;
	}
	return balance;
}

// Function that is responsible for withdrawals to the account.
// If the amount passed in is greater than the current balance, 
// Exception_Overdrawn is thrown. If the amount is less than zero
// (negative amount), then Exception_Negative_Withdraw is thrown.
// Otherwise, the amount will be subtracted from the exsiting balance.
double Account::withdraw(double amount)throw(Exception_Overdraw, Exception_Negative_Withdraw) {
	Exception_Overdraw overdraw;
	Exception_Negative_Withdraw negWithdraw;

	if (amount > balance) {
		cout << "\nFailed to withdraw $" << amount;
		throw overdraw;
	} else if (amount < 0) {
		cout << "\nFailed to withdraw $" << amount;
		throw negWithdraw;
	} else {
		cout << "\nSuccessful Withdrawal of $" << amount;
		balance -= amount;
	}

	return balance;
}