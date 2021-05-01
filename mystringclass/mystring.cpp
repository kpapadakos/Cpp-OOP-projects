#include <iostream>
#include <cstring>
#include "mystring.h"

ostream& operator<< (ostream& os, const MyString& s)
{
  os << s.msp;
  return os;
}

istream& operator>> (istream& is, MyString& s)
{
  char ch;
  int i = 0;

//skips whitespace until a char is read

  is >> skipws >> ch;
  s.msp[i] = ch;
  i++;  

//white space becomes delimiter

  while(ch != ' ')
  {
    char temp = cin.peek();
    if(temp == ' ')
      is.putback(temp);
    if(s.currentsize == s.size)
      s.Grow();
    is.get(ch);
    s.msp[i] = ch;
    i++;
  }

  return is;
}

istream& getline (istream& is, MyString& s)
{
  char ch;
  int i = 0;

//new line is delimiter

  while(ch != '\n')
  {
    s.Grow();
    is.get(ch);
    s.msp[i] = ch;
    i++;
    s.currentsize = i;
  }

  return is;
}

istream& getline(istream& is, MyString& s, char delim)
{
  char ch, ch1;
  int i = 0;

  is.get(ch);
  s.msp[i] = ch;
  i++;

  while(ch != delim)
  {
    s.Grow();
    char temp = is.peek();

//grabs the delim and stores into garbage variable

    if(temp == delim)
    {
      is.get(ch1);
      break;
    }
    is.get(ch);
    s.msp[i] = ch;
    i++;
    s.currentsize = i;
  }
  s.msp[s.currentsize + 1] = '\0';

  return is;
}

MyString operator+ (const MyString& s1, const MyString& s2)
{
  MyString r;

  r.size = s1.size + s2.size;
  r.msp = new char[r.size + 1];

  for(int i = 0; i < s1.size; i++)
    r.msp[i] = s1.msp[i];
  for(int i = 0; i < s2.size; i++)
    r.msp[i + s1.size] = s2.msp[i];

  r.currentsize = strlen(r.msp);

  return r;
}

bool operator<(const MyString& s1, const MyString& s2)
{
  if(strcmp(s1.msp, s2.msp) < 0)
    return true;
  else if(strcmp(s1.msp, s2.msp) == 0 || strcmp(s1.msp, s2.msp) > 0)
    return false;
}

bool operator>(const MyString& s1, const MyString& s2)
{
  if(s1 < s2)
    return false;
  else
    return true;
}

bool operator<=(const MyString& s1, const MyString& s2)
{
  if(s1.msp == s2.msp || s1 < s2)
    return true;
  else
    return false;    
}

bool operator>=(const MyString& s1, const MyString& s2)
{
  if(s1.msp == s2.msp || s1 > s2)
    return true;
  else
    return false;  
}

bool operator==(const MyString& s1, const MyString& s2)
{
  if(strcmp(s1.msp, s2.msp) == 0)
    return true;
  else  
    return false;
}

bool operator!=(const MyString& s1, const MyString& s2)
{
  if(s1.msp == s2.msp)
    return false;
  else
    return true;
}

MyString::MyString()
{
  size = 0;
  msp = new char[size + 1];
  msp[0] = '\0';
}

MyString::MyString(const char* s)
{
  size = strlen(s);
  currentsize = strlen(s);
  msp = new char[size + 1];
  strcpy(msp, s);
}

MyString::MyString(int x)
{ 
  int c = x;
  int temp, temp1;
  size = 0;
  
//grabs numbers from right to left

  while(c != 0)
  {
    temp = c % 10;
    c = c / 10;
    size++;
  }

  msp = new char[size + 1];

//stores numbers in reverse order

  for(int i = size - 1; i >= 0; i--)
  {
    temp1 = x % 10 + '0';
    x = x / 10;
    msp[i] = temp1;
  }
  msp[size] = '\0';
  currentsize = size - 1;
}

MyString::~MyString()
{
  delete [] msp;
}

MyString::MyString(const MyString& s)
{
  size = s.size;
  msp = new char[size + 1];

  for(int i = 0; i < size + 1; i++)
    msp[i] = s.msp[i];
  msp[size] = '\0';  

  currentsize = size - 1;
}

MyString& MyString::operator=(const MyString& s)
{
  if(this != &s)
  {
    delete [] msp;

    size = s.size;
    msp = new char[size + 1];
    for(int i = 0; i < size + 1; i++)
      msp[i] = s.msp[i];
    msp[size] = '\0';
  }
}

MyString& MyString::operator+=(const MyString& s)
{
  strcat(msp, s.msp);  
}

char& MyString::operator[] (unsigned int index)
{  
  if(index > size)
  {
    char* str = new char[index + 1];
    
    strcpy(str, msp);
    
//fills added spots with spaces

    for(int i = size; i < index + 1; i++)
      str[i] = ' ';

    delete [] msp;
    msp = str;
    str[index + 1] = '\0';
    size = index;

//returns the param at last spot

    return str[index];
  }
  else
    return msp[index];
}

const char& MyString::operator[] (unsigned int index) const
{
  MyString null;  //constructor with no param creates an object
		  //  with only a null pointer

  if(index > size)
    return null.msp[0];
  else
    return msp[index];
}

MyString& MyString::insert(unsigned int index, const MyString& s)
{
  int slen = strlen(s.msp);
  int newlen = size + slen;
  int mspsize = size;

//creates array of new size and shifts indices to the end

  Grow(newlen);
  for(int i = mspsize; i > index - 1; i--)
    msp[i + slen] = msp[i];

//adds new string to *this

  for(int i = 0; i < slen; i++)
    msp[index + i] = s.msp[i];

  return *this;
}

int MyString::indexOf(const MyString& s) const
{  
  char* ptr = strstr(msp, s.msp);

//returns position

  if(ptr != '\0')
    return ptr-msp;
  else
    return -1;
} 
  
int MyString::getLength() const
{
  return size;
}

const char* MyString::getCString() const
{
  return msp;
}

MyString MyString::substring(unsigned int f, unsigned int t) const
{
  MyString r;

  if(f > t || t > size)
    t = size;

  r.Grow();
  for(int i = 0; i < t; i++)
    r.msp[i] = msp[i+f];

  return r.msp;
}

MyString MyString::substring(unsigned int f) const
{
  MyString r;
  
  r.Grow();
  for(int i = 0; i < size + 1; i++)
    r.msp[i] = msp[i + f];

  return r.msp;
}
 
void MyString::Grow()
{

//no parameter creates an array of size + 5

  size = size + 5;
  char* str = new char[size + 1];

  for(int i = 0; i < currentsize; i++)
    str[i] = msp[i];

  delete [] msp;
  msp = str;
}

void MyString::Grow(int x)
{

//allows to pass in a size as param

  size = x;
  char* str = new char[size + 1];

  for(int i = 0; i < size + 1; i++)
    str[i] = msp[i];

  delete [] msp;
  msp = str;
}
