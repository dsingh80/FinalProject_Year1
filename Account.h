#ifndef ACCOUNT_H_EXISTS
#define ACCOUNT_H_EXISTS

#include <string>
#include "User.h"

class Account{
	public:
		
		Account();
		Account(std::string, User*);
		~Account(); // delete User

		// Add abstract class framework
		virtual std::string getType() = 0; // tells what type of account this is	

		// GENERAL METHODS
		double getBalance(); // check cash available
		void deposit(double); // deposit money
		void withdraw(double); // take out money

		// ACCESSORS & MODIFIERS
		User* getOwner();
		void setOwner(User*); // give user permission to access account

	protected:
		std::string accountType; // type of account
		User* owner; // owns the account
		double balance; // cash in account
		
};

#endif
