#include<iostream>
#include<string.h>
#include "Area.h"

using namespace std;

void Shape :: readData()
{
   cout << "Enter the length of Rectangle  :: ";
    
   cout << "Enter the breadth of Rectangle :: ";
  
}

double Shape :: Area()
{
  //return length * breadth;
}



void Rectangle :: readData()
{
   cout << "Enter the length of Rectangle  :: ";
   cin >> length;
    
   cout << "Enter the breadth of Rectangle :: ";
   cin >> breadth;
  
}

double Rectangle :: Area()
{
  return length * breadth;
}

void Triangle :: readData()
{
   cout << "Enter the base of Triangle    :: ";
   cin >> base;

   cout << "Enter the height of Triangle  :: ";
   cin >> height;
  
}

double Triangle :: Area()
{
  return 0.5 * base * height;
}

void Circle :: readData()
{
   cout << "Enter the radius of Circle    :: ";
   cin >> radius;
  
}

double Circle :: Area()
{
  return 3.14 * radius * radius; 
}
