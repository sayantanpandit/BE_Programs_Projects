#include<iostream>
#include<string.h>
#include "ColHeader.h"
using namespace std;


AllDetails :: AllDetails()
{
   cout << "Default AllDetails Constructor is called ..."  << endl;
   Name = NULL;
   Age = 0;
   Gender = NULL;
}

AllDetails :: AllDetails(const char *n, int a, const char *g)
{
   cout << "Parametrized AllDetails Constructor is called ..."  << endl;
   
   Name = new char[strlen(n) + 1];
   strcpy(Name, n);
   Age    = a;
   Gender = new char[strlen(g) + 1];
   strcpy(Gender, g);
}

AllDetails :: ~AllDetails()
{
  cout << "Default AllDetails Destructor is called ..."  << endl;
}

void AllDetails :: readData(const char *n, int a, const char  *g)
{
   Name = new char[strlen(n) + 1];
   strcpy(Name, n);
   Age    = a;
   Gender = new char[strlen(g) + 1];
   strcpy(Gender, g);
}

void AllDetails :: writeData()
{
   cout << "Name     :: " << Name   << endl;
   cout << "Age      :: " << Age    << endl;
   cout << "Gender   :: " << Gender << endl;
}

Student :: Student()
{
    cout << "Default Student Constructor is called ..."  << endl;
    Dept = NULL;
    Year = 0;
}

Student :: Student(const char *n, int a, const char *g, const char *dpt, int yrs):AllDetails(n,a,g)
{
   cout << "Parametrized Student Constructor is called ..."  << endl;
   
   Dept = new char[strlen(dpt) + 1];
   strcpy(Dept,dpt);
   Year  = yrs;
}

Student :: ~Student()
{
    cout << "Default Student Destructor is called ..."  << endl;
}

void Student :: readData(const char *n, int a, const char *g, const char *dpt, int yrs)
{
   AllDetails::readData(n,a,g);
  
   strcpy(Dept,dpt);
   Year  = yrs;
}

void Student :: writeData()
{
   AllDetails::writeData();

   cout << "Dept     :: " << Dept   << endl;
   cout << "Year     :: " << Year   << "\n\n" << endl;
}


Clerk :: Clerk()
{
    cout << "Default Clerk Constructor is called ..."  << endl;
    WorkLoad = NULL;
    Salary = 0;
    
}

Clerk :: Clerk(const char *n, int a, const char *g,  const char * wl, double sal) : AllDetails(n,a,g)
{
   cout << "Parametrized Clerk Constructor is called ..."  << endl;
   
   WorkLoad = new char[strlen(wl) + 1];
   strcpy(WorkLoad, wl);
   Salary   = sal;
}

Clerk :: ~Clerk()
{
    cout << "Default Clerk Destructor is called ..."  << endl;
}

void Clerk :: readData(const char *n, int a, const char *g,  const char * wl, double sal)
{
   AllDetails::readData(n,a,g);
 
   WorkLoad = new char[strlen(wl) + 1];
   strcpy(WorkLoad, wl);
   Salary   = sal;
}

void Clerk :: writeData()
{
   AllDetails::writeData();

   cout << "WorkLoad :: " << WorkLoad << endl;
   cout << "Salary   :: " << Salary   << "\n\n" << endl;
}

Professor :: Professor()
{
    cout << "Default Professor Constructor is called ..."  << endl;
    Dept = NULL;
    CourseLoad = NULL;
    Salary = 0;
}

Professor :: Professor(const char *n, int a, const char *g, const char *dept, const char *cl, double sal) : AllDetails(n,a,g)
{
   cout << "Parametrized Clerk Constructor is called ..."  << endl;  
   
   
   strcpy(Dept,dept);
   strcpy(CourseLoad,cl);
   Salary     = sal;
}

Professor :: ~Professor()
{
    cout << "Default Professor Destructor is called ..."  << endl;
}

void Professor::readData(const char *n, int a, const char *g, const char *dept, const char *cl, double sal)
{
   AllDetails::readData(n,a,g);
  
   strcpy(Dept,dept);
   strcpy(CourseLoad,cl);
   Salary     = sal;
}

void Professor :: writeData()
{
   AllDetails::writeData();
   cout << "Dept       :: " << Dept       << endl;
   cout << "CourseLoad :: " << CourseLoad << endl;
   cout << "Salary     :: " << Salary  << "\n\n" << endl;
}

