#include<iostream>
#include<string.h>
#include "Vehicle.h"

using namespace std;

Vehicle :: Vehicle()
{
   cout << "Default Vehicle Constructor is Called ... "<< endl;
   price = 0;
   manufacturer=NULL;
}

Vehicle :: Vehicle(double p, const char *manu)
{
    cout << "Parameterized Vehicle Constructor is Called ... "<< endl;
    price = p;
    manufacturer = new char[strlen(manu) + 1];
    strcpy(manufacturer, manu);
}

Vehicle :: ~Vehicle(void)
{
   cout << "Default Vehicle Destructor is Called ..." << endl;
}

Vehicle :: Vehicle(const Vehicle &obj)
{
  cout << "Copy Vehicle Constructor is Called ..." << endl;
  
  price = obj.price;
  manufacturer = new char[strlen(obj.manufacturer) + 1];
  strcpy(manufacturer, obj.manufacturer);
  
}

Vehicle &Vehicle :: operator = (const Vehicle &obj)
{
  cout << "Assignment Constructor is Called ..." << endl;
  
  price = obj.price;
  manufacturer = new char[strlen(obj.manufacturer) + 1];
  strcpy(manufacturer, obj.manufacturer);
}

void Vehicle :: ReadData(double p, const char *manu)
{
  price = p;
  manufacturer = new char[strlen(manu) + 1];
  strcpy(manufacturer, manu);
}

void Vehicle :: PrintData()
{
  cout << "Price            :: " << price << endl;
  cout << "Manufacturer     :: " << manufacturer << endl;
}


Car :: Car()
{
   cout << "Default Car Constructor is Called ... "<< endl;
}

Car :: Car(const double p, const char* manu, const char *c, int nOS, const char *m) : Vehicle(p,manu)
{
   cout << "Parameterized Car Constructor is Called ... "<< endl;
   
   color = new char[strlen(c)+1];
   strcpy(color,c);
   numberOfSeats = nOS;
   model = new char[strlen(m)+1];
   strcpy(model,m);
}

Car :: ~Car(void)
{
   cout << "Default Car Destructor is Called ..." << endl;
}

Car :: Car(const Car &obj)
{
  cout << "Copy Car Constructor is Called ..." << endl;
}

Car &Car :: operator = (const Car &obj)
{
  cout << "Assignment Car Constructor is Called ..." << endl;
  
  color = new char[strlen(obj.color)+1];
  strcpy(color,obj.color);
  numberOfSeats = obj.numberOfSeats;
  model = new char[strlen(obj.model)+1];
  strcpy(model,obj.model);
  Vehicle::operator = (obj);
}

void Car :: ReadData(double p, const char *manu,const char *c, int noS, const char *m)
{
   Vehicle :: ReadData(p,manu);

   color = new char[strlen(c)+1];
   strcpy(color,c);
   numberOfSeats = noS;
   model = new char[strlen(m)+1];
   strcpy(model,m);
}

void Car :: PrintData()
{
   Vehicle::PrintData();
   
   cout << "The Color        :: " << color << endl;
   cout << "The No. of Seats :: " << numberOfSeats << endl;
   cout << "Model            :: " << model << endl;
}
