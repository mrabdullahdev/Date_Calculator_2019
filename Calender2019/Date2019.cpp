#include "pch.h"
#include "Date2019.h"
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

// non perametric constructor
Date2019::Date2019()
{
	d = 1;
	m = 1;
}
// single parametric constructor
Date2019::Date2019(int dd)
{
	// condition for checking the accuracy of days
	if (dd > 0 && dd <= 365)
	{
		d = dd;
		m = 1;
		standarddate();		// calling function to convert date into  standard form
	}
	else
		cout << "Date is not from 2019.\n";
}
// double parametric constructor
Date2019::Date2019(int dd, int mm)
{
	d = dd;
	m = mm;
	standarddate();		// calling function to convert date into  standard form
}

// function for reversing the string
string reverse_str(string str)
{
	string rev = "";
	int str_size;
	// loop for finding the size of string
	for (str_size = 0; str[str_size] != '\0'; str_size++)
	{

	}
	// loop for reversing the string
	for (str_size; str_size >= 0; str_size--)
	{
		rev += str[str_size];
	}

	return rev;
}

// function for the conversion of an integer into a string
string num_to_str(int num)
{
	string str="";
	for (num; num > 0; num = (num - (num % 10)) / 10)
	{
		str += (48 + (num % 10));	// forced conversion of integer to string
	}
	string rev_str= reverse_str(str);
	return rev_str;
}

// function for setting the date
void Date2019::setdate(int dd, int mm)
{
	d = dd;
	m = mm;
	standarddate();
}

// function for printing the date on the screen
void Date2019::printdate()
{
	// declearing a variable of string
	string full_date = "";
	// declearing an array of integers to set the days of each month
	int day[12] = { d + 1,d + 4,d + 4,d,d + 2,d + 5,d,d + 3,d + 6,d + 1,d + 4,d + 6 };
	// array of strings for storing days of week
	string week_days[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	// array of strings for storing months of year
	string months[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	full_date = week_days[day[m - 1] % 7] + ", ";	// adding day to the string
	full_date += months[m - 1];		// adding month to the string
	full_date += " ";
	// calling function to convert number to string and adding to the string
	full_date += num_to_str(d);
	full_date += ", 2019";

	// conditon to print the date
	if (m < 13 && m>0)	
	{
		cout << full_date;
	}
}

// friend function to add days into date
Date2019 operator+(Date2019 date, int days)
{
	Date2019 date1;
	date1.setdate(date.d + days, date.m);	// adding days to previous date and settingb values
	date1.standarddate();		// calling standarddate function
	return date1;
}

// private member function to convert the date into standard form
void Date2019::standarddate()
{
	// array of integers to convert days months to days
	int months_to_days[12] = { d,31 + d,59 + d,90 + d,120 + d,151 + d,181 + d,212 + d,243 + d,273 + d,304 + d,334 + d };
	// setting days 
	d = months_to_days[m - 1];
	// if/else statement to convert days to standard days and month
	if (d <= 31 && d > 0)		// condition for month 1
	{
		m = 1;
	}
	else if (d > 31 && d <= 59)		// condition for month 2
	{
		d -= 31;
		m = 2;
	}
	else if (d > 59 && d <= 90)		// condition for month 3
	{
		d -= 59;
		m = 3;
	}
	else if (d > 90 && d <= 120)	// condition for month 4
	{
		d -= 90;
		m = 4;
	}
	else if (d > 120 && d <= 151)	// condition for month 5
	{
		d -= 120;
		m = 5;
	}
	else if (d > 151 && d <= 181)	// condition for month 6
	{
		d -= 151;
		m = 6;
	}
	else if (d > 181 && d <= 212)	// condition for month 7
	{
		d -= 181;
		m = 7;
	}
	else if (d > 212 && d <= 243)	// condition for month 8
	{
		d -= 212;
		m = 8;
	}
	else if (d > 243 && d <= 273)	// condition for month 9
	{
		d -= 243;
		m = 9;
	}
	else if (d > 273 && m == 304)	// condition for month 10
	{
		d -= 273;
		m = 10;
	}
	else if (d > 304 && d <= 334)	// condition for month 11
	{
		d -= 304;
		m = 11;
	}
	else if (d > 334 && d <= 365)	// condition for month 12
	{
		d -= 334;
		m = 12;
	}
	// if date is not from 2019
	else
	{
		cout << "Date is not from 2019.\n";
	}	
}
