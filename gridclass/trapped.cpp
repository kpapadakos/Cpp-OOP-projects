//trapped.cpp

#include<iostream>
#include "grid.h"

using namespace std;

int main()
{
  int r;
  int c;
  cout << "\n***WARNING*** ***WARNING*** ***WARNING*** ***WARNING*** ***WARNING***\n**" << endl;
  cout << "** Giant Mole People have risen from their underground lairs and \n** are taking over the world. You have been taken prisoner and\n** placed in an underground jail cell..." << endl;
  cout << "**\n***WARNING*** ***WARNING*** ***WARNING*** ***WARNING*** ***WARNING***\n" << endl;

  cout << "How many rows would you like your cell?" << endl;  
  cin >> r;
  cout << "How many columns would you like your cell?" << endl;
  cin >> c;
  
  Grid g(r,c);

  g.Display(); 

  g.Move(40);
  g.TurnLeft();

  while(g.RightIsClear() == false)
  {
    if(g.RightIsClear() == false && g.FrontIsClear() == true)
      g.Move(1);
    else if(g.RightIsClear() == false && g.FrontIsClear() == false)
      g.TurnLeft();
  }

  for(int i = 0; i < 3; i++)
    g.TurnLeft();

  g.Move(1);
  g.Display();

  cout << "We escaped!!!" << endl;
  cout << "The door is located at Row: " << g.GetRow() << " and Col: " << g.GetCol() << endl;
}
