#include <iostream>
#include "mixed.h"

using namespace std;

Mixed::Mixed(int x)						//Default constructor
{								//  also acts as conversion
  Integer = 0;
  Numerator = x;
  Denominator = 1;

  Simplify();
}

Mixed::Mixed(int x, int n, int d)
{
  if(x < 0 && n < 0 || d < 0)					//Boundary checking for parameters
  {
    Integer = 0;
    Numerator = 0;
    Denominator = 0;
  }
  else
  {
    Integer = x;
    Numerator = n;
    Denominator = d;
  }
}

double Mixed::Evaluate()
{
  double temp, temp2, result;

  if(Integer < 0)						//returns decimal value but checks for
  {								//  negative integer math
    Integer = Integer * -1.0;
    temp = Integer * Denominator;
    temp2 = temp + Numerator;
    result = (temp2 / Denominator) * -1.0;
    Integer = Integer * -1.0;
  }  
  else
  {
    temp = Integer * Denominator;
    temp2 = temp + Numerator;
    result = temp2 / Denominator;
  }
  
  return result;
}

void Mixed::Simplify()
{
  Integer = Integer + (Numerator / Denominator);		//Simplifies 1 21/10 to 2 1/10
  Numerator = Numerator % Denominator;  

  if(Numerator % 2 == 0 && Denominator % 2 == 0)		//Checks GCM for num and denom
  {								//  turns 10/15 into 2/3
    Numerator = Numerator / 2;
    Denominator = Denominator /2;
  }
  else if(Numerator % 3 == 0 && Denominator % 3 == 0)
  {
    Numerator = Numerator / 3;
    Denominator = Denominator / 3;
  }
  else if(Numerator % 5 == 0 && Denominator % 5 == 0)
  {
    Numerator = Numerator / 5;
    Denominator = Denominator / 5;
  }
  else if(Numerator % 7 == 0 && Denominator % 7 == 0)
  {
    Numerator = Numerator / 7;
    Denominator = Denominator / 7;
  }
  else if(Numerator % 11 == 0 && Denominator % 11 == 0)
  {
    Numerator = Numerator / 11;
    Denominator = Denominator / 11;
  }
  else if(Numerator % 13 == 0 && Denominator % 13 == 0)
  {
    Numerator = Numerator / 13;
    Denominator = Denominator / 13;
  }
  else if(Numerator % 17 == 0 && Denominator % 17 == 0)
  {
    Numerator = Numerator / 17;
    Denominator = Denominator / 17;
  }
  else if(Numerator % 19 == 0 && Denominator % 19 == 0)
  {
    Numerator = Numerator / 19;
    Denominator = Denominator / 19;
  }
}

void Mixed::ToFraction()
{ 
  if(Integer > 0)
  {
    Numerator = (Integer * Denominator) + Numerator;
    Integer = 0;   
  }    
  else if(Integer < 0)						//converts to improper fraction
  {								//  checks for negative math
    Integer = Integer * -1;
    Numerator = (Integer * Denominator) + Numerator;
    Integer = 0;
    Numerator = Numerator * -1;
  }
}

Mixed Mixed::operator++()					//returns new value (pre)
{
  Integer += 1;  
  return *this;
}

Mixed Mixed::operator++(int)					//returns old value (post)
{
  Mixed copy(Integer, Numerator, Denominator);
  Integer += 1;
  return copy;
}

Mixed Mixed::operator--()					//returns new value (pre)
{
  Integer -= 1;  
  return *this;
}

Mixed Mixed::operator--(int)					//returns old value (post)
{
  Mixed copy(Integer, Numerator, Denominator);
  Integer -= 1;
  return copy;
}

ostream& operator<< (ostream& s, const Mixed& m)
{
  int tempint;

//FORMATTING COUT <<

  if(m.Integer == 0 && m.Numerator == 0 && m.Denominator == 0)	
    s << "0 ";
  else if(m.Integer == 0 && m.Numerator == 0 && m.Denominator != 0)
    s << "0 ";
  else if(m.Integer == 0 && m.Numerator != 0 && m.Denominator != 0)
    s << m.Numerator << "/"  << m.Denominator << " ";
  else if(m.Integer != 0 && m.Numerator == 0 && m.Denominator == 0)
    s << m.Integer << " ";
  else if(m.Integer != 0 && m.Numerator == 0 && m.Denominator != 0)
    s << m.Integer << " ";
  else if(m.Integer < 0 && m.Numerator < 0)
  {
    tempint = m.Numerator * -1;
    s << m.Integer << " " << tempint << "/" << m.Denominator << " ";
  }
  else
    s << m.Integer << " " << m.Numerator << "/" << m.Denominator << " ";
 
  return s;
}

