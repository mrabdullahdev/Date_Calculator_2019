#pragma once
#include <string.h>

// Declearing class of Date2019
class Date2019
{
private:	// private members of class
	int d, m;		// integers
	void standarddate();	// function to convert date into standard form

public:		// public member funtions of class
	Date2019();		// non perametric constructor
	Date2019(int dd);		// single parameter constructor
	Date2019(int dd, int mm);		// double parameter constructor
	void setdate(int dd, int mm);		// function for setting date
	void printdate();		// function for printing date
	// operator overload friend function to add days into date
	Date2019 friend operator+(Date2019 date, int days);	

};

