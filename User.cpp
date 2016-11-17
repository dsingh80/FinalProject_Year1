#include "User.h"
#include <sstream>

User::User(){
	firstName = "";
	lastName = "";
	
	birthDate = new Date();
	address = new Address();

	setPassword(); // calculate password key
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

	return fullInfo.str();
}



std::string User::getFullName(){
	/* GET USER'S FULL NAME */
	
	//stringstream makes concatenation easy
	std::stringstream concatStream;
	
	concatStream << getFirstName() << " " << getLastName();
	
	return concatStream.str();
}


void User::setPassword(){
	/* CALCULATE PASSWORD KEY */
}



/**********************************************************/
/*------------------ACCESSORS & MODIFIERS-----------------*/
/**********************************************************/

std::string User::getPassword(){
	return password;
}



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
