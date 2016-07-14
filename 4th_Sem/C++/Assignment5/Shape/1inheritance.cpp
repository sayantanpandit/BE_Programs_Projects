#include<iostream>
#include<cstring>
using namespace std;
class Vehicle{
      private:
      int price;
      char *manu;
      public:
      Vehicle():price(0),manu(NULL){}
      Vehicle(const int &p,char *name)
      {
         price=p;
         manu=new char[strlen(name)+1];
         strcpy(manu,name);
      }
      Vehicle(const Vehicle &p)
      {
	  price=p.price;
	  manu=new char[strlen(p.manu)+1];
	  strcpy(manu,p.manu);
      }
      Vehicle &operator=(const Vehicle &rhs)
      {
              manu=new char[strlen(rhs.manu)+1];
              strcpy(manu,rhs.manu);
              price=rhs.price;
      }
      void Read(const int &p,char *name)
      {
           price=p;
           manu=new char[strlen(name)+1];
           strcpy(manu,name);
      }
      void Display()
      {
           cout<<"Price :"<<price<<endl;
           cout<<"Manufacturer :"<<manu<<endl;
      }
      };
      class Car:public Vehicle{
            private:
            char *color;
            int noofseats;
            char *model;
            public:
            Car():color(NULL),noofseats(0),model(NULL){}
            Car(const int &p,char *nam,char *col,const int &seat,char *mod)
	    {
		color=new char[strlen(col)+1];
		strcpy(color,col);
		model=new char[strlen(mod)+1];
		strcpy(model,mod);
		noofseats=seat;
		Vehicle(p,nam);
	    }
  	    Car(const Car &rhs):Vehicle(rhs)
	    {
		color=new char[strlen(rhs.color)+1];
		strcpy(color,rhs.color);
		model=new char[strlen(rhs.model)+1];
		strcpy(model,rhs.model);
		noofseats=rhs.noofseats;
	    }
	    Car &operator=(const Car &rhs)
	    {
		color=new char[strlen(rhs.color)+1];
		strcpy(color,rhs.color);
		noofseats=rhs.noofseats;
		model=new char[strlen(rhs.model)+1];
		strcpy(model,rhs.model);
	   }
	   void Read(char *col,const int &seat,char *mod,const int &p,char *nam)
	   {
		Vehicle::Read(p,nam);
		color=new char[strlen(col)+1];
		strcpy(color,col);
		model=new char[strlen(mod)+1];
		strcpy(model,mod);
		noofseats=seat;
	   }
	   void Display()
	   {
		Vehicle::Display();
		cout<<"Colour :"<<color<<endl;
		cout<<"No Of Seats :"<<noofseats<<endl;
		cout<<"Model :"<<model<<endl;
	   }
	};
	int main()
	{
		Car c1;
		c1.Read("RED",5,"E250",258900,"MARUTI");
		c1.Display();
		Car c3=c1;
		cout<<"Displaying object created by assignment operator"<<endl;
		c3.Display();
	}
