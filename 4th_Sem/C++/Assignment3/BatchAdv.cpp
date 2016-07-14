#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

class Student
{
	private:
		string name;
		int age;
		string dept;
		int year;
	public:
		void ReadStudentData();
		void PrintStudentData() const;
};

void Student :: ReadStudentData()
{
	string s;
	cout << "Enter Student's Name :: ";
	getline (cin, Student::name);
        
	
        cout << "Enter Age :: ";
	getline(cin,s);
        stringstream(s) >> Student::age;
	
        cout<<"Enter Department :: ";
	getline(cin, Student::dept);
	
        cout<< "Enter Year :: ";
	getline (cin,s);
        stringstream(s)  >> Student::year;
}
	
void Student::PrintStudentData() const
{
   cout << Student::name << "\t";
   cout << Student::age  << "\t";
   cout << Student::dept << "\t";
   cout << Student::year << endl;
}

int main()
{
	int n,i;
	cout << "Enter no. of Students :: ";
	cin >> n;
	Student * stu = new Student[n];
        getchar();

	for(i=0;i<n;i++)
	{
	  cout<< "----------Enter data of student :: " << i+1 << "----------" <<endl;
	  stu[i].ReadStudentData();
	}

	cout << "Name\tAge\tDept\tYear" << endl;
	for(i=0;i<n;i++)
		stu[i].PrintStudentData();
	return 0;
}
