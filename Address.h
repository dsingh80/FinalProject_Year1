#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS

#include <string>

class Address{
	public:
		Address();
		Address(std::string); // extracts needed information
		Address(const Address&);
		~Address(); //empty destructor
		
		std::string toString(); // return formatted address

		//ACCESSOR METHODS
		std::string getLineOne();
		std::string getLineTwo();
		std::string getCity();
		std::string getState();
		int getZipCode();
		
		//MODIFIER METHODS
		void setLineOne(std::string);
		void setLineTwo(std::string);
		void setCity(std::string);
		void setState(std::string);
		void setZipCode(int);
		void setZipCode(std::string); // incase a string is passed. Converts to string
		
	private:
		std::string lineOne;
		std::string lineTwo;
		std::string city;
		std::string state;
		int zipCode;

};


#endif
