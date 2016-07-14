#define STACKMAXSIZE 100

class MyStack 
{
  public :
           unsigned int top;
           unsigned int maxSize;
           int *list;
};

    
void Initialize (MyStack &, unsigned int = STACKMAXSIZE);
void Deinitialize (MyStack &);
int Push(MyStack &, const int &);
int Push(MyStack &, const int &, const int &);
int Pop(MyStack &, int &);

inline unsigned int MaximumSize(const MyStack & theStack)
{
  return theStack.maxSize;
}

inline unsigned int CurrentSize(const MyStack & theStack)
{
  return theStack.top;
}

int IsEmpty(const MyStack &);
void Display(const MyStack &);

const int ResultSuccess = 1;
const int ResultFailure = 0;
