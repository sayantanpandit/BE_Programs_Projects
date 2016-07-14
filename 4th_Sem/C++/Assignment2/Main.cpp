#include<iostream>
#include "MyStack.h"
using namespace std;

// A sample client program to demonstrate Stack functionalities
int main()
{
   MyStack myStackTwo;
   
   Initialize(myStackOne, 42);
   Initialize(myStackTwo);
   
   Display(myStackOne);
   cout << endl << endl;
   Display(myStackTwo);
   
   Push(myStackOne, 4);
   Push(myStackOne, 3, 9);
   
   cout << "StackOne current size : " << CurrentSize(myStackOne) << endl;
   cout << "StackTwo maximum size : " << MaximumSize(myStackTwo) << endl;
   
   cout << endl << endl;
   Push(myStackTwo, 6, -7);
   
   Display(myStackOne);
   Display(myStackTwo);int elem = 0;
   
   if(ResultSuccess == Pop(myStackOne, elem))
   {
      cout << "Popped element from StackOne is : " << elem << endl;
   }
  
   // Push the popped element from StackOne into StackTwo
      Push(myStackTwo, elem);
      cout << endl << endl;
      Display(myStackOne);
      Display(myStackTwo);
      Deinitialize(myStackOne);
      Deinitialize(myStackTwo);
      
      MyStack myStackThree;
      Initialize(myStackThree, 4);
      Push(myStackThree, 3, 9);
      Push(myStackThree, 7);
      Push(myStackThree, 8, -11);
      Push(myStackThree, 5);
  
         cout << endl << endl;
      Display(myStackThree);
      Deinitialize(myStackThree);
      
    return 0;
}
