#include <iostream>
#include "frac.h"

using namespace std;

/*
  int numerator;
  int denominator;
*/

Fraction::Fraction()
{
  numerator = 0;
  denominator = 1;

}

Fraction::Fraction(int n, int d)
{
  numerator = n;
  denominator = d;
}

void Fraction::SetValue(int n, int d)
{ 
  numerator = n;
  denominator = d;

}

void Fraction::Input()
{
  char divsign; 
  cin >> numerator >> divsign >> denominator;
}
  
void Fraction::Show() const
{
  cout << numerator << "/" << denominator;
}

int Fraction::GetNumerator() const
{
  return numerator;
}

int Fraction::GetDenominator() const
{
  retrun denominator;
}

double Fraction::Evaluate() const
{
  double n = numerator;
  double d = denominator;

  return n / d;
}
