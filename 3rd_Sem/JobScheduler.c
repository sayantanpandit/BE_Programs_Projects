#include<stdio.h>

int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int top=0;
int gt;
struct node 
{
       int jobNo;
       int addt;
       int reqt;
};

void heapify(struct node );
void del();
struct node pq[50];
      
main()
{
    int n,i,delt,total=0;
    struct node s[10];
    printf("Enter no. of Jobs  :: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
                    scanf("%d",&s[i].jobNo);
                    scanf("%d",&s[i].addt);
                    scanf("%d",&s[i].reqt);
                    total=total+s[i].reqt;
                    
    }
    gt=0;
   delt=0;
    while(gt<=total)
    {
                for(i=1;i<=n;i++)
                {
                                if(s[i].addt==gt)
                                heapify(s[i]);
                }
                if(pq[1].reqt==0)
                {
                                 del();
                                  printf("  Time:%d\n",gt);
                }
                
                pq[1].reqt--;
               
                
                gt++;
    }
}
void heapify(struct node n)
{
     int i;
     struct node y;
     top++;
     pq[top]=n;
     i=top;
     
     while(i>1)
     {
                  if(pq[i].reqt<pq[i/2].reqt)
                  {
                          y=pq[i];
                          pq[i]=pq[i/2];
                          pq[i/2]=y;
                  }
                  i=i/2;
     }
} 

void del()
{
          int i,c;
          struct node y,x;
          printf("Job Completed:%d\t",pq[1].jobNo);
          pq[1]=pq[top];
          top=top-1;
          
          i=1;
          
          while(2*i<=top)
          {
                       if(pq[2*i].reqt>pq[2*i+1].reqt)         
                       c=2*i+1;
                       else
                       c=2*i;
                       if(pq[i].reqt>pq[c].reqt)
                       {
                              y=pq[i];
                              pq[i]=pq[c];
                              pq[c]=y;  
                              i=c;
                       }
                       else
                       break;
          }
}
