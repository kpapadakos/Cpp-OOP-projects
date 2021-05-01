#include <iostream>
#include <cstdlib>
#include "grid.h"

using namespace std; 

Grid::Grid()							//Default Constructor
{
  grid[1][1];
  grid[0][0] = '>';
  Direction = Grid::EAST;
  Rows = 1;
  Columns = 1; 
  Mover = '>';
}

Grid::Grid(int r, int c)					//two param for trapped.cpp
{
  if(r < 3 || c < 3)
  {
    Rows = 3;
    Columns = 3;
  }
  else if(r > 40 || c > 40)
  {
    Rows = 40;
    Columns = 40;
  }
  else
  {
    Rows = r;
    Columns = c;
  }

  for(int i = 0; i < Rows; i++)					//Inits array to all "."
    for(int j = 0; j < Columns; j++)	
      grid[i][j] = '.';

  for(int i = 0; i < Columns; i++)				//Implements a block (#) border
    grid[0][i] = '#';
  for(int i = 0; i < Rows; i++)
    grid[i][Columns - 1] = '#';
  for(int i = 0; i < Columns; i++)
    grid[Rows - 1][i] = '#';
  for(int i = 0; i < Rows; i++)
    grid[i][0] =  '#';

  srand( time(0) );						//Randomizes direction
  int d = rand() % 4;
  Direction = d;
  WhichMover();

  int a = rand() % (Rows - 2) + 1;				//Randomizes mover location
  int b = rand() % (Columns -2) + 1;
  grid[a][b] = Mover;

  MR = a;							//Stores mover location
  MC = b;

  int w = rand() % 4 + 1;					//Randomizes exit door location
  int exit;
  if(w == 1)							//Disallows cornors for being exits
  {
    exit = rand() % (Columns - 2) + 1;
    grid[0][exit] = ' ';
  }
  else if(w == 2)
  {
    exit = rand() % (Rows - 2) + 1;
    grid[exit][Columns - 1] = ' ';
  }
  else if(w == 3)
  {
    exit = rand() % (Columns - 2) + 1;
    grid[Rows - 1][exit] = ' ';
  }
  else if(w == 4)
  {
    exit = rand() % (Rows - 2) + 1;
    grid[exit][0] = ' ';
  }
}

Grid::Grid(int r, int c, int mr, int mc, int d)			//Full param constructor
{
  if(r < 1)
    Rows = 1;
  else if(r > 40)
    Rows = 40;
  else
    Rows = r;
  
  if(c < 1)
    Columns = 1;
  else if(c > 40)
    Columns = 40;
  else
    Columns = c;

  for(int i = 0; i < Rows; i++)
    for(int j = 0; j < Columns; j++)
      grid[i][j] = '.';

  if(mr > Rows)
    mr = Rows;
  else if(mr < 1)
    mr = 0;

  if(mc > Columns)
    mc = Columns;
  else if(mc < 1)
    mc = 0;

  Direction = d;
  WhichMover();

  MR = mr;
  MC = mc;
}

void Grid::WhichMover()						//Selects mover based on direction
{
  if(Direction == 0)
    Mover = '^';
  else if(Direction == 1)
    Mover = '<';
  else if(Direction == 2)
    Mover = 'v';
  else if(Direction == 3)
    Mover = '>';
}

bool Grid::Move(int s)
{
  for(int i = 0; i < s; i++)					//Iterates for s moves
  {
    FrontIsClear();
    if(Direction == 0 && FrontIsClear() == true)
    {
      if(grid[MR][MC] == '0')
      {
        grid[MR][MC] = '@';					//Checks for item
        MR = MR-1;
        grid[MR+1][MC] = '0';
      }
      else
      {
        grid[MR][MC] = 't';					// 't' for travelled (helps with output)
        MR = MR-1;
      }       
    }
    else if(Direction == 1 && FrontIsClear() == true)
    {
      if(grid[MR][MC] == '0')
      {
        grid[MR][MC] = '@';
        MC = MC-1;
        grid[MR][MC+1] = '0';
      }
      else
      {
        grid[MR][MC] = 't';
        MC = MC-1;
      }
    }
    else if(Direction == 2 && FrontIsClear() == true)
    {
      if(grid[MR][MC] == '0')
      {
        grid[MR][MC] = '@';
        MR = MR+1;
        grid[MR-1][MC] = '0';
      }
      else
      {
        grid[MR][MC] = 't';
        MR = MR+1;
      }
    }
    else if(Direction == 3 && FrontIsClear() == true)
    {
      if(grid[MR][MC] == '0')
      {
        grid[MR][MC] = '@';
        MC = MC+1;
        grid[MR][MC-1] = '0';
      }
      else
      {
        grid[MR][MC] = 't';
        MC = MC+1;
      }
    }
  }
}

