/*
*	Name:		Kyriakos Papadakos
*	Course:		COP3330
*	Section:	4
*	Project:	House Class (HW1)
*	Summary:	This .cpp file contains the definitons
*			to complete the header file for creating
*			a house class.  This class allows the
*			user to create a house with a border and
*			a fill, finds the area and perimeter,
*			grows, shrinks, and draws the house.
*/

#include <iostream>
#include "house.h"

using namespace std;

House::House(int s)				//one parameter is MANDATORY
{
 if(s < 3)					//checks range (3-37)
   Size = 3;
 else if(s > 37)
   Size = 37;
 else
   Size = s;

 Border = 'X';					//sets border to default 
 Fill = '*';					//sets fill to default
}

House::House(int s, char b)			//constructor for two parameters
{
 if(s < 3)					//checks range (3-37)
   Size = 3;
 else if(s > 37)
   Size = 37;
 else
   Size = s;

 SetBorder(b);					//calls SetBorder to check validity

 Fill = '*';					//sets fill to default
}

House::House(int s, char b, char f)		//constructor for three parameters
{
 if(s < 3)					//checks range (3-37)
   Size = 3;
 else if(s > 37)
   Size = 37;
 else
   Size = s;

 SetBorder(b);					//checks border
 SetFill(f);					//checks fill
}

int House::GetSize() const			
{	
 return Size;					//returns int s or the Size
}

int House::Perimeter() const			//Finds Perimeter 
{
 int baseperimeter = Size * 3;
 int topperimeter = (Size + 2) * 2;

 return baseperimeter + topperimeter + 2;
}

double House::Area() const			//finds the area by calculating 
{						//  the area of the square and
 double size  = Size * 1.0;			//  the area of the triangle
 double basearea;				//  then adds the two
 double toparea;
 double sqrthree = 1.732050807568877;
 basearea = size * size;
 toparea = (sqrthree/4.0) * ( (Size + 2) * (Size + 2) );

 return basearea + toparea;
}

void House::Grow()				//increment size by 1
{
 if(Size < 37)
   Size = Size + 1;
 else
   Size = Size;
}

void House::Shrink()				//decrrement size by 1
{
 if(Size > 3)
   Size = Size - 1;
 else
   Size = Size;
}

void House::SetBorder(char b)
{
 if(b < char(33) || b > char(126))		//checks ascii range for valid border char
   Border = char(88);
 else
   Border = b;
}

void House::SetFill(char f)			//checks ascii range for valid fill char
{
 if(f < char(33) || f > char(126))
   Fill = char(42);
 else
   Fill = f;
}

void House::Draw() const
{
 for(int i = 0; i < Size + 1; i++)
 {
   cout << " ";					//creates border for triangle (first border char)
 }
 cout << Border;
 cout << '\n';
 for(int i = Size; i > 0; i--)
 {
   for(int j = 0; j < i; j++)
   {
     cout << " ";				//creates the remaining border
   }
   cout << Border << " ";
     for(int k = Size; k > i; k--)
     {
       cout << Fill << " ";      		//fills the triangle
     }
   cout << Border;
   cout << endl;
 }

 for(int i = 0; i < 2;  i++)			//creates border for base
 {
   cout << Border << " ";
 }
 for(int i = 0; i < Size - 2; i++)
 {  
   cout << Fill << " ";				//fills base
 }
 for(int i = 0; i < 2; i++)
 {
   cout << Border << " ";
 }
 cout << endl;					//finishes border

 for (int i = 0; i < Size - 2; i++)
 {
   cout << "  " << Border << " ";
     for (int j = 0; j < Size - 2; j++)
     {
       cout << Fill << " ";			//Base
     }
   cout << Border << '\n';
 }
 cout << " ";
  
 for(int i = 0; i < Size; i++)
 {
   cout << " " << Border;
 }

 cout << endl;

}

void House::Summary() const
{
 cout << "House width and height base to roof = " << GetSize() << " units." << '\n';
 cout << "Perimeter of house = " << Perimeter() << " units." << '\n';
 cout << "Area of house = " << Area() << " units." << '\n';
 cout << "House looks like: " << endl;
 Draw();
}
