#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(){
	accountType = "Checking";
}

CheckingAccount::CheckingAccount(User* firstUser){
	accountType = "Checking";
	setOwner(firstUser);
}

CheckingAccount::~CheckingAccount(){
	//DEALLOCATE HEAP MEMORY
	
	// Parent class(Account) deletes owner
}

std::string CheckingAccount::getType(){
	return CheckingAccount::accountType;
}


