#include "Date.h"
#include <sstream>

Date::Date(){
	day = 1;
	month = 1;
	year = 2016;
}

Date::Date(std::string inputString){
	//FULL DATE PROVIDED mm/dd/yyyy
	//inputString = 00/00/0000

	//Converts string to int
	std::stringstream convertStream;
	
	//WRITE A FORMATTED INPUTSTRING TO CONVERTSTREAM
	//Extract month of (MM/DD/YYYY)
	convertStream << inputString.substr(0, inputString.find('/')) << " ";
	inputString = inputString.substr(inputString.find('/')+1); //We chop off the month aspect of  the input to make further extraction easier
	//Extract day of (DD/YYYY)
	convertStream << inputString.substr(0, inputString.find('/')) << " ";
	//Extract year of (DD/YYYY)
	convertStream << inputString.substr(inputString.find('/')+1);

	//Hold our extracted values
	int tempDay, tempMonth, tempYear;
	convertStream >> tempMonth >> tempDay >> tempYear; //extract variables and write to them
	
	//Set variables
	Date::setDay(tempDay);	
	Date::setMonth(tempMonth);	
	Date::setYear(tempYear);
	

}

Date::Date(const Date& newDate){
	day = newDate.day;
	month = newDate.month;
	year = newDate.year;

}

Date::~Date(){
	//EMPTY DESTRUCTOR
}

std::string Date::toString(){
	//RETURN FORMATTED DATE
	/*std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	*std::string monthName = months[Date::month]; //convert the int month to the real name of the month (1=January)
	
	*std::cout << "INSIDE DATE: " << month << "/" << day << "/" << year << "|"<< std::endl;
	*std::cout << "\t" << Date::month << " " << Date::day << ", " << Date::year << std::endl;
	*/

	//Final String to return
	std::string formattedString;
	//Stringstream to concatenate the date easily
	std::stringstream stringHolder;
	stringHolder << Date::month << "/" << Date::day << "/" << Date::year;
	
	formattedString = stringHolder.str(); //write to string

	return formattedString;
}

// ACCESSOR METHODS //
int Date::getDay(){
	return Date::day;
}

int Date::getMonth(){
	return Date::month;
}

int Date::getYear(){
	return Date::year;
}

// MODIFIER METHODS //
void Date::setDay(int tempDay){
	Date::day = tempDay;
}

void Date::setMonth(int tempMonth){
	Date::month = tempMonth;
}

void Date::setYear(int tempYear){
	Date::year = tempYear;
}
