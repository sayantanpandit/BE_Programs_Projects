#include<cstdio>
#include<cstdlib>
typedef struct
{
	long long value;
	long long key;
}element;
void swap(element &a,element &b)
{
	long long tempvalue;
	long long tempkey;
	tempvalue=a.value;
	tempkey=a.key;
	a.value=b.value;
	a.key=b.key;
	b.key=tempkey;
	b.value=tempvalue;
}
long long parent(long long i)
{
	if(i%2==0)//that means it's a right child of it's parent
	{
		return (i-2)/2;
	}
		return (i-1)/2;
} 
void heapify(element A[],long long i,long long n)
{
	long long l,r,largest;
	l=2*i+1;
	r=2*i+2;
	if((l<=n)&&(A[l].key>A[i].key))
	{
		largest=l;	
	}
	else
	{
		largest=i;
	}
	if((r<=n)&&(A[r].key>A[largest].key))
	{
		largest=r;

	}
	if(i!=largest)
	{
		swap(A[i],A[largest]);
		heapify(A,largest,n);
	}
}
//algortihm maximum returns the element with the largest key
void Maximum(element A[],long long & n,element & maxelem)
{
	if(n<0)
	{
		printf("Empty priority queue\n");
		return;
	}
	maxelem=A[0];
}
//Extractmax removes and returns the element with the largest key
void Extractmax(element A[],long long & n,element & maxelem)
{
	//as in a max priority queue's heap implementation, root element is the element with the largest key	
	if(n<0)
	{
		printf("Empty priority queue\n");
		return;
	}
	else if(n==0)
	{
		n=n-1;
		maxelem=A[0];
		return;
	}
	swap(A[0],A[n]);
	n=n-1;
	heapify(A,0,n);//in this process (n=n-1 and heapify(A,0,n) element with the largest key is removed
	maxelem=A[n+1];
	return;
}
void Insertheap(element A[],long long & n,element x)
{
	if(n<0)
	{
		printf("This is the first element\n");
	}
	n=n+1;
	long long i=n;
	while(i>0&&A[parent(i)].key<x.key)
	{
		A[i].value=A[parent(i)].value;
		A[i].key=A[parent(i)].key;
		i=parent(i);
	}
	A[i].value=x.value;
	A[i].key=x.key;
}
//it increses the key of element x with value given to the new value
void Heapincrease(element A[],const long long &n,const long long &choosenvalue,long long new_key)
{
	bool flag=false;
	long long i;
	for(i=0;i<=n;i++)
	{
		if(A[i].value==choosenvalue)
		{
			flag=true;
			break;
		}
	}
	if(flag==false)
	{
		printf("Value is not found\n");
		return;
	}
	else
	{
		if(A[i].key>new_key)
		{
			printf("New key is smaller than current key\n");
			return;
		}
		else
		{
			A[i].key=new_key;
			element x=A[i];
			while(i>0&&A[parent(i)].key<new_key)
			{
				A[i].value=A[parent(i)].value;
				A[i].key=A[parent(i)].key;
				i=parent(i);
			}
			A[i].value=x.value;
			A[i].key=x.key;
		}
	}
}	

int main()
{
	long long elemno=-1;
	element A[500];//hoping 500 is long enoguh for my job
	int ch;
	do
	{
		printf("1.Insert a new element in the  heap\n");
		printf("2.Display the value of the element with largest key\n");
		printf("3.Delete the element with largest key value\n");
		printf("4.Increase the element's keyvalue to the new key value\n");
		printf("5.Exit\n");		
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:element newelem;
			       printf("Enter the element's value and key:");
				scanf("%lld%lld",&newelem.value,&newelem.key);
				Insertheap(A,elemno,newelem);
				break;
			case 2:element maxelem;
				Maximum(A,elemno,maxelem);
				printf("The value of the element with the largest keyvalue=%lld is:%lld\n",maxelem.key,maxelem.value);
				break;
			case 3:element exmaxelem;
				Extractmax(A,elemno,exmaxelem);
				printf("The value and the key of the element are=%lld,%lld\n",exmaxelem.value,exmaxelem.key);
				break;
			case 4:long long val,newkeyval;
				printf("Enter the element's value:");
				scanf("%lld",&val);
				printf("Enter the new key value:");
				scanf("%lld",&newkeyval);
				Heapincrease(A,elemno,val,newkeyval);
				break;
			case 5:printf("You choose to exit\n");
				break;
			default:printf("Invalid choice\n");
				break;
		}
	}while(ch!=5);
	return 0;
}
