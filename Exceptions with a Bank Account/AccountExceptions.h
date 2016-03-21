/*	Name: Vivian Lee
	Compiler: Microsoft Visual Studio Express 2015

	Description: A header file that contains the exceptions that
	are thrown when a deposit is negative, a withdrawal is negative,
	or when an overdraw occurs.*/

#pragma once
#ifndef _ACCOUNTEXCEPTIONS_H
#define _ACCOUNTEXCEPTIONS_H
#include <iostream>
#include <stdexcept>

using namespace std;
// If a negative deposit occurs, this error message is thrown.  A message
// indicating an error is shown to the user.
class Exception_Negative_Deposit : public exception {
	public:
		virtual const char* what() const throw() {
			return "\nException: Unable to deposit a negative amount of money to account.";
		}
	};

// If an overdrawal occurs, this message is thrown.  A message
// indicating an error is shown to the user.
class Exception_Overdraw : public exception {
	public:
		virtual const char* what() const throw() {
			return "\nException: Insufficient funds for withdrawal from account.";
		}
	};

// If a negative withdrawal occurs, this exception is thrown. A message
// indicating an error is shown to the user.
class Exception_Negative_Withdraw : public exception {
	public:
		virtual const char* what() const throw() {
			return "\nException: Unable to withdraw a negative amount of money from account.\n";
		}
	};

#endif
