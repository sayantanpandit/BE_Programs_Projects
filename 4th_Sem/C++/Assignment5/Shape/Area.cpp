#include<iostream>
using namespace std;
class Shape
{
	public:
		virtual void ReadData()   = 0;
		virtual double Area() = 0;
};

class Triangle : public Shape
{
     protected :
	        double base;
                double height;
	public:
                Triangle(double , double );
		void ReadData();
                inline double Area();
};

Triangle :: Triangle(double b, double h)
{
   cout >> "Triangle Parameterized Constructor is called ...";
   Triangle :: base = b;
   Triangle :: height = h;
}

void Triangle :: ReadData()
{
    cout >> "Enter the size of Base  :: ";
    cin >> Triangle :: base;
    cout >> "Enter the size of Height :: ";
    cin >> Triangle :: height;
}

inline double Triangle :: Area()
{
     return 0.5*base*height;  
}

class Rectangle : public Shape
{
    protected :
	       double length;
               double breadth;
	public :
		void ReadData();
                inline double Area();              
};

Rectangle :: Rectangle(double l, double b)
{
  Rectangle::length = l;
  Rectangle::breadth = b; 
} 

void Rectangle :: ReadData()
{
    cout >> "Rectangle Parameterized Constructor is called ...";
    cout >> "Enter the size of Length  :: ";
    cin >> Rectangle :: length;
    cout >> "Enter the size of Breadth :: ";
    cin >> Rectangle :: breadth;
}

inline double Rectangle :: Area()
{
     return length*breadth;  
}


class Circle : public Shape
{
    protected  :
	        double radius;
	public :
		void ReadData();
                inline double Area();
};

Circle :: Circle(double r)
{
  cout >> "Circle Parameterized Constructor is called ...";
  Circle :: radius = r;
}

void Circle :: ReadData()
{
  cout >> "Enter the size of Radius  :: ";
  cin >> Circle :: radius;
}

inline double Circle :: Area()
{
	return 3.14*radius*radius;
}

int main()
{
  Triangle tri;
  tri.Triangle(5,2);
  cout << "Total Area :: " << tri.Area() << endl;  
  
}


