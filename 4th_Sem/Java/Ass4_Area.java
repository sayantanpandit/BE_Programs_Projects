package studentdet;

import java.io.*;

abstract class Shape
{
        public void Read()throws IOException
	{}
	abstract double Area();
        abstract void Display();
}

class Rectangle extends Shape
{
	protected double Width;
	protected double Height;
	public void Read()throws IOException
	{
		System.out.print("Enter the Width of the rectangle:");
		DataInputStream z=new DataInputStream(System.in);
		Width=Double.parseDouble(z.readLine());
		System.out.println();
		System.out.print("Enter the Height of the rectangle:");
		Height=Double.parseDouble(z.readLine());
		System.out.println();
	}
	public double Area()
	{
		return Width*Height;
	}
	public void Display()
	{
		System.out.println("The area of the rectangle is:"+Area());
	}
}
final class Square extends Rectangle
{
	public void Read()throws IOException
	{
		System.out.print("Enter the length of the side of the square:");
		DataInputStream X=new DataInputStream(System.in);
		Width=Double.parseDouble(X.readLine());
		System.out.println();
		Height=Width;
	}
	public void Display()
	{
		System.out.println("The area of the square is:"+Area());
	}
}
class Triangle extends Shape
{
	private double Side1;
	private double Side2;
	private double Side3;
	public void Read()throws IOException
	{
		while(true)
		{
			System.out.print("Enter the length of the side1 of the triangle :: ");
			BufferedReader buff = new BufferedReader (new InputStreamReader(System.in));
			Side1=Double.parseDouble(buff.readLine());
			System.out.println();
			System.out.print("Enter the length of the side2 of the triangle :: ");
			Side2=Double.parseDouble(buff.readLine());
			System.out.println();
			System.out.print("Enter the length of the side3 of the triangle :: ");
			Side3=Double.parseDouble(buff.readLine());
			System.out.println();
			if((Side1+Side2>Side3)&&((Side1+Side3)>Side2)&&((Side2+Side3)>Side1))
			{
				break;
			}
			else
			{
				System.out.println("The triangle side lengths are not valid");
				continue;
			}
		}
	}
	public double Area()
	{
		double temps,tempresult;
		temps=(Side1+Side2+Side3)/2;
		tempresult=temps*(temps-Side1)*(temps-Side2)*(temps-Side3);
		return Math.sqrt(tempresult);
	}
        
	public void Display()
	{
		System.out.println("The area of the Triangle is:"+Area());
	}
}

class Circle extends Shape
{
	private double Radious;
	public void Read()throws IOException
	{
		System.out.print("Enter the radious of the circle:");
		BufferedReader buff = new BufferedReader (new InputStreamReader(System.in));
		Radious=Double.parseDouble(buff.readLine());
	}
	public double Area()
	{
		return Math.PI*Radious*Radious;
	}
	public void Display()
	{
		System.out.println("The area of the circle is:"+Area());
	}
}		
class Mainsclass
{
	public static void main(String args[])throws IOException
	{
		double Totalarea=0;
		int totalobjs=0;
		char selectobj;
		String tempselectobj;
		System.out.print("Enter the total no. of objects you want to create:");
		BufferedReader buff = new BufferedReader (new InputStreamReader(System.in));
		totalobjs=Integer.parseInt(buff.readLine());
		System.out.println();		
		Shape []shp=new Shape[totalobjs];		
		for(int i=0;i<totalobjs;i++)
		{
			System.out.print("Enter C for creating circle,S for creating Square,R for creating Rectangle,T for creating triangle:");
			tempselectobj=buff.readLine();
			selectobj=tempselectobj.charAt(0);
			if(selectobj=='C')
			{
				shp[i]=new Circle();
			}
			else if(selectobj=='S')
			{
				shp[i]=new Square();
			}
			else if(selectobj=='R')
			{
				shp[i]=new Rectangle();
			}
			else if(selectobj=='T')
			{
				shp[i]=new Triangle();
			}
			else
			{
				System.out.println("Invalid choice. Enter a valid choice");
				i--;
				continue;
			}
			shp[i].Read();
		}
		for(int j=0;j<totalobjs;j++)
		{
			Totalarea+=shp[j].Area();
			shp[j].Display();
		}
		System.out.println("The total area is:"+Totalarea);
	}
}
