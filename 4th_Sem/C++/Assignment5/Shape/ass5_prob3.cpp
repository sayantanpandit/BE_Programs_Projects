#include<iostream>
using namespace std;
class Shape{
	public:
		virtual void Read()=0;
		virtual double Area()=0;
};
class Rectangle:public Shape{
	double length,breadth;
	public:
		void Read(){
			cin>>length>>breadth;
		}
		double Area(){
			return length*breadth;
		}
};
class Triangle:public Shape{
	double base,height;
	public:
		void Read(){
			cin>>base>>height;
		}
		double Area(){
			return 0.5*base*height;
		}
};
class Circle:public Shape{
	double radius;
	public:
		void Read(){
			cin>>radius;
		}
		double Area(){
			return 3.14*radius*radius;
		}
};



int main()
{
	double area1=0,area2=0,area3=0,totalArea=0;
	int n1,n2,n3,n;
	cout<<"Enter number of rectangles"<<endl;
	cin>>n1;
	
	
	cout<<"Enter number of triangles"<<endl;
	cin>>n2;
	cout<<"Enter number of circles"<<endl;
	cin>>n3;
	cout<<"Reading Parameters of Shapes:"<<endl;
	Shape * p1[n1];
		for(int i=0;i<n1;i++)
	    {
	    	p1[i]=new Rectangle();
	    }
	    //Read rectangle data
	    	for(int a=0;a<n1;a++)
	{
		p1[a]-> Read();
	}
	//find rectangle area
	for(int a=0;a<n1;a++)
	{
		area1+=p1[a]-> Area();
	}
	//delete p1;
	Shape * p2[n2];
	for(int j=0;j<n2;j++)
	    {
	    	p2[j]=new Triangle();
	    }
	    //read triangle data
	    	for(int b=0;b<n2;b++)
	{
		p2[b]-> Read();
	}
	//find triangle area
		for(int b=0;b<n2;b++)
	{
		area2+=p2[b]-> Area();
	}
	 //delete p2;
	Shape * p3[n3];

	
	for(int k=0;k<n3;k++)
	    {
	    	p3[k]=new Circle();
	    }
	

	//read circle data
	for(int c=0;c<n3;c++)
	{
		p3[c]-> Read();
	}
	
//find circle area
	for(int c=0;c<n3;c++)
	{
		area3+=p3[c]-> Area();
	}
	// delete p3;
		totalArea=area1+area2+area3;
		
	cout<<"The total area of all the shapes is"<<totalArea<<endl;
    
}