void Grid::TogglePath()						//Odd = ToggleOff ; Even = ToggleOn
{
  TP++;  
}

void Grid::TurnLeft()						//Updates direction
{
  if(Direction == 0)
    Direction = 1;
  else if(Direction == 1)
    Direction = 2;
  else if(Direction == 2)
    Direction = 3;
  else if(Direction == 3)
    Direction = 0;

  WhichMover();  
}

void Grid::PutDown()
{
  PutDown(MR, MC);
}

bool Grid::PutDown(int r, int c)
{
  if(r < Rows && c < Columns && grid[r][c] != '#')		
  {
    grid[r][c] = '0';
      return true;
  }
  else 
    return false;
}

bool Grid::PickUp()
{
  if(grid[MR][MC] = '@')
  {
    grid[MR][MC] = 't';						//Replaces '0' with 't'
    return true;
  }
  else
    return false;
}

bool Grid::PlaceBlock(int r, int c)
{
  if(r < Rows && c < Columns && grid[r][c] == '.')
  {
    grid[r][c] = '#';
    return true;
  }
  else
    return false;
}

void Grid::Grow(int gr, int gc)
{
  int NewRows;
  int NewColumns;

  if(Rows + gr > 40)
    NewRows = 40;
  else
    NewRows = Rows + gr;

  if(Columns + gc > 40)
    NewColumns = 40;
  else
    NewColumns = Columns + gc;

  for(int j  = 0; j < NewColumns; j++)					//Adds to bottom addition
    for(int i = Rows; i < NewRows; i++)
      grid[i][j] = '.';

  for(int j = 0; j < NewRows; j++)					//Adds to side addition
    for(int i = Columns; i < NewColumns; i++)
      grid[j][i] = '.';

  Rows = NewRows;
  Columns = NewColumns;
}

void Grid::Display() const
{
  cout << "The Grid: " << endl;

  if(TP % 2 != 0)							//TOGGLE OFF
    for(int i = 0; i < Rows; i++)
    {
      for(int j = 0; j < Columns; j++)
      {
        if(i == MR && j == MC && grid[i][j] == '0')
          cout << "@ ";
        else if(i == MR && j == MC && grid[i][j] != '@')
          cout << Mover << " ";
        else if(grid[i][j] == 't')					//Replaces 't' with '.'
          cout << ". ";
        else 
          cout << grid[i][j] << " \n"[j == Columns];
      }
      cout << endl;
    }
  else if(TP % 2 == 0)							//TOGGLE ON
    for(int i = 0; i < Rows; i++)
    {
      for(int j = 0; j < Columns; j++)
      {
        if(i == MR && j == MC && grid[i][j] == '0')
          cout << "@ ";
        else if(i == MR && j == MC && grid[i][j] != '@')
          cout << Mover << " ";
        else if(grid[i][j] == 't')					//Replaces 't' with ' '
          cout << "  ";
        else 
          cout << grid[i][j] << " \n"[j == Columns];
      }
      cout << endl;
    }
}

bool Grid::FrontIsClear() const
{
  if(Direction == 0)
  {
    if(grid[MR-1][MC] == '#')
      return false;
    else 
      return true;
  }
  else if(Direction == 1)
  {
    if(grid[MR][MC-1] == '#')
      return false;
    else 
      return true;
  }
  else if(Direction == 2)
  {
    if(grid[MR+1][MC] == '#')
      return false;
    else 
      return true;
  }
  else if(Direction == 3)
  {
    if(grid[MR][MC+1] == '#')
      return false;
    else 
      return true;
  }
}

bool Grid::RightIsClear() const	
{
  if(Direction == 0)
  {
    if(grid[MR][MC+1] == '#')
      return false;
    else
      return true;
  }
  else if(Direction == 1)
  {
    if(grid[MR-1][MC] == '#')
      return false;
    else
      return true;
  }
  else if(Direction == 2)
  {
    if(grid[MR][MC-1] == '#')
      return false;
    else
      return true;
  }
  else if(Direction == 3)
  {
    if(grid[MR+1][MC] == '#')
      return false;
    else
      return true;
  } 
}

int Grid::GetRow() const
{
  return MR;
}

int Grid::GetCol() const
{
  return MC;
}

int Grid::GetNumRows() const
{
  return Rows;
}

int Grid::GetNumCols() const	
{
  return Columns;
}
