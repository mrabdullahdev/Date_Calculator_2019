// Calender2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include"Date2019.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()		
{
	ifstream infile;		// variable for getting input from file
	int days,dd,mm;		// variables to store integers
	// Objects of class Date2019 with different constructors to call
	Date2019 date(-270, 10), date1,date2(34),date4,date6;

	// Implementation of object with double parameter constructor 
	cout << "\nDate for double parameter constructor.\n";

	cout << "Enter days to add: ";
	cin >> days;	// getting days to add
	date1 = date + days;		//adding days in date
	// printing date
	cout << days << " days after ";
	date.printdate();		// calling function to print date
	cout << " is ";
	date1.printdate();		// calling function to print date

	// Implementation of object with single parameter constructor 
	cout << "\nDate for single parameter constructor.\n";
	cout << "Enter days to add: ";
	cin >> days;	// getting days to add
	date1 = date2 + days;		//adding days in date
	cout << days << " days after ";
	date2.printdate();		// calling function to print date
	cout << " is ";
	date1.printdate();		// calling function to print date

	// Implementation of object without parameter constructor 
	cout << "\nDate for non parameter constructor.\n";

	cout << "Enter days to add: ";
	cin >> days;	// getting days to add
	date1 = date4 + days;		//adding days in date
	cout << days << " days after ";
	date4.printdate();		// calling function to print date
	cout << " is ";
	date1.printdate();		// calling function to print date

	// Implementation of object without constructor for getting input fron user
	infile.open("input.txt");		// opening file for getting input
	cout << "\nGetting input from file.\n";
	while(!infile.eof())	// condition for checking end of file
	{
		infile >> mm >> dd >> days;	// getting input from file
		date6.setdate(dd, mm);
		date1 = date6 + days;		//adding days in date
		// if/else statement to check the accuracy of date
		if (mm > 12 || mm <= 0)
		{
			cout << "The date you entered is incorrect.\n";
		}
		else
		{
			cout << days << " days after ";
			date6.printdate();		// calling function to print date
			cout << " is ";
			date1.printdate();		// calling function to print date
		}
	}
	
	infile.close();		// closing file

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
