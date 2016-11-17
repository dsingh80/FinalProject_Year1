#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

#include <string>

class Date{
	public:
		Date();
		Date(std::string); //pass in full Date 00/00/0000
		Date(const Date&);
		~Date(); //empty destructor
		
		std::string toString(); //return formatted date

		//ACCESSOR METHODS
		int getDay();
		int getMonth();
		int getYear();

		//MODIFIER METHODS
		void setDay(int);
		void setMonth(int);
		void setYear(int);
	private:
		int day;
		int month;
		int year;

};

#endif
