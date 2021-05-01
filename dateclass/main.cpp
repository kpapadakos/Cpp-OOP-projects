/////////////////////////////////////////////////////////
// Bob Myers
//
// sample.cpp -- sample test program starter for Date class
/////////////////////////////////////////////////////////

#include <iostream>
#include "date.h"

using namespace std;

int main()
{
   Date d1(4,9,1992);		// should default to 1/1/2000
   Date d2(4,10,1992);  // should init to 4/10/1992

   // display dates to the screen
   cout << "\nDate d1 is: ";
   d1.Show();			
   cout << "\nDate d2 is: ";
   d2.Show();

//   d1.Input();			// Allow user to enter a date for d1
//   cout << "\nDate d1 is: ";
//   d1.Show();			

   d2.Set(2,13,-5);
   d2.Show();

//   d1.GetMonth();
   
   d2.SetFormat('T');		// change format of d1 to "Long" format
   cout << "\nDate d2 is: ";
   d2.Show();			// print d1 -- should show now in long format

//   d1.Increment();
//   d1.Show();

   int obj = d1.Compare(d2);
   cout << obj;
   // and so on.  Add your own tests to fully test the class' 
   //   functionality.
}
