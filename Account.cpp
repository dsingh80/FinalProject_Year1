#include "Account.h"
#include <string>
#include <iostream>

Account::Account(){
	accountType = "";
	balance = 0.00;
}


Account::Account(std::string newType){
	accountType = newType;
}

Account::~Account(){
	//Deallocate heap memory
}

void Account::deposit(double depAmount){
	/* DEPOSIT MONEY INTO ACCOUNT */	
	balance = balance + depAmount;
	
	//Tell them new balance
	std::cout << "Deposited $" << depAmount << " into account." << std::endl;
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

// BALANCE //
double Account::getBalance(){
	return balance;
}

void Account::setBalance(double newBal){
	balance = newBal;
}

std::string Account::getType(){
	return accountType;
}
