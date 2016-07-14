package studentdet;

import java.io.*;

public class Ass3_University 
{
 
    public static void main(String args[])throws IOException
    {
        String choice = "";
	String tempchoice;
	AllDetails []uni = new AllDetails[10];
	AllDetails prsn1;
	
        Students s = new Students();
        Professor p = new Professor();
        
        for(int i=0;i<10;i++)
	{
		System.out.print("Enter S for creating a database for students,\nenter P for creating a database for Professors:");
		BufferedReader buff = new BufferedReader (new InputStreamReader(System.in));
		tempchoice=buff.readLine();
		
		if(choice.equalsIgnoreCase("s"))
		{
			uni[i]=new Students();
		}
		else if(choice.equalsIgnoreCase("p"))
		{
			uni[i]=new Professor();
		}
		else
		{
			System.out.println("Invalid choice. Enter again");
			i--;
		}
		uni[i].ReadDatabase();
	}
	for(int j=0;j<10;j++)
	{
		uni[j].DisplayDatabase();
	}
	prsn1=s;
	prsn1.ReadDatabase();
	prsn1.DisplayDatabase();
	prsn1=p;
	prsn1.ReadDatabase();
	prsn1.DisplayDatabase();
    }
    
    class AllDetails
    {
	private String Name;
	private int Age;
	private String Gender;
	
        public AllDetails()
	{
		System.out.println("All Details -> Default Constructor");
		Name = null;
		Age = 0;
		Gender = null;
	}
        
	public AllDetails(final String tempName, final int tempAge, final String tempGender)
	{
		 Name=tempName;
		 Age=tempAge;
		 Gender=tempGender;
	}
        
	public void ReadDatabase()throws IOException
	{
          BufferedReader buff = new BufferedReader (new InputStreamReader(System.in));
	  
          System.out.print("Enter the name:");
	  Name = buff.readLine();
          
   	  System.out.print("Enter the age:");
	  Age = Integer.parseInt(buff.readLine());
	  
	  System.out.print("Enter the Gender(M/F):");
          Gender=buff.readLine();
   	 
	}
        
	public void DisplayDatabase()
	{
	  	System.out.println("The name is:"+Name);
		System.out.println("The age is:"+Age);
		System.out.println("The gender is:"+Gender);
	}
}
class Students extends AllDetails
{
	private String Dept;
	private int Year;
        
	public Students()
	{
		System.out.println("Students -> Default Constructor");
		Dept = null;
		Year = 1;
	}
        
	public Students(final String tempName,final int tempAge, final String tempGender,final String tempDept,final int tempYear)
	{
		super(tempName,tempAge,tempGender);
		Dept=tempDept;
		Year=tempYear;
	}
        
	public void ReadDatabase()throws IOException
	{
          BufferedReader buff = new BufferedReader (new InputStreamReader(System.in));
	  System.out.println("Enter the data for the students");
	  super.ReadDatabase();
	  
	  System.out.print("Enter Department :: ");
          Dept = buff.readLine();
          
   	  System.out.print("Enter the year:");
	  Year=Integer.parseInt(buff.readLine());
	}
        
	public void DisplayDatabase()
	{
		System.out.println("Display the data for the students");
		super.DisplayDatabase();
		System.out.println("The Department is:"+Dept);
		System.out.println();
		System.out.println("The Year is:"+Year);
	}
}
class Professor extends AllDetails
{
	private String Dept;
	private int Courseload;
	private int Salary;
        
	public Professor()
	{
		System.out.println("Professor -> Default Constructor");
		Dept = null;
		Courseload = 8;
		Salary = 1000;
	}
        
	public Professor(final String tempName,final int tempAge,final String tempGender, final String tempDept,final int tempCourseload,final int tempSalary)
	{
		super(tempName,tempAge,tempGender);
		Dept = tempDept;
		Courseload = tempCourseload;
		Salary = tempSalary;
	}
        
	public void ReadDatabase()throws IOException
	{
          BufferedReader buff = new BufferedReader (new InputStreamReader(System.in));
	  System.out.println("Enter the Data for the professor");
	  super.ReadDatabase();
	  
          System.out.print("Enter Department ::");
          Dept=buff.readLine();
          
   	  System.out.print("Enter Courseload :: ");
	  Courseload=Integer.parseInt(buff.readLine());
	  
	  System.out.print("Enter Salary     :: ");
	  Salary=Integer.parseInt(buff.readLine());
	  
	}
        
	public void DisplayDatabase()
	{
		System.out.println("Display the data for the professor");
		super.DisplayDatabase();
		
                System.out.println("The Department is :: "+Dept);
		System.out.println("The Courseload is :: "+Courseload);
		System.out.println("The Salary is     :: "+Salary);
	}
}

}
