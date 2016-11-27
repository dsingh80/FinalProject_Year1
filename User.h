#ifndef USER_H_EXISTS
#define USER_H_EXISTS

#include "Date.h"
#include "Address.h"

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


		//ACCESSORS & MODIFIERS
		void setKey(); // create passkey for save file
		std::string getKey(); // return passkey for save file
		
		void setFirstName(std::string);
		std::string getFirstName()
;
		void setLastName(std::string);
		std::string getLastName();
		
		void setBirthDate(Date*); // calls Date copy constructor
		void setBirthDate(std::string);
		std::string getBirthDate(); // calls Date.toString()
		Date* getBirthDateObject(); // returns pointer to birthDate instance

		void setAddress(Address*); // calls Address copy constructor
		void setAddress(std::string);
		std::string getAddress(); // calls Address.toString()
		Address* getAddressObject(); // returns pointer to address instance


	private:
		std::string firstName;
		std::string lastName;

		std::string password; // USER-INPUTTED pass word to account
		
		Date* birthDate; // on heap
		Address* address; // on heap

		//Used to access saved information
		//NOT USER INPUTTED
		std::string key; // calculated after first and last name are known;
		
		void setPassword(); // calculate password
};

#endif
