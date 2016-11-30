#ifndef CHECKING_ACCOUNT_H_EXISTS
#define CHECKING_ACCOUNT_H_EXISTS

#include "Account.h"
#include <string>

class CheckingAccount : public Account {
	public:
		CheckingAccount();
		CheckingAccount(std::string); // initialize with information and owner
		~CheckingAccount();
		
		std::string getType();
		std::string getSaveInfo(); // get info to write to save file
	private:
		
		
};

#endif
