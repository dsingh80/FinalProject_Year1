#include "Bank.h"
#include <string>
#include <iostream>
#include <fstream>

Bank::Bank(){

	login(); // retrieve old information or make new user
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
		}
		
			
		
		std::cout << "What can I do for you today?" << std::endl;	
		getline(std::cin, inputCmd); // ask for another command
	}
}

Bank::~Bank(){
	//DEALLOCATE HEAP MEMORY
	
	//delete checking account
}

void Bank::login(){
	// Check for previous save file
	
	// Save found
		// Load file
	// Save not found
		// make new user
}

void Bank::logout(){
	// Save user information
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

