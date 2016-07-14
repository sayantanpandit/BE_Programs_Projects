
package studentdet;

import java.io.BufferedReader;
import java.io.*;

public class StudentDet 
{
    public static void main(String[] args) throws IOException
    {
       BufferedReader buff = new BufferedReader (new InputStreamReader(System.in));
       
       System.out.print("Enter the size of Batch :: ");
       int n = Integer.parseInt(buff.readLine());
       
       String name[] = new String[n];
       int roll[] = new int[n];
       
       for(int i = 0; i<n; i++)
       {
           System.out.print("Enter Name :: ");
           name[i] = buff.readLine();
           System.out.print("Enter Roll :: ");
           roll[i] = Integer.parseInt(buff.readLine());
       }
       
       System.out.print("Name\t\tRoll\n");
         
       for(int i = 0; i<n; i++)
       {
           System.out.print(name[i] + "\t\t");
           System.out.println(roll[i]);         
       }
       
       
    }
    
}
