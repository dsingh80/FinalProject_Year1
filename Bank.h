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
		
		bool login(); // retrieve user info
		void logout(); // save user info

		void makeNewUser();

		void depositMoney(); // put in money. Checks if the user has any money to deposit
		void withdrawMoney(); // checks if account has balance required

		std::string getTransactionLog(); // returns log of all transactions
		double stringToDouble(std::string); // converts to a double

	private:
		User* currentUser; // owner of current accounts
		std::string transactionLog = ""; // holds all information on transactions taken in current session
		double pocketCash = 0.0; // cash on hand
		
};

#endif
