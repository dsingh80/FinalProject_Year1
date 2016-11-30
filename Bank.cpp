#include "Bank.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

Bank::Bank(){

	bool loginSuccessful = login(); // retrieve old information or make new user
	if(loginSuccessful == true){
		// LOGGED IN SUCCESSFULLY
		double pocketCash = 0.0;
		std::string tempCash;
		std::stringstream convertStream;
		// ASK FOR AMOUNT OF MONEY THAT USER HAS ON HAND
		std::cout << "How much money do you have on you at this moment?" << std::endl;
		std::cin >> tempCash;
		
		convertStream << tempCash;
		convertStream >> pocketCash;

		std::string inputCmd;
		bool keepGoing = true;
		
		// Get a valid command to do
		std::cout << "What can I do for you today?" << std::endl;
		getline(std::cin, inputCmd);

		while(keepGoing){
			// Check for valid commands
			if(inputCmd=="quit" || inputCmd == "exit"){
				keepGoing = false;
				break;
			}
			else if(inputCmd=="balance" || inputCmd == "check balance"){
				std::cout << currentUser -> getCheckingAccount() -> getBalance();
			}
			else if(inputCmd == "deposit"){
				depositMoney();
			}
			else if(inputCmd == "withdraw"){
				withdrawMoney();
			}
			
			std::cout << "What can I do for you today?" << std::endl;	
			getline(std::cin, inputCmd); // ask for another command
		}

		//save all info
		logout();

		/* DEALLOCATE ALL HEAP MEMORY. PROGRAM OVER */
		delete currentUser;

	}
	else{
		std::cout << "We hope to see you again!" << std::endl;
	}
}

Bank::~Bank(){
	//DEALLOCATE HEAP MEMORY
	
	//delete checking account
}

bool Bank::login(){
	// ASSIGNS A CURRENT USER
	

	std::string input = "";
	std::cout << "Are you a returning user?" << std::endl;
	getline(std::cin, input);

	// Check for previous save file
	if(input == "yes" || input == "Yes" || input == "YES"){
		std::string fName = ""; // first name
		std::string lName = ""; // last name
		std::string password; // number specific to person
		
		// Verify valid name entered
		while(fName == "" || lName == ""){
			std::cout << "What is your Full Name? (FORMAT: FirstName LastName)" << std::endl;
			std::cin >> fName;
			std::cin >> lName;
		}
		std::cout << "What is your password?" << std::endl;
		std::cin.ignore();
		std::cin >> password;
		
		// FIND SAVE
		std::ifstream inputStream; // allows opening and reading files
		User* tempUser = new User(fName, lName, password); // used to make a pass key for real save file
		
		inputStream.open(tempUser->getKey()); // retrieve pass key for save file from User class
		
		delete tempUser; // deallocate temporary user

		if(inputStream.is_open()){
		// Save found
			// Load file
			std::string info;
			getline(inputStream, info);

			currentUser = new User(info);
			
		}
		else{
		// Save not found
			// make new user
			std::cout << "\nERROR: User save file not found!" << std::endl;
			std::cout << "Would you like to make a new account?" << std::endl;
		
			// "Clear" previous input	
			std::cin.ignore();
			std::string tempInput = "";
			getline(std::cin, tempInput); // get answer to question

			if(tempInput == "yes" || tempInput == "Yes" || tempInput == "YES"){ // check if they said yes
				// Make new user
				makeNewUser();
				return true;
			}
			else{
				// Exit program
				return false;
			}
		
		}
	
		inputStream.close();	
	}
	else{
	// New user
		std::cout << "Would you like to make a new account?" << std::endl;
	
		// "Clear" previous input	
		std::string tempInput = "";
		getline(std::cin, tempInput); // get answer to question

		std::cout << "tempInput: |" << tempInput << std::endl;
		if(tempInput == "yes" || tempInput == "Yes" || tempInput == "YES"){ // check if they said yes
			// Make new user
			makeNewUser();
			return true;
		}
		else{
			// Exit program
			return false;
		}
	}
	return false;
}

void Bank::logout(){
	// Save user information
}

void Bank::makeNewUser(){
	// PROMPTS USER FOR INFORMATION TO CREATE NEW USER

	currentUser = new User();
	std::cout << "Inside MakeNewUser()" << std::endl;
	std::string firstName = "";
	std::string lastName = "";
	std::string password;
	std::string lineOne, lineTwo, city, state, zipCode;
	std::string birthDate;
		
	std::stringstream addressStream;
	// Ask for required information
	
	// First Name
	while(firstName == ""){
		std::cout << "What is your First Name?" << std::endl;
		std::cin >> firstName;
	}

	// Last Name
	while(lastName == ""){
		std::cout << "What is your Last Name?" << std::endl;
		std::cin >> lastName;
	}

	// Address
	std::cin.ignore();
	std::cout << "What is the first line of your address? (Ex. 123 Mayberry Lane)" << std::endl;
	getline(std::cin, lineOne);
	
	std::cin.ignore();
	std::cout << "What is the second line of your address? (Can leave blank)" << std::endl;
	getline(std::cin, lineTwo);

	std::cin.ignore();
	std::cout << "What city do you live in?" << std::endl;
	std::cin >> city;
	
	std::cin.ignore();
	std::cout << "What state do you live in?" << std::endl;
	std::cin >> state;
	
	std::cin.ignore();
	std::cout << "What is your zipCode?" << std::endl;
	std::cin >> zipCode;

	addressStream << lineOne << "," << lineTwo << "," << city << "," << state << "," << zipCode << ",";
	
	// Date
	std::cin.ignore();
	std::cout << "What is your date of birth following the form MM/DD/YYYY? (Ex. 01/22/1994 for January 22, 1994)" << std::endl;
	std::cin >> birthDate;

	// Assign values
	currentUser -> setFirstName(firstName);
	currentUser -> setLastName(lastName);
	currentUser -> setAddress(addressStream.str());
	currentUser -> setBirthDate(birthDate);
	
}

void Bank::depositMoney(){
	// Put money into account
	
	// Check if user has money on hand to deposit
		//Deposit money
		//Log transaction
	// Not enough money to deposit
		//Ask if they want to deposit all available funds
		//Log transaction
}

void Bank::withdrawMoney(){
	// Takes money out of account
	
	// Check if money is available in account
	 	//Withdraw money
	 	//Log transaction
	// Not enough money in account
		//Tell full balance
		//Ask if they want to withdraw full balance
		//Log transaction
}

std::string Bank::getTransactionLog(){
	return transactionLog;
}
