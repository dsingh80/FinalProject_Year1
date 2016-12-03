#ifndef ACCOUNT_H_EXISTS
#define ACCOUNT_H_EXISTS

#include <string>

class Account{
	public:
		
		Account();
		Account(std::string);
		~Account();

		// Add abstract class framework
		virtual std::string getSaveInfo() = 0; // return string to write to save file

		// GENERAL METHODS
		void deposit(double); // deposit money
		void withdraw(double); // take out money

		// ACCESSORS & MODIFIERS
		double getBalance(); // check cash available
		void setBalance(double); // explicitly overwrite balance; only used for loading info from save

		std::string getType(); // return accountType
	protected:
		std::string accountType;
		double balance; // cash in account
		
};

#endif
