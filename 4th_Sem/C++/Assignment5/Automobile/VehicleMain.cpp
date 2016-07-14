#include <iostream>
#include "Vehicle.h"

using namespace std;

int main()
{
  Car c1,c2; 
  //c2 = c1;         //Assignment Car Constructor will be called
  //Car c3 = c1;         //Copy Car Constructor will be called...

  //Car c1(1234, "MRF","Red", 60, "A1");
  c1.ReadData(1234, "MRF","Red", 60, "A1");
  c1.PrintData();
    
  c2.ReadData(1235, "Hero","Blue", 3, "A");
  c2.PrintData();
}
