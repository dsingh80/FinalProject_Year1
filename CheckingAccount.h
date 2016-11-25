#ifndef CHECKING_ACCOUNT_H_EXISTS
#define CHECKING_ACCOUNT_H_EXISTS

#include "Account.h"
#include <string>

class CheckingAccount : public Account {
	public:
		CheckingAccount();
		CheckingAccount(User*); // initialize with an owner
		~CheckingAccount();
		
		std::string getType();

	private:
		
		
};

#endif
