#include "User.h"
#include "Address.h"
#include "Date.h"

void testUser();
void testDate();
void testAddress();

int main(){
	//Initialize test classes
	testAddress();
	//testDate();
	//testUser();

	return 0;
}

void testUser(){
	User testUser = User();
	std::cout << "Test User: " << testUser.toString() << std::endl;

}

void testDate(){
	Date testDate = Date();
	std::cout << "Test Date: " << testDate.toString() << std::endl;
	
}

void testAddress(){
	Address testAddress = Address();
	std::cout << "Test Address: " << testAddress.toString() << std::endl;
	
}
