#include "User.h"
#include "CheckingAccount.h"
#include <string>
#include <sstream>

User::User(){
	firstName = "Unknown";
	lastName = "name";
	
	password = "password";

	birthDate = new Date();
	address = new Address();

	checkingAcc = new CheckingAccount();

	setKey(); // calculate password key
}

User::User(std::string newFirstName, std::string newLastName, std::string newPassword){
	firstName = newFirstName;
	lastName = newLastName;
	
	password = newPassword;

	birthDate = new Date();
	address = new Address();
	
	checkingAcc = new CheckingAccount();

	setKey();
}

User::User(std::string userInfo){
	// LOAD USER SAVE CONSTRUCTOR
	
	// Extract all info
	firstName = userInfo.substr(0, userInfo.find("|"));
	userInfo = userInfo.substr(userInfo.find("|"));
	
	lastName  = userInfo.substr(0, userInfo.find("|"));
	userInfo = userInfo.substr(userInfo.find("|"));
	
	password = userInfo.substr(0, userInfo.find("|"));
	userInfo = userInfo.substr(userInfo.find("|"));
	
	std::string tempBirthInfo = userInfo.substr(0, userInfo.find("|"));
	birthDate = new Date(tempBirthInfo);
	userInfo = userInfo.substr(userInfo.find("|"));

	std::string tempAddressInfo = userInfo.substr(0, userInfo.find("|"));
	address = new Address(tempAddressInfo);
	userInfo = userInfo.substr(userInfo.find("|"));

	checkingAcc = new CheckingAccount();
	setCheckingAccount(userInfo);
	setKey();
}

User::User(const User& otherUser){
	firstName = otherUser.firstName;
	lastName = otherUser.lastName;
	
	password = otherUser.password;

	birthDate = otherUser.birthDate;
	address = otherUser.address;
	
	checkingAcc = otherUser.checkingAcc;
	setKey();
}

User::~User(){
	/* DESTRUCTOR */

	delete birthDate;
	delete address;
	delete checkingAcc;
}



/********************************************************/
/*---------------------METHODS--------------------------*/
/********************************************************/

std::string User::toString(){
	/* PRINT USER INFORMATION */

	std::stringstream fullInfo;
	
	fullInfo << "\n\t" << getFullName();
	fullInfo << "\n\tBorn: " << getBirthDate();
	fullInfo << getAddress();
	fullInfo << "\n";

	return fullInfo.str();
}



std::string User::getFullName(){
	/* GET USER'S FULL NAME */
	
	//stringstream makes concatenation easy
	std::stringstream concatStream;
	
	concatStream << getFirstName() << " " << getLastName();
	
	return concatStream.str();
}

std::string User::getSaveInfo(){
	// Return info to write to save file
	
	std::stringstream saveInfo;

	saveInfo << getFirstName() << "|";
	saveInfo << getLastName() << "|";
	saveInfo << getPassword() << "|";
	saveInfo << getBirthDateObject()->toString() << "|";
	saveInfo << getAddressObject()->getSaveInfo() << "|";
	saveInfo << getCheckingAccount()->getSaveInfo();

	saveInfo << "\n";
	return saveInfo.str();
}

void User::setKey(){
	/* CALCULATE PASSWORD KEY */
	std::string tempKey = "";
	//concat(firstName, password, lastName);
	std::stringstream concatStream;
	
	concatStream << ".";
	concatStream << firstName << password << lastName;
	concatStream << ".sav";

	tempKey = concatStream.str();

	// Use hashing to jumble the key
	//key = std::hash<std::string>()(tempKey);
	key = tempKey;
}

std::string User::getKey(){
	/* GET PASS KEY FOR SAVE FILE */
	return key;
}



/**********************************************************/
/*------------------ACCESSORS & MODIFIERS-----------------*/
/**********************************************************/


// FIRST NAME //
void User::setFirstName(std::string tempFirstName){
	firstName = tempFirstName;
	setKey();
}

std::string User::getFirstName(){
	return firstName;
}



// LAST NAME //
void User::setLastName(std::string tempLastName){
	lastName = tempLastName;
	setKey();
}

std::string User::getLastName(){
	return lastName;
}

// PASSWORD //
std::string User::getPassword(){
	return password;
}

void User::setPassword(std::string newPass){
	password = newPass;
	setKey();
}

// BIRTH DATE //
void User::setBirthDate(Date* tempDate){
	*birthDate = *tempDate; // use copy constructor
}

void User::setBirthDate(std::string tempDateInfo){
	Date tempDate = Date(tempDateInfo);
	*(birthDate) = tempDate; // use copy constructor
}

std::string User::getBirthDate(){
	return birthDate->toString();
}

Date* User::getBirthDateObject(){
	return birthDate;
}



// ADDRESS //
void User::setAddress(Address* tempAddress){
	*address = *tempAddress; // use copy constructor to override address
}

void User::setAddress(std::string tempAddressInfo){
	Address tempAddress = Address(tempAddressInfo);
	*(address) = tempAddress; // use copy constructor to override address
}

std::string User::getAddress(){
	return address->toString();
}

Address* User::getAddressObject(){
	return address;
}

// CHECKING ACCOUNT //
void User::setCheckingAccount(CheckingAccount* newChecking){
	*checkingAcc = *newChecking;
}

void User::setCheckingAccount(std::string accinfo){
	delete checkingAcc;
	checkingAcc = new CheckingAccount(accinfo);
}

CheckingAccount* User::getCheckingAccount(){
	return checkingAcc;
}
