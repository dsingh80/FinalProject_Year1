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
}

std::string CheckingAccount::getType(){
	return CheckingAccount::accountType;
}


