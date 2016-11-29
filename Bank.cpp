#include "Bank.h"
#include <string>
#include <iostream>
#include <fstream>

Bank::Bank(){

	bool loginSuccessful = login(); // retrieve old information or make new user
	if(loginSuccessful == true){
		// LOGGED IN SUCCESSFULLY
		double pocketCash = 0.0;

		// ASK FOR AMOUNT OF MONEY THAT USER HAS ON HAND
		

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
			
			std::cout << "What can I do for you today?" << std::endl;	
			getline(std::cin, inputCmd); // ask for another command
		}

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
			std::string userinfo;
			getline(inputStream, userinfo);
			
			currentUser = new User(userinfo);
		
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
		std::cin.ignore();
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
	std::string firstName;
	std::string lastName;
	std::string password;
	// Ask for required information
	
	// First name
	// Last name
	
	// Address
	
	// Date
	
	// Password
	
}

void Bank::NewCheckingAccount(){
	// Open a new checking account
}

void Bank::CloseCheckingAccount(){
	// Close user's checking account
	
	// Withdraw any leftover balance
}

void Bank::depositMoney(){
	// Put money into account
	
	// Check if user has money on hand to deposit
		//Deposit money
	// Not enough money to deposit
}

