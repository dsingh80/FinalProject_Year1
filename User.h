#ifndef USER_H_EXISTS
#define USER_H_EXISTS

#include "Date.h"
#include "Address.h"
#include "CheckingAccount.h"

#include <string>
#include <iostream>

class User{

	public:
		
		//CONSTRUCTORS
		User();
		User(std::string, std::string, std::string); // pass in name of user and password
		User(std::string); // pass in all user info
		User(const User&); // copy constructor
		~User(); // Destructor


		//METHODS
		std::string toString(); // print user's information
		std::string getFullName(); // returns getFirstName() + getLastName() as 1 string
		
		std::string getSaveInfo(); // return information to save to file


		//ACCESSORS & MODIFIERS
		void setKey(); // create passkey for save file
		std::string getKey(); // return passkey for save file
	
		std::string getLogKey(); // set by setKey();
	
		void setFirstName(std::string);
		std::string getFirstName();

		void setLastName(std::string);
		std::string getLastName();
		
		void setPassword(std::string);
		std::string getPassword();
		
		void setBirthDate(Date*); // calls Date copy constructor
		void setBirthDate(std::string);
		std::string getBirthDate(); // calls Date.toString()
		Date* getBirthDateObject(); // returns pointer to birthDate instance

		void setAddress(Address*); // calls Address copy constructor
		void setAddress(std::string);
		std::string getAddress(); // calls Address.toString()
		Address* getAddressObject(); // returns pointer to address instance

		void setCheckingAccount(CheckingAccount*);
		void setCheckingAccount(std::string);
		CheckingAccount* getCheckingAccount();

	private:
		std::string firstName;
		std::string lastName;

		std::string password; // USER-INPUTTED pass word to account
		
		Date* birthDate; // on heap
		Address* address; // on heap

		//Used to access saved information
		//NOT USER INPUTTED
		std::string key; // calculated after first and last name are known;
		std::string logKey; // used to access statement
			
		CheckingAccount* checkingAcc;	
		void setPassword(); // calculate password
};

#endif
