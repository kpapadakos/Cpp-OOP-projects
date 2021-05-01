//*************************************************************************
//*	Name:		Kyriakos Papadakos				 **
//*	Class: 		COP3330						 **
//*	Section:	4						 **
//*	Project:	Date Class (HW2)				 **
//*	Description:	This class works with dates.  It allows the user **
//*				to set, input, compare, increment, show, **
//*				and get the month day and year of dates. **
//*									 **
//*************************************************************************

#include <iostream>
#include <iomanip>
#include "date.h"

using namespace std;

Date::Date()							//intializes to 1/1/2000
{
 Month = 1;
 Day = 1;
 Year = 2000;
 Format = 'D';
}

Date::Date(int m, int d, int y)					//Checks boundaries and discards
{								//  out of boundary entries
 if((m < 1) || (m > 12))
 {
   Month = 1;
   Day = 1;
   Year = 2000;
 }
 else if((d < 1) || (d > 31))
 {  
   Month = 1;
   Day = 1;
   Year = 200;
 }
 else if(y < 0)
 {  
   Month = 1;
   Day = 1;
   Year  = 2000;
 }
 else								//Allows user initializing 
 {
   Month = m;
   Day = d;
   Year = y;
 }

 Format = 'D';							//Default format
}

void Date::Show() const
{
 switch(Format)
 {
   case 'D' :							//M/D/YYYY
     cout << Month << "/" << Day << "/" << Year << endl;	
     break;
   case 'T' :							//MM/DD/YY
     cout << setw(2) << setfill('0') << Month << "/" << setw(2) << setfill('0') << Day << "/" << setw(2) << setfill('0') << Year%100 << endl;
     break;
   case 'L' :							//Month D, YYYY
     numMonth();
     cout << Day << ", " << Year << endl;
     break;
 }
}

void Date::Input()
{
 char divsign;
  								//allows  M/D/YYYY input
 do
 {
   cout << "Enter in a date (Month/Day/Year) - " ;
   cin >> Month >> divsign >> Day >> divsign >> Year;
   CheckValidity();						//Checks Validity
     if(CheckValidity() == 0)
       cout << "Invalid date... Please try again. " << endl;
 }while(CheckValidity() == 0);
}

bool Date::Set(int m, int d, int y)				//Checks M/D/YYYY boundaries
{
 if((m > 12) || (m < 1) || (d < 1) || (d > 31) || (y < 0))
   return false;
 else if((m == 4) && (d > 30))
   return false;
 else if((m == 6) && (d > 30))
   return false;
 else if((m == 9) && (d > 30))
   return false;
 else if((m == 11) && (d > 30))
   return false;
 else if((m == 2) && (d > 29))
   return false;
 else
 {
   Month = m;
   Day = d;
   Year = y;
   return true; 
 }
}

int Date::GetMonth() const
{
 cout << Month;
 return Month;
}

int Date::GetDay() const
{
 cout << Day;
 return Day;
}

int Date::GetYear() const
{
 cout << Year;
 return Year;
}

bool Date::SetFormat(char f)
{
 if(f == 'D')							//Allows only D,T,L for format
 {
   Format = f;
   return true;
 }
 else if(f == 'T')
 {
   Format = f;
   return true;
 }
 else if(f == 'L')
 {
   Format = f;
   return true;
 }
 else
   return false;
}

void Date::Increment(int numDays)
{
 Day = Day + numDays;
 if(Month == 1 && Day > 31)					//Bleeds into next month
 {
   Month = 2;
   Day = Day - 31;
 }
 else if(Month == 2 && Day > 29)
 {
   Month = 3;
   Day = Day - 29; 
 }
 else if(Month == 3 && Day > 31)
 {
   Month = 4;
   Day = Day - 31;
 }
 else if(Month == 4 && Day > 30)
 {
   Month = 5;
   Day = Day - 30;
 }
 else if(Month == 5 && Day > 31)
 {
   Month = 6;
   Day = Day - 31;
 }
 else if(Month == 6 && Day > 30)
 {
   Month = 7;
   Day = Day - 30;
 }
 else if(Month == 7 && Day > 31)
 {
   Month = 8;
   Day = Day - 31;
 }
 else if(Month == 8 && Day > 31)
 {
   Month = 9;
   Day = Day - 31;
 }
 else if(Month == 9 && Day > 30)
 {
   Month = 10;
   Day = Day - 30;
 }
 else if(Month == 10 && Day > 31)
 {
   Month = 11;
   Day = Day - 31;
 }
 else if(Month == 11 && Day > 30)
 {
   Month = 12;
   Day = Day - 30;
 }
 else if(Month == 12 && Day > 31)					//Bleeds into next year
 {
   Month = 1;
   Day = Day - 31;
   Year = Year + 1;
 }
}

int Date::Compare(const Date &d) const
{
 if(d.Day == Day && d.Month == Month && d.Year == Year)			//Calling obj and paramter
   return 0;								//  are equal (returns 0)
 else if(d.Year < Year)							//Paramter comes first (1)
   return 1;
 else if(d.Year == Year && d.Month < Month)				//Parameter comes first (1)
   return 1;
 else if(d.Year == Year && d.Month == Month && d.Day < Day)		//Parameter comes first (1)
   return 1;
 else									//Calling obj comes first (-1)
   return -1;
}

void Date::numMonth() const
{
 switch(Month)								//Finds long version of Month
 {
   case 1:
     cout << "Jan ";
     break;
   case 2:
     cout << "Feb ";
     break;
   case 3:
     cout << "Mar ";
     break;
   case 4:
     cout << "Apr ";
     break;
   case 5:
     cout << "May ";
     break;
   case 6:
     cout << "June ";
     break;
   case 7:
     cout << "July ";
     break;
   case 8:
     cout << "Aug ";
     break;
   case 9:
     cout << "Sep ";
     break;
   case 10:
     cout << "Oct ";
     break;
   case 11:
     cout << "Nov ";
     break;
   case 12:
     cout << "Dec ";
     break;
 }
}

bool Date::CheckValidity() const					//Checks validity for days in Month
{
 if((Month < 1) || (Month > 12))
 {
   return false;
 }
 else if((Day < 1) || (Day > 31))
 {  
   return false;
 }
 else if(Year < 0)
 {  
   return false;
 }
 else
 {
   return true;
 }

 if((Month == 4) || (Month == 6) || (Month == 9) || (Month == 11) && (Day > 30))
   return false;
 else if ((Month == 2) && (Day > 29))
   return false;
 else
   return true;
}
