#include <iostream>
#include <cstring>
#include "stack.h"

using namespace std;

bool isPalindrome(Stack <char>, char[], char[]);

int main()
{
  char next;

  char temp[100], original[100];

  Stack <char> charStack;
  
  cout << "Please enter a string:\n> ";
  cin.getline(original, 100);

  for(int i = 0; i <= strlen(temp); i++)
    temp[i] = tolower(original[i]);

  for(int i = 0; temp[i] != '\0'; i++)
  {
    if(int (temp[i]) >= 65 && int (temp[i]) <= 122)
    {
      next = temp[i];
      charStack.push(next);
    } 
  }    

  isPalindrome(charStack, temp, original);

  return 0;
}

bool isPalindrome(Stack <char> s, char array[], char og[])
{
  char ch;

  while(!s.isStackEmpty())
  {
    for(int i = 0; array[i] != '\0'; i++)
    {
      if(int (array[i]) >= 65 && int (array[i]) <= 122)
      { 
        s.pop(ch);
          if(ch != array[i])
          {
            cout << "\n\"" << og << "\" is NOT a palindrome" << endl;
            return false;
          }
      }
    }
  }
  
  cout << "\n\"" << og << "\" IS a palindrome" << endl;
  return true;
}
