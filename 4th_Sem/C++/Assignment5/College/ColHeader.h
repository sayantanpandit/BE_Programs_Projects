

class AllDetails
{
  public :   
             AllDetails();
             AllDetails(const char *, int , const char *);
             ~AllDetails();
             void readData(const char *,int , const char *);
	     void writeData();
  protected :
             char *Name;
             int Age;
             char *Gender;
};


//Derived Class
class Student : public AllDetails
{
    protected :
              char *Dept;
              int Year;
    public :
         Student();
         Student(const char *,int , const char *, const char * , int);
         ~Student();
         void readData(const char *,int , const char *, const char * ,int );
         void writeData();
};

class Clerk : public AllDetails
{
     protected :
                char *WorkLoad;
                double Salary;
     public :
         Clerk();
         Clerk(const char *,int , const char *, const char *, double );
	 ~Clerk();
         void readData(const char *,int , const char *, const char * , double );
         void writeData();
};

class Professor : public AllDetails
{
     protected :
                char *Dept;
                char *CourseLoad;
                double Salary;
     public :
         Professor();
         Professor(const char *,int , const char *, const char * ,const char *, double );
         ~Professor();
         void readData(const char *,int , const char *, const char * ,const char *, double );
	 void writeData();
};


