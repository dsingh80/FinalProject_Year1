#ifndef BANK_H_EXISTS
#define BANK_H_EXISTS

#include "CheckingAccount.h"
#include "User.h"
#include "Date.h"
#include <string>

class Bank{
	public:
		Bank();
		~Bank();
		
		void login(); // retrieve user info
		void logout(); // save user info

		void NewCheckingAccount(); // make new checking account
		void CloseCheckingAccount(); // remove checking account

		void depositMoney(); // put in money. Checks if the user has any money to deposit
		
	private:
		User currentUser; // owner of current accounts
		CheckingAccount* checking; // Checking account
		double pocketCash; // cash on hand
		
};

#endif
