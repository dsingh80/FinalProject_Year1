#include "Account.h"
#include <string>

Account::Account(){
	accountType = "NULL";
	owner = new User();
}

Account::Account(std::string newType, User firstUser){
	accountType = newType;
	setOwner(firstUser);
}

Account::~Account(){
	//Deallocate heap memory
	
	//Delete owner
	delete owner;
}

void Account::deposit(double depAmount){
	/* DEPOSIT MONEY INTO ACCOUNT */	
}

void Account::withdraw(double witAmount){
	/* WITHDRAW MONEY FROM ACCOUNT */
	
	//Check if amount available
		//Withdraw money
		//Tell them new balance

		//Money not available
}

User* Account::getOwner(){
	/* GET OWNER INFO */
}

void Account::setOwner(User newOwner){
	/* GIVE CONTROL TO NEW USER */
}
