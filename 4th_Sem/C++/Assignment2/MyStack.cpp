#include<iostream>
#include "MyStack.h"

using namespace std;

void Initialize (MyStack & theStack, unsigned int maxSize)
{
  theStack.top = 0;
 
  // Boundary checking, make it default in case invalid size is provided
  if((0 == maxSize) || (maxSize > STACKMAXSIZE))
  {
     maxSize = STACKMAXSIZE;
  }

  theStack.maxSize = maxSize;
  theStack.list = new int[maxSize];

  for(int i =0; i<maxSize; i++)
  {
     theStack.list[i] = 0;
  }
}

void Deinitialize(MyStack & theStack)
{
  delete []theStack.list;
  theStack.top = 0;
  theStack.maxSize = 0;
}

int Push(MyStack & theStack, const int & element)
{
  if(theStack.top == theStack.maxSize)
  {
    cout << "PUSH operation failed : STACK IS FULL" << endl;
    return ResultFailure;
  }

  theStack.list[theStack.top++] = element;
  return ResultSuccess;
}

int Push(MyStack & theStack, const int & elem1, const int & elem2)
{
  if((theStack.top+2) > theStack.maxSize)
  {
    cout << "PUSH operation failed : NO space available for two elements..." << endl;
    return ResultFailure;
  }
  
  theStack.list[theStack.top++] = elem1; 
  theStack.list[theStack.top++] = elem2; 
  return ResultSuccess;
}

int Pop(MyStack & theStack, int & elem)
{
   if(0 == theStack.top)
   {
     cout << "POP operation failed : The Stack is empty" << endl;
     return ResultFailure;
   }
  
  elem = theStack.list[--theStack.top];
  return ResultSuccess;
}

int IsEmpty(const MyStack & theStack)
{
  return theStack.top ? ResultFailure : ResultSuccess;
}

void Display(const MyStack &theStack)
{
  cout << "Stack Maximum Size : " << theStack.maxSize << endl;
  
  if(theStack.top == 0)
  {
     cout << "The Stack is Empty" << endl;
     return;
  }
 
  if(theStack.top == theStack.maxSize)
  {
    cout << "The Stack is full : " << theStack.top << ". Stack elements :: ";
  }
  else
  {
    cout << "The Stack current size : " << theStack.top << ". Stack elements : ";
  }

  for(int i = 0; i < theStack.top; i++)   
  {
    cout << theStack.list[i] << " " ;
  }
   cout << endl;
}
