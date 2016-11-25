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
}

void Account::withdraw(double witAmount){
	/* WITHDRAW MONEY FROM ACCOUNT */
	
	//Check if amount available
	if(witAmount<=balance){
		//Withdraw money
		balance = balance - witAmount;
		//Tell them new balance
		std::cout << "Withdrew $" << getBalance() << " from " << accountType << " account." << std::endl;
		std::cout << "New Balance: $" << getBalance() << std::endl;
	}
	else{
		//Money not available
	}
}

User* Account::getOwner(){
	/* GET OWNER INFO */
	return owner;
}

void Account::setOwner(User* newOwner){
	/* GIVE CONTROL TO NEW USER */
	
	*(owner) = *(newOwner); // use copy constructors to make new owner
}
