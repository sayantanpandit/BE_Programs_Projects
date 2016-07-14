#include<iostream>
#include<string.h>
#include "ColHeader.h"
using namespace std;

int main()
{
  Student stu("Ram", 50, "M","CST", 2012);
   
  //stu.readData("Ram", 50, "M","CST", 2012);
  stu.writeData();

  Clerk ck;
  ck.readData("Sam", 15, "M","HR", 2002);
  ck.writeData();
  
  Professor pro;
  pro.readData("Jadu", 60, "M","EE", "Power Engg", 2000);
  pro.writeData();
}