istream& operator>> (istream& s, Mixed& m)
{
  char divsign;
  
  s >> m.Integer >> m.Numerator >> divsign >> m.Denominator;

//BOUNDARY CHECKING

  if(m.Integer < 0 && m.Numerator < 0 || m.Denominator < 0)
  {
    m.Integer = 0;
    m.Numerator = 0;
    m.Denominator = 0;
  }
  else if(m.Integer != 0 && m.Numerator < 0)
  {
    m.Integer = 0;
    m.Numerator = 0;
    m.Denominator = 0;
  }
  else if(m.Denominator == 0 || m.Denominator < 0)
  {
    m.Integer = 0;
    m.Numerator = 0;
    m.Denominator = 0;
  }
}

bool operator<(Mixed m1, Mixed m2)
{
  int tempnum1, tempnum2;
  m1.ToFraction();
  tempnum1 = m1.Numerator * m2.Denominator;
  m2.ToFraction();
  tempnum2 = m2.Numerator * m1.Denominator;

  if(tempnum1 < tempnum2)
    return true;
  else
    return false;
}

bool operator>(Mixed m1, Mixed m2)
{
  int tempnum1, tempnum2;
  m1.ToFraction();
  tempnum1 = m1.Numerator * m2.Denominator;
  m2.ToFraction();
  tempnum2 = m2.Numerator * m1.Denominator;

  if(tempnum1 > tempnum2)
    return true;
  else
    return false;  
}

bool operator<=(Mixed m1, Mixed m2)
{
  int tempnum1, tempnum2;
  m1.ToFraction();
  tempnum1 = m1.Numerator * m2.Denominator;
  m2.ToFraction();
  tempnum2 = m2.Numerator * m1.Denominator;

  if(tempnum1 <= tempnum2)
    return true;
  else
    return false;
}

bool operator>=(Mixed m1, Mixed m2)
{
  int tempnum1, tempnum2;
  m1.ToFraction();
  tempnum1 = m1.Numerator * m2.Denominator;
  m2.ToFraction();
  tempnum2 = m2.Numerator * m1.Denominator;

  if(tempnum1 >= tempnum2)
    return true;
  else
    return false;
}

bool operator==(Mixed m1, Mixed m2)
{
  int tempnum1, tempnum2;
  m1.ToFraction();
  tempnum1 = m1.Numerator * m2.Denominator;
  m2.ToFraction();
  tempnum2 = m2.Numerator * m1.Denominator;

  if(tempnum1 == tempnum2)
    return true;
  else
    return false;
}

bool operator!=(Mixed m1, Mixed m2)
{
  int tempnum1, tempnum2;
  m1.ToFraction();
  tempnum1 = m1.Numerator * m2.Denominator;
  m2.ToFraction();
  tempnum2 = m2.Numerator * m1.Denominator;

  if(tempnum1 != tempnum2)
    return true;
  else
    return false;
}

Mixed operator+(Mixed m1, Mixed m2)
{
  Mixed m;

  m1.ToFraction();
  m2.ToFraction();
 
  m.Numerator = (m1.Numerator * m2.Denominator)
		 + (m2.Numerator * m1.Denominator);
  
  m.Denominator = m1.Denominator * m2.Denominator;
  m.Simplify();

  return m;
}

Mixed operator-(Mixed m1, Mixed m2)
{
  Mixed m;

  m1.ToFraction();
  m2.ToFraction();
 
  m.Numerator = (m1.Numerator * m2.Denominator)
		 - (m2.Numerator * m1.Denominator);
  
  m.Denominator = m1.Denominator * m2.Denominator;
  m.Simplify();
 
  return m;
}

Mixed operator*(Mixed m1, Mixed m2)
{
  Mixed m;

  m1.ToFraction();
  m2.ToFraction();

  m.Numerator = m1.Numerator * m2.Numerator;
  m.Denominator = m1.Denominator * m2.Denominator;

  m.Simplify();

  return m;
}

Mixed operator/(Mixed m1, Mixed m2)
{
  Mixed m;

  if(m2.Integer == 0 && m2.Numerator == 0 && m2.Denominator == 0)
    return 0;

  m1.ToFraction();
  m2.ToFraction();

  m.Numerator = m1.Numerator * m2.Denominator;
  m.Denominator = m1.Denominator * m2.Numerator;

  m.Simplify();

  if(m.Denominator < 0)
    m.Denominator = m.Denominator * -1;

  return m;
}
