#include<iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

#define noOfStack 5

using namespace std;


class MyStack
{
   private :
           int top;
           int size;
           int *s;
   public :
	   MyStack(void);
	   void Initialize();
	   void Push(); 
	   int Pop();
           int MaxSize();
           int IsEmpty();
	   void Display();
};

void MyStack :: Initialize()
{
     cin >> size;
     s = new int[size];
}

void MyStack :: Push()
{
    int x;
    if(top == size-1)
	cout << "Stack Overflow !!! "<<endl;
    else
    {
        cout << "Enter no. to be pushed ::";
	cin >> x;
	top++;
	s[top] = x;
     }
}

int MyStack :: Pop()
{
   if(top == -1)
	return 0;
   else
        return s[top--];
}

int MyStack :: MaxSize()
{
     return size;
}

int MyStack :: IsEmpty()
{
   if(top==-1)
       return 0;
   else
       return 1;
}

void MyStack :: Display()
{
      int i,p=top;
      for(i=0;i<=p;i++)
	  cout<<s[i]<<endl;
}

MyStack::MyStack(void)
{
	MyStack::top = -1;
	MyStack::size = 0;
	MyStack::s = new int[MyStack::size];
}

int main()
{
	int n,i;
	cout << "Enter no. of Stacks :: ";
	cin >> n;
	MyStack * ms = new MyStack();
	for(i=0; i<n; i++)
	{
		cout<<"Enter size of stack " << i+1 << " :: ";
		ms[i].Initialize();
	}
	int c,s;

	while(1)
	{
	  cout << "     Operations     " << endl;
	  cout << "1. Create new Stack  Press 1"<<endl;
	  cout << "2. Push              Press 2"<<endl;
          cout << "3. Pop               Press 3" << endl;
          cout << "4. Maximum Size      Press 4" << endl;
          cout << "5. Is Empty          Press 5" << endl;
          cout << "6. Display           Press 6" << endl;
          cout << "7. No. of Stacks     Press 7" << endl;
          cout << "8. Update a Stack    Press 8" << endl;         
          cout << "9. Exit              Press 9" << endl;
	  cout<<"Enter your choice :: ";
	  cin >> c;
	  
          if(n > 1 && c != 1)
	  {
	     cout << "Operation on which Stack :: ";
	     cin >> s;
	  }
	  else
	       s = 1;
	  if(c == 1)
          {
             if( i < noOfStack)
             {
	       cout<<"Enter size of stack " << i+1 << " :: ";
	       ms[i++].Initialize();
             }
             else
               cout << "STACK Limit is full. U cant create any more stack." << endl;
          }
	  else if(c == 2)
	        ms[s-1].Push();
	  else if(c == 3)
	  {
		if(ms[s-1].Pop()==0)
			cout<<"stack underflow!"<<endl;
		else
			cout<<ms[s-1].Pop()<<endl;
	  }
	  else if(c==4)
		cout<<ms[s-1].MaxSize()<<endl;
	  else if(c==5)
	  {
		 if(ms[s-1].IsEmpty()==0)
		      cout<<"True"<<endl;
		 else
		      cout<<"False"<<endl;
	  }
	  else if(c == 6)
		ms[s-1].Display();
          else if(c == 7)
                cout << "No. of Stack :: " << i << endl;
          else if(c == 8)
          {
             
          }
	  else if(c == 9)
		exit(1);
	  else
	       cout<<"Wrong input!"<<endl;
	}

	int k;
	cout << "Which stack do you want to copy ??";
	cin >> k;
	MyStack c1 = ms[k-1];
	while(1)
	{
	  cout << "     Operations     " << endl;
	  cout << "1. Create new Stack  Press 1"<<endl;
	  cout << "2. Push              Press 2"<<endl;
          cout << "3. Pop               Press 3" << endl;
          cout << "4. Maximum Size      Press 4" << endl;
          cout << "5. Is Empty          Press 5" << endl;
          cout << "6. Display           Press 6" << endl;
          cout << "7. No. of Stacks     Press 7" << endl;
          cout << "8. Update a Stack    Press 8" << endl;         
          cout << "9. Exit              Press 9" << endl;
	  cout<<"Enter your choice :: ";
	    
            cin >> c;
 
	    if(c == 1)
          	c1.Push();
	    else if(c == 2)
	    {	
		if(c1.Pop() == 0)
		     cout<<"Stack Underflow!" <<endl;
		else
		     cout << ms[s-1].Pop() <<endl;
	     }
	     else if(c == 3)
		cout << c1.MaxSize() << endl;
	     else if(c == 4)
	     {
		if(c1.IsEmpty() == 0)
		    cout << "True" << endl;
		else
		    cout<<"False"<<endl;
	      }		
	      else if(c == 5)
		 c1.Display();
	      else if(c == 6)
		 break;
	      else
		cout << "Wrong input!" << endl;
	}
	return 0;
}
