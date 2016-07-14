

class Vehicle
{
  protected :
             double price;
             char *manufacturer;
  public :
     Vehicle();    //Default Constructor
     Vehicle(double , const char *); //Parameterized Constructor
     ~Vehicle();   //Default Destructor
     Vehicle(const Vehicle &);  //Copy Constructor
     Vehicle &operator = (const Vehicle &); //Assignment Constructor
     void ReadData(double price, const char *);
     void PrintData();
};

class Car : public Vehicle
{
  protected :
           char *color;
           int numberOfSeats;
           char *model;
  public :
      Car();
      Car(double , const char *, const char * ,int , const char * );
      ~Car();
      Car(const Car &);
      Car &operator = (const Car &);
      void ReadData(double , const char *, const char *,int , const char *);
      void PrintData();
};
