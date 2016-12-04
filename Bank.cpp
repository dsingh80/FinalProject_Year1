#include "Bank.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

Bank::Bank(){

	bool loginSuccessful = login(); // retrieve old information or make new user
	if(loginSuccessful == true){
		// LOGGED IN SUCCESSFULLY
		pocketCash = 0.0;
		std::string tempCash;
		// ASK FOR AMOUNT OF MONEY THAT USER HAS ON HAND
		std::cout << "How much money do you have on you at this moment?" << std::endl;
		std::cin >> tempCash;
	
		pocketCash = stringToDouble(tempCash);	

		std::string inputCmd;
		bool keepGoing = true;
	

		/* PRINT COMMANDS FOR USER */
		std::cout << "-----Valid Commands-----" << std::endl;
		std::cout << "deposit - deposit money into checking account" << std::endl;
		std::cout << "withdraw - withdraw money from checking account" << std::endl;
		std::cout << "balance - check balance of checking account" << std::endl;
		std::cout << "statement - print statement of transactions" << std::endl;
		std::cout << "quit - exit the program" << std::endl;
		std::cout << "------------------------" << std::endl;




	
		// Get a valid command to do
		std::cin.ignore();
		std::cout << "What can I do for you today?" << std::endl;
		getline(std::cin, inputCmd);

		while(keepGoing){
			// Check for valid commands
			if(inputCmd=="quit" || inputCmd == "exit"){
				keepGoing = false;
				break;
			}
			else if(inputCmd=="balance" || inputCmd == "check balance"){
				std::cout << "$" << currentUser -> getCheckingAccount() -> getBalance() << std::endl;
			}
			else if(inputCmd == "deposit"){
				depositMoney();
			}
			else if(inputCmd == "withdraw"){
				withdrawMoney();
			}
			else if(inputCmd == "logs" || inputCmd == "statement"){
				printStatement();
			}
			else if(inputCmd == "getKey"){
				std::cout << currentUser -> getKey() << std::endl;
			}
			else{
				std::cout << "Invalid command!" << std::endl;
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
		getline(std::cin, password);
		
		// FIND SAVE
		std::ifstream inputStream; // allows opening and reading files
		User* tempUser = new User(fName, lName, password); // used to make a pass key for real save file
		std::cout << "Key: " << tempUser -> getKey() << std::endl;	
		inputStream.open(tempUser->getKey()); // retrieve pass key for save file from User class
		
		delete tempUser; // deallocate temporary user

		if(inputStream.is_open()){
		// Save found
			// Load file
			std::string info;
			getline(inputStream, info);

			currentUser = new User(info);
			inputStream.close();
			return true;	
		}
		else{
		// Save not found
			// make new user
			std::cout << "\nERROR: User save file not found!" << std::endl;
			std::cout << "Would you like to make a new account?" << std::endl;
		
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
	std::ofstream outputStream;

	outputStream.open(currentUser->getKey());
	
	if(outputStream.is_open()){
		outputStream << currentUser -> getSaveInfo();
	}
	
	outputStream.close();
}

void Bank::makeNewUser(){
	// PROMPTS USER FOR INFORMATION TO CREATE NEW USER

	currentUser = new User();
	//std::cout << "Inside MakeNewUser()" << std::endl;
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

	std::cin.ignore();
	std::cout << "Please create a password: ";
	getline(std::cin, password);

	// Assign values
	currentUser -> setFirstName(firstName);
	currentUser -> setLastName(lastName);
	currentUser -> setAddress(addressStream.str());
	currentUser -> setBirthDate(birthDate);
	currentUser -> setPassword(password);
}

void Bank::depositMoney(){
	// Put money into account
	
	double depAmount = 0.0;
	std::string tempDep;
	std::cout << "How much money would you like to deposit?" << std::endl;
	
	while(depAmount<=0){
		std::cin >> tempDep;
		depAmount = stringToDouble(tempDep);
	}
	// Check if user has money on hand to deposit
	
	std::cout << "\tPocket Cash: " << pocketCash << std::endl;
	std::cout << "\tDepAmount: " << depAmount << std::endl;
	if(pocketCash>=depAmount){
		//Deposit money
		currentUser->getCheckingAccount()->deposit(depAmount);
		pocketCash = pocketCash - depAmount;

		//Log transaction
		std::ofstream logStream;
		logStream.open(currentUser->getLogKey(), std::fstream::app); // append log
		if(logStream.is_open()){
			logStream << "Deposited $" << depAmount << " into checking account.\tNew Balance: $" << currentUser->getCheckingAccount()->getBalance() << std::endl;
		}
		else{
			std::cout << "Failed to log transaction" << std::endl;
		}
			
		logStream.close(); // write log
	}
	else{
	// Not enough money to deposit
		std::string input;
		//Ask if they want to deposit all available funds
		std::cout << "Insufficient funds to deposit. Would you like to deposit all of the money on hand into your checking account?" << std::endl;
		std::cin >> input;
		
		if(input == "yes" || input == "Yes" || input == "YES"){
			//Deposit money
			currentUser->getCheckingAccount()->deposit(pocketCash);
			pocketCash = 0;
			
			//Log transaction
			std::ofstream logStream;
			logStream.open(currentUser->getLogKey(), std::fstream::app);
			if(logStream.is_open()){
				logStream << "Deposited $" << depAmount << " into checking account.\tNew Balance: $" << currentUser->getCheckingAccount()->getBalance() << std::endl;
			}
			else{
				std::cout << "Failed to log transaction" << std::endl;
			}
				
			logStream.close(); // write log

		}
		else{
			std::cout << "Deposit cancelled!" << std::endl;
		}
	}
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

	double witAmount = 0.0;
	std::string tempWit;
	std::cout << "How much money would you like to withdraw?" << std::endl;
	
	while(witAmount<=0){
		std::cin >> tempWit;
		witAmount = stringToDouble(tempWit);
	}
	// Check if user has money on hand to deposit
	if(currentUser->getCheckingAccount()->getBalance() >= witAmount){
		//Deposit money
		currentUser->getCheckingAccount()->withdraw(witAmount);
		pocketCash = pocketCash + witAmount;

		//Log transaction
		std::ofstream logStream;
		logStream.open(currentUser->getLogKey(), std::fstream::app);
		if(logStream.is_open()){
			logStream << "Withdrew $" << witAmount << " from checking account.\tNew Balance: $" << currentUser->getCheckingAccount()->getBalance() << std::endl;
		}
		else{
			std::cout << "Failed to log transaction" << std::endl;
		}
			
		logStream.close(); // write log
	}
	else{
	// Not enough money to deposit
		std::string input;
		//Ask if they want to deposit all available funds
		std::cout << "Insufficient funds available to withdraw. Would you like to withdraw all of the money from your checking account?" << std::endl;
		std::cout << "Current Balance: $" << currentUser->getCheckingAccount()->getBalance() << std::endl;
		
		std::cin >> input;
		
		if(input == "yes" || input == "Yes" || input == "YES"){
			//Deposit money
			currentUser->getCheckingAccount()->withdraw(currentUser->getCheckingAccount()->getBalance());
			pocketCash = pocketCash + witAmount;
			
			//Log transaction
			std::ofstream logStream;
			logStream.open(currentUser->getLogKey(), std::fstream::app);
			if(logStream.is_open()){
				logStream << "Withdrew $" << witAmount << " from checking account.\tNew Balance: $" << currentUser->getCheckingAccount()->getBalance() << std::endl;
			}
			else{
				std::cout << "Failed to log transaction" << std::endl;
			}
				
			logStream.close(); // write log

		}
		else{
			std::cout << "Withdraw cancelled!" << std::endl;
		}
	}
}

void Bank::printStatement(){
	// PRINT LOGS
	
	std::string tempString; // string to print

	std::ifstream inputStream;
	inputStream.open(currentUser->getLogKey());
	
	if(inputStream.is_open()){
		std::cout << "\n-------------STATEMENT-----------" << std::endl;
		while(getline(inputStream, tempString)){
			std::cout << tempString << std::endl;
		}
	}
	else{
		std::cout << "Could not find statement" << std::endl;
	}
}

double Bank::stringToDouble(std::string tempDouble){
	std::stringstream convertStream;
	convertStream << tempDouble;

	double actualDouble;

	convertStream >> actualDouble;

	return actualDouble;
}
