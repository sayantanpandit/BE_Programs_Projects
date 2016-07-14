#include<iostream>
#include<string.h>
#include<cstring>
#include "Area.h"

using namespace std;

int main()
{
    double recArea=0, triArea=0, cirArea=0, totalArea=0;
    int n;

    cout << "Enter no. of Rectangles :: " << endl;
    cin >> n;
	
    Shape *p1[n];
    for(int i=0; i<n; i++)
  	p1[i] = new Rectangle();
    
    for(int a=0; a<n; a++)
    {
       cout << "For Rectangle :: " << (a+1) << endl;
       p1[a]-> readData();
    }
	
    for(int a=0; a<n; a++)
	recArea = recArea + p1[a]-> Area();
	

    cout << "Enter no. of Triangles  :: ";
    cin >> n;
     
    Shape *p2[n];
    for(int i=0; i<n; i++)
	p2[i]=new Triangle();
	    	
    for(int a=0; a<n; a++)
    {
       cout << "For Triangle :: " << (a+1) << endl;
       p2[a]-> readData();
    }
	
    for(int a=0; a<n; a++)
	triArea = triArea + p2[a]-> Area();
	

    cout << "Enter no. of Circles    :: ";
    cin >> n;
    
    Shape *p3[n];
    for(int k=0; k<n; k++)
	p3[k]=new Circle();

    for(int a=0; a<n; a++)
    {
       cout << "For Circle :: " << (a+1) << endl;
       p3[a]-> readData();
    }

    for(int a=0; a<n; a++)
		cirArea = cirArea + p3[a]-> Area();
	

    totalArea = recArea + triArea + cirArea;

    cout<<"The total Area :: "<< totalArea << endl;
    
}

