#include "User.h"
#include "Address.h"
#include "Date.h"
#include "Bank.h"

void testUser();
void testDate();
void testAddress();


int main(){
	//Initialize test classes
	//testAddress();
	//testDate();
	//testUser();
	Bank();
	return 0;
}

void testUser(){
	User testUser = User();
	std::cout << "=====Test User=====\n1: " << testUser.toString() << std::endl;

	testUser.setFirstName("First");
	std::cout << "2: " << testUser.toString() << std::endl;

	testUser.setLastName("Last");
	std::cout << "3: " << testUser.toString() << std::endl;

}

void testDate(){
	Date testDate = Date();
	std::cout << "=====Test Date=====\n1: " << testDate.toString() << std::endl;
	
	testDate.setDay(2);
	std::cout << "2: " << testDate.toString() << std::endl;
	
	testDate.setMonth(12);
	std::cout << "3: " << testDate.toString() << std::endl;

	testDate.setYear(1234);
	std::cout << "4: " << testDate.toString() << std::endl;	
	
}

void testAddress(){
	Address testAddress = Address();
	std::cout << "=====Test Address=====\n1:" << testAddress.toString() << std::endl;
	
	testAddress.setLineOne("123 Fake Lane");
	std::cout << "2:" << testAddress.toString() << std::endl;
	
	testAddress.setLineTwo("Suite 130");
	std::cout << "3:" << testAddress.toString() << std::endl;

	testAddress.setCity("Indianapolis");
	std::cout << "4:" << testAddress.toString() << std::endl;

	testAddress.setState("Indiana");
	std::cout << "5:" << testAddress.toString() << std::endl;

	testAddress.setZipCode("12350");
	std::cout << "6:" << testAddress.toString() << std::endl;
	
}


