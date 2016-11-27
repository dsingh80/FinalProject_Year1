#include "User.h"
#include <string>
#include <sstream>

User::User(){
	firstName = "Unknown";
	lastName = "name";
	
	password = "password";

	birthDate = new Date();
	address = new Address();

	setKey(); // calculate password key
}

User::User(std::string newFirstName, std::string newLastName, std::string newPassword){
	firstName = newFirstName;
	lastName = newLastName;
	
	password = newPassword;

	birthDate = new Date();
	address = new Address();
	
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

	setKey();
}

User::User(const User& otherUser){
	firstName = otherUser.firstName;
	lastName = otherUser.lastName;
	
	password = otherUser.password;

	birthDate = otherUser.birthDate;
	address = otherUser.address;
	
	setKey();
}

User::~User(){
	/* DESTRUCTOR */

	delete birthDate;
	delete address;
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


void User::setKey(){
	/* CALCULATE PASSWORD KEY */
	
	//concat(firstName, password, lastName);
	std::stringstream concatStream;
	concatStream << firstName << password << lastName;
	
	key = concatStream.str();
	
	// Use symmetric hashing to jumble the key
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
}

std::string User::getFirstName(){
	return firstName;
}



// LAST NAME //
void User::setLastName(std::string tempLastName){
	lastName = tempLastName;
}

std::string User::getLastName(){
	return lastName;
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
