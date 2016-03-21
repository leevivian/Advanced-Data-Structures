/*	Name: Vivian Lee	
	Compiler: Microsoft Visual Studio Express 2015

	Description: A header file containing a class that
	maintains an account balance and declares various
	functions that attempt to change the balance.*/

#ifndef _ACCOUNT_H
#define	_ACCOUNT_H
#include "AccountExceptions.h"

// A class named "Account" that maintains an account balance. Various
// functions, including deposits and withrdrawals, can be applied.
// Exceptions are thrown if an instance of an invalid case occurs.
class Account {
	private:
		double balance;
	public:
		// Initialize balance to 0
		Account() :balance(0) {}
		// Sets the balance to initialDeposit
		Account(double initialDeposit) :balance(initialDeposit) {}
		// Returns the current balance
		double getBalance() {
			return balance;
		}
		// Attempts to deposite the amount of money that is specified and 
		// is responsible for throwing an exception if the case happens to be negative 
		double deposit(double amount)throw(Exception_Negative_Deposit);
		// Attempts to withdraw the amount of money that is specified and is responsible for
		// throwing the appropriate exception when: the amount is greater than
		// the balance, or if the amount is negative
		double withdraw(double amount)throw(Exception_Overdraw, Exception_Negative_Withdraw);
};

#endif	