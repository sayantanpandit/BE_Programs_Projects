package studentdet;

import java.io.*;

public class Student 
{
  public static void main(String[] args) throws IOException
  {
     BufferedReader buff = new BufferedReader (new InputStreamReader(System.in));
     
     System.out.print("Enter the size of Batch :: ");
     int n = Integer.parseInt(buff.readLine());
     StuFunc arr[] = new StuFunc[n];
    
     for(int i =0; i<n; i++)
     {
         arr[i] = new StuFunc();
         arr[i].ReadData();
     }
     
     System.out.println("Name\t\tAge\t\tDept\t\tYear");
     for(int i =0; i<n; i++)
     {
         arr[i].PrintData();
     }
  }
}


class StuFunc
{
     String name, dept;
     int age, year;
    
    public void ReadData() throws IOException
    {
       BufferedReader buff = new BufferedReader (new InputStreamReader(System.in));
    
       System.out.print("Enter Name :: ");
       name = buff.readLine();
       
       System.out.print("Enter Age  :: ");
       age = Integer.parseInt(buff.readLine());
       
       System.out.print("Enter Dept :: ");
       dept = buff.readLine();
       
       System.out.print("Enter Year :: ");
       year = Integer.parseInt(buff.readLine());
       
    }
    
    public void PrintData()
    {
        System.out.print(name + "\t\t");
        System.out.print(age + "\t\t");
        System.out.print(dept + "\t\t");
        System.out.println(year + "\t\t");
    }   
}