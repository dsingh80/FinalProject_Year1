#include "Address.h"
#include <sstream>
#include <iostream>
Address::Address(){
	//Use modifier methods separately to construct an address
	lineOne = "Line One";
	lineTwo = "Line Two";
	city = "City";
	state = "State";
	zipCode = 00000;
}

Address::Address(std::string fullInfo){
	/* EXTRACT INFORMATION CONSTRUCTOR */
	// ',' is the delimiter
	//Extract lineOne
	lineOne = fullInfo.substr(0, fullInfo.find(","));
	fullInfo = fullInfo.substr(fullInfo.find(",")+1);
	
	//Extract lineTwo
	lineTwo = fullInfo.substr(0, fullInfo.find(","));
	fullInfo = fullInfo.substr(fullInfo.find(",")+1);	

	//Extract city
	city = fullInfo.substr(0, fullInfo.find(","));
	fullInfo = fullInfo.substr(fullInfo.find(",")+1);
	
	
	state = fullInfo.substr(0, fullInfo.find(","));
	fullInfo = fullInfo.substr(fullInfo.find(",")+1);
	
	//convert string to int
	std::stringstream convertStream;
	convertStream << fullInfo;
	convertStream >> zipCode;
	
}

Address::Address(const Address& newAddress){
	lineOne = newAddress.lineOne;
	lineTwo = newAddress.lineTwo;
	city = newAddress.city;
	state = newAddress.state;
	zipCode = newAddress.zipCode;
}

Address::~Address(){
	//EMPTY DESTRUCTOR
}

std::string Address::toString(){
	//RETURN FORMATTED ADDRESS
	//Holds final string
	std::string formattedString;

	//format string with a stringstream for easy concatenation
	std::stringstream concatStream;
	concatStream << "\n\t" << Address::getLineOne() << "\n";
	if(Address::getLineTwo() != ""){
		concatStream << "\t" << Address::getLineTwo() << "\n";
	}
	concatStream << "\t"  << Address::getCity() << ", " << Address::getState() << " " << Address::getZipCode();

	//Convert stringstream to string
	formattedString = concatStream.str();

	return formattedString;
}

std::string Address::getSaveInfo(){
	std::stringstream saveInfo;
	
	saveInfo << getLineOne() << ",";
	saveInfo << getLineTwo() << ",";
	saveInfo << getCity() << ",";
	saveInfo << getState() << ",";

	return saveInfo.str();
}
// ACCESSOR METHODS //
std::string Address::getLineOne(){
	return Address::lineOne;
}

std::string Address::getLineTwo(){
	return Address::lineTwo;
}

std::string Address::getCity(){
	return Address::city;
}

std::string Address::getState(){
	return Address::state;
}

int Address::getZipCode(){
	return Address::zipCode;
}

// MODIFIER METHODS //
void Address::setLineOne(std::string tempLineOne){
	Address::lineOne = tempLineOne;
}

void Address::setLineTwo(std::string tempLineTwo){
	Address::lineTwo = tempLineTwo;
}

void Address::setCity(std::string tempCity){
	Address::city = tempCity;
}

void Address::setState(std::string tempState){
	Address::state = tempState;
}

void Address::setZipCode(int tempZipCode){
	Address::zipCode = tempZipCode;
}

void Address::setZipCode(std::string tempZipCode){
	/* CONVERTS STRING TO INT ZIPCODE */

	std::stringstream convertStream;
	convertStream << tempZipCode;
	convertStream >> zipCode; // output as int and assign to zipCode


}
