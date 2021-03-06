// Fig. 21.4: list.h
// Template List class definition.
#ifndef LIST_H
#define LIST_H

#include <iostream>
using std::cout;

#include <new>
#include "listnode.h"  // ListNode class definition

template< class NODETYPE >
class List 
{
public:
   List();      // constructor
   ~List();     // destructor
   List(const List < NODETYPE > & );
   List& operator=(const List < NODETYPE > & );
   void insertAtFront( const NODETYPE & );
   void insertAtBack( const NODETYPE & );
   void insertMiddle( const NODETYPE &, int);
   bool removeFromFront( NODETYPE & );
   bool removeFromBack( NODETYPE & );
   bool removeMiddle( NODETYPE &, int);
   bool isEmpty() const;
   void print() const;

private:
   ListNode< NODETYPE > *firstPtr;  // pointer to first node
   ListNode< NODETYPE > *lastPtr;   // pointer to last node

   // utility function to allocate new node
   ListNode< NODETYPE > *getNewNode( const NODETYPE & );

}; // end class List

// default constructor
template< class NODETYPE >
List< NODETYPE >::List() 
   : firstPtr( 0 ), lastPtr( 0 ) 
{ 
   // empty body

} // end List constructor

// destructor
template< class NODETYPE >
List< NODETYPE >::~List()
{
   if ( !isEmpty() ) {    // List is not empty

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 )         // delete remaining nodes
      {  
         tempPtr = currentPtr;

         currentPtr = currentPtr->nextPtr;
         delete tempPtr;
      }
   }
}
//   cout << "All nodes destroyed\n\n";

template< class NODETYPE >
List< NODETYPE >::List(const List< NODETYPE >& L)
{
  firstPtr = lastPtr = 0;
  ListNode< NODETYPE > *tempPtr;
  tempPtr = L.firstPtr;
  while(tempPtr != 0)
  {
    insertAtBack(tempPtr->getData());
    tempPtr = tempPtr->nextPtr;
  }
}

template< class NODETYPE >
List< NODETYPE >& List< NODETYPE >::operator=(const List< NODETYPE >& L)
{
  //destructor
  NODETYPE value;

  while(!isEmpty())
    removeFromFront(value);

  //copy constructer
  firstPtr = lastPtr = 0;
  ListNode< NODETYPE > *tempPtr;
  tempPtr = L.firstPtr;

  while(tempPtr != 0)
  {
    insertAtBack(tempPtr->getData());
    tempPtr = tempPtr->nextPtr;
  }

  return *this;
}

// insert node at front of list
template< class NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      newPtr->nextPtr = firstPtr;
      firstPtr = newPtr;

   } // end else

} // end function insertAtFront

// insert node at back of list
template< class NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      lastPtr->nextPtr = newPtr;
      lastPtr = newPtr;

   } // end else

} // end function insertAtBack

template< class NODETYPE >
void List< NODETYPE >::insertMiddle( const NODETYPE &value, int index)
{
  int size = 0;
  ListNode< NODETYPE > *currentPtr = firstPtr;
  ListNode< NODETYPE > *tempPtr;
  ListNode< NODETYPE > *newPtr = getNewNode(value);

  while ( currentPtr != 0 ) 
  {
    currentPtr = currentPtr->nextPtr;
    size++;
  } 
  
  currentPtr = firstPtr;

  if(index > size)
  {
    insertAtBack(value);
    return;
  }
  if(index < 2)
  {
    insertAtFront(value);
    return;
  }
 
  for(int i = 0; i < index - 2; i++)
     currentPtr = currentPtr->nextPtr;

  tempPtr = currentPtr->nextPtr;
  currentPtr->nextPtr = newPtr;
  newPtr->nextPtr = tempPtr; 
}

// delete node from front of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
   if ( isEmpty() )  // List is empty
      return false;  // delete unsuccessful

   else {  
      ListNode< NODETYPE > *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else
         firstPtr = firstPtr->nextPtr;

      value = tempPtr->data;  // data being removed
      delete tempPtr;

      return true;  // delete successful

   } // end else

} // end function removeFromFront

// delete node from back of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
   if ( isEmpty() )
      return false;  // delete unsuccessful

   else {
      ListNode< NODETYPE > *tempPtr = lastPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else {
         ListNode< NODETYPE > *currentPtr = firstPtr;

         // locate second-to-last element
         while ( currentPtr->nextPtr != lastPtr )
            currentPtr = currentPtr->nextPtr;

         lastPtr = currentPtr;
         currentPtr->nextPtr = 0;

      } // end else

      value = tempPtr->data;
      delete tempPtr;

      return true;  // delete successful

   } // end else

} // end function removeFromBack

template< class NODETYPE >
bool List< NODETYPE >::removeMiddle( NODETYPE &value, int index)
{
  int size = 0;
  ListNode< NODETYPE > *currentPtr = firstPtr;
  ListNode< NODETYPE > *tempPtr;

  while ( currentPtr != 0 ) 
  {
    currentPtr = currentPtr->nextPtr;
    size++;
  } 
  
  currentPtr = firstPtr;

  if(index > size)
    return false;

  if(index < 1)
    return false;
 
  if(index == 1)
  {
    removeFromFront(value);
    return true;
  }

  for(int i = 1; i < index-1; i++)
     currentPtr = currentPtr->nextPtr;

  cout << "current pointer data is : " << currentPtr->data << endl;
  tempPtr = currentPtr->nextPtr;
  cout << "data removed is: " << tempPtr->data << endl;  
  value = tempPtr->data;
  currentPtr->nextPtr = tempPtr->nextPtr;
  delete tempPtr;

  return true;
}

// is List empty?
template< class NODETYPE > 
bool List< NODETYPE >::isEmpty() const 
{ 
   return firstPtr == 0; 
   
} // end function isEmpty

// return pointer to newly allocated node
template< class NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode( 
   const NODETYPE &value )
{
   return new ListNode< NODETYPE >( value );

} // end function getNewNode

// display contents of List
template< class NODETYPE >
void List< NODETYPE >::print() const
{
   if ( isEmpty() ) {
      cout << "The list is empty\n\n";
      return;

   } // end if

   ListNode< NODETYPE > *currentPtr = firstPtr;

   cout << "The list is: ";

   while ( currentPtr != 0 ) {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;

   } // end while

   cout << "\n\n";

} // end function print

#endif

/**************************************************************************
 * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and Prentice      *
 * Hall. All Rights Reserved.                                             *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
