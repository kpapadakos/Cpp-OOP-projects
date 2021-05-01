/*********************************************************************************
**	Name:		Kyriakos Papadakos					**
**	Class:		COP3330							**
**	Section:	4							**
**	Description:	This class manipulates mixed numbers while showcasing 	**
**			  operator overloading					**
**********************************************************************************/

#include <iostream>

using namespace std;

class Mixed
{
  friend istream& operator >> (istream& s, Mixed& m);		//check
  friend ostream& operator << (ostream& s, const Mixed& m); 	//check
  friend bool operator < (Mixed m1, Mixed m2);			//check
  friend bool operator > (Mixed m1, Mixed m2);			//check
  friend bool operator <= (Mixed m1, Mixed m2);			//check
  friend bool operator >= (Mixed m1, Mixed m2);			//check
  friend bool operator == (Mixed m1, Mixed m2);			//check
  friend bool operator != (Mixed m1, Mixed m2);			//check
  friend Mixed operator + (Mixed m1, Mixed m2);			//check
  friend Mixed operator - (Mixed m1, Mixed m2);			//check
  friend Mixed operator * (Mixed m1, Mixed m2);
  friend Mixed operator / (Mixed m1, Mixed m2);
public:
  Mixed(int x = 0);
  Mixed(int x, int n, int d = 1);
  double Evaluate();
  void Simplify();
  void ToFraction();

  Mixed operator++();
  Mixed operator++(int);
  Mixed operator--();
  Mixed operator--(int);
private:
  int Integer;
  int Numerator;
  int Denominator;
};
