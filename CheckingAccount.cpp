#include "CheckingAccount.h"
#include <sstream>
#include <iostream>

CheckingAccount::CheckingAccount(){
	accountType = "Checking";
}

CheckingAccount::CheckingAccount(std::string allInfo){
	// Extract account info from save information
	
	accountType = "Checking";
		
	std::stringstream extractStream;
	double newBal;

	std::cout << "Checking Account Save Info read: " << allInfo;
	extractStream << allInfo;

	// Read balance
	extractStream >> newBal;

	setBalance(newBal);
}

CheckingAccount::~CheckingAccount(){
	//DEALLOCATE HEAP MEMORY
	
	// Parent class(Account) deletes owner
}

std::string CheckingAccount::getType(){
	return CheckingAccount::accountType;
}

std::string CheckingAccount::getSaveInfo(){
	// return info to write to save file
	
	std::stringstream saveInfo;
	
	// Get balance
	saveInfo << getBalance();

	saveInfo << "\n";

	return saveInfo.str();
}
