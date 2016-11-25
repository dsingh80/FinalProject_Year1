#include "Account.h"
#include <string>

Account::Account(){
	accountType = "NULL";
	owner = new User();
	balance = 0.00;
}

Account::Account(std::string newType, User* firstUser){
	accountType = newType;
	setOwner(firstUser);
}

Account::~Account(){
	//Deallocate heap memory
	
	//Delete owner
	delete owner;
}

double Account::getBalance(){
	return balance;
}

void Account::deposit(double depAmount){
	/* DEPOSIT MONEY INTO ACCOUNT */	
	balance = balance + depAmount;
	
	//Tell them new balance
	std::cout << "Deposited $" << depAmount << " into " << accountType << " account." << std::endl;
	std::cout << "New Balance: $" << getBalance() << std::endl;

}

void Account::withdraw(double witAmount){
	/* WITHDRAW MONEY FROM ACCOUNT */
	
	//Check if amount available
	if(witAmount<=balance){
		//Withdraw money
		balance = balance - witAmount;
		//Tell them new balance
		std::cout << "Withdrew $" << witAmount << " from " << accountType << " account." << std::endl;
		std::cout << "New Balance: $" << getBalance() << std::endl;
	}
	else{
		//Money not available
		std::cout << "TRANSACTION FAILED: Insufficient funds in " << accountType << "account." << std::endl;
	}
}

User* Account::getOwner(){
	/* GET OWNER INFO */
	return owner;
}

void Account::setOwner(User* newOwner){
	/* GIVE CONTROL TO NEW USER */
	delete owner; // deallocate old owner
	owner = newOwner; // point to new owner
	//*(owner) = *(newOwner); // use copy constructors to make new owner
}
