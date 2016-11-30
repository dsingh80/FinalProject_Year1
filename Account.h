#ifndef ACCOUNT_H_EXISTS
#define ACCOUNT_H_EXISTS

#include <string>

class Account{
	public:
		
		Account();
		Account(std::string);
		~Account();

		// Add abstract class framework
		virtual std::string getType() = 0; // tells what type of account this is	
		virtual std::string getSaveInfo() = 0; // return string to write to save file


		// GENERAL METHODS
		void deposit(double); // deposit money
		void withdraw(double); // take out money

		// ACCESSORS & MODIFIERS
		double getBalance(); // check cash available
		void setBalance(double); // explicitly overwrite balance; only used for loading info from save

	protected:
		std::string accountType; // type of account
		double balance; // cash in account
		
};

#endif
