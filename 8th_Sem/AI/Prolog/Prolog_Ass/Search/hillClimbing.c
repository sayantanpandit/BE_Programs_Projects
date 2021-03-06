#include<stdio.h>
#include<stdlib.h>

struct qnode
{
	int board[3][3];
	int distance;
	struct qnode* next;
	struct qnode* parent;
};
typedef struct qnode qnode;

enque(qnode** rear, qnode** front, qnode newnode)
{
	if((*rear)==NULL)
	{
		(*rear)=(qnode*)malloc(sizeof(qnode));
		(**rear)=newnode;
		(*rear)->next=NULL;
		(*front)=(*rear);
	}
	else
	{
		qnode* temp=(qnode*)malloc(sizeof(qnode));
		(*temp)=newnode;
		temp->next=NULL;
		(*rear)->next=temp;
		(*rear)=temp;
	}
}

qnode deque(qnode** rear, qnode** front)
{
	qnode temp;
	if((*front)==NULL)
	{
		printf("Trying to remove from empty queue.. Exiting..\n");
		exit(1);
	}
	else
	{
		temp=(**front);
		(*front)=(*front)->next;
		if((*front)==NULL)
			(*rear)=(*front);
	}
	return temp;
}

push(qnode** top, qnode newnode)
{
	if((*top)==NULL)
	{
		(*top)=(qnode*)malloc(sizeof(qnode));
		(**top)=newnode;
		(*top)->next=NULL;
	}
	else
	{		
		qnode* temp=(qnode*)malloc(sizeof(qnode));
		(*temp)=newnode;
		temp->next=(*top);
		(*top)=temp;
	}
}

qnode pop(qnode** top)
{
	qnode temp;
	if((*top)==NULL)
	{
		printf("Trying to remove from empty stack.. Exiting..\n");
		exit(1);
	}
	else
	{
		temp=(**top);
		(*top)=(*top)->next;
	}
	return temp;
}

display(qnode* tempNode, int step)
{
	if(tempNode==NULL)
		return;
	else
	{
		display(tempNode->parent,step-1);
		int i,j;
		printf("\nStep %d:\n\n",step);
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%d	",tempNode->board[i][j]);
			}
			printf("\n");
		}
		printf("\n\n\n");
	}
}

puzzle(int initMat[3][3], int goalMat[3][3])
{
	qnode* top=NULL;
	qnode* r2=NULL;
	qnode* f2=NULL;
	int i,j,k,count=0;
	qnode first;
	first.distance=0;
	first.parent=NULL;
	first.next=NULL;	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			first.board[i][j]=initMat[i][j];
		}
	}
	push(&top,first);
	while(1)
	{
		count=count+1;
		qnode tempNode=pop(&top);
		int flag1=0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(tempNode.board[i][j]!=goalMat[i][j])
					flag1=1;
			}
		}
		if(flag1==1)
		{
			enque(&r2,&f2,tempNode);
			int posR,posC;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					if(tempNode.board[i][j]==0)
					{
						posR=i;
						posC=j;
					}
				}
			}
			qnode tempNode1;
			qnode tempQ[4];
			int tempVar,ptr=0;
			qnode* tempF;
			if(posR+1 < 3)
			{
				tempNode1.distance=tempNode.distance+1;
				tempNode1.parent=r2;
				tempNode1.next=NULL;
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						tempNode1.board[i][j]=tempNode.board[i][j];
					}
				}
				tempVar=tempNode1.board[posR+1][posC];
				tempNode1.board[posR+1][posC]=tempNode1.board[posR][posC];
				tempNode1.board[posR][posC]=tempVar;
				tempF=f2;
				int flag2=0;
				while(tempF!=NULL)
				{
					int flag3=0;
					for(i=0;i<3;i++)
					{
						for(j=0;j<3;j++)
						{
							if(tempF->board[i][i]!=tempNode1.board[i][j])
								flag3=1;
						}
					}
					if(flag3==0)
					{
						flag2=1;
						break;
					}
					else
						tempF=tempF->next;
				}
				if(flag2==0)
					tempQ[ptr++]=tempNode1;
			}
			if(posR-1 >= 0)
			{
				tempNode1.distance=tempNode.distance+1;
				tempNode1.parent=r2;
				tempNode1.next=NULL;
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						tempNode1.board[i][j]=tempNode.board[i][j];
					}
				}
				tempVar=tempNode1.board[posR-1][posC];
				tempNode1.board[posR-1][posC]=tempNode1.board[posR][posC];
				tempNode1.board[posR][posC]=tempVar;
				tempF=f2;
				int flag2=0;
				while(tempF!=NULL)
				{
					int flag3=0;
					for(i=0;i<3;i++)
					{
						for(j=0;j<3;j++)
						{
							if(tempF->board[i][i]!=tempNode1.board[i][j])
								flag3=1;
						}
					}
					if(flag3==0)
					{
						flag2=1;
						break;
					}
					else
						tempF=tempF->next;
				}
				if(flag2==0)
					tempQ[ptr++]=tempNode1;
			}
			if(posC+1 < 3)
			{
				tempNode1.distance=tempNode.distance+1;
				tempNode1.parent=r2;
				tempNode1.next=NULL;
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						tempNode1.board[i][j]=tempNode.board[i][j];
					}
				}
				tempVar=tempNode1.board[posR][posC+1];
				tempNode1.board[posR][posC+1]=tempNode1.board[posR][posC];
				tempNode1.board[posR][posC]=tempVar;
				tempF=f2;
				int flag2=0;
				while(tempF!=NULL)
				{
					int flag3=0;
					for(i=0;i<3;i++)
					{
						for(j=0;j<3;j++)
						{
							if(tempF->board[i][i]!=tempNode1.board[i][j])
								flag3=1;
						}
					}
					if(flag3==0)
					{
						flag2=1;
						break;
					}
					else
						tempF=tempF->next;
				}
				if(flag2==0)
					tempQ[ptr++]=tempNode1;
			}
			if(posC-1 >= 0)
			{
				tempNode1.distance=tempNode.distance+1;
				tempNode1.parent=r2;
				tempNode1.next=NULL;
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						tempNode1.board[i][j]=tempNode.board[i][j];
					}
				}
				tempVar=tempNode1.board[posR][posC-1];
				tempNode1.board[posR][posC-1]=tempNode1.board[posR][posC];
				tempNode1.board[posR][posC]=tempVar;
				tempF=f2;
				int flag2=0;
				while(tempF!=NULL)
				{
					int flag3=0;
					for(i=0;i<3;i++)
					{
						for(j=0;j<3;j++)
						{
							if(tempF->board[i][i]!=tempNode1.board[i][j])
								flag3=1;
						}
					}
					if(flag3==0)
					{
						flag2=1;
						break;
					}
					else
						tempF=tempF->next;
				}
				if(flag2==0)
					tempQ[ptr++]=tempNode1;
			}
			int* h=(int*)malloc(ptr*sizeof(int));
			for(k=0;k<ptr;k++)
				h[k]=0;
			for(k=0;k<ptr;k++)
			{
				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						if(tempQ[k].board[i][j]!=goalMat[i][j] && goalMat[i][j]!=0)
							h[k]++;
					}
				}
			}
			int tempH;
			qnode tempSwap;
			for(i=0;i<ptr;i++)
			{
				for(j=0;j<ptr-i-1;j++)
				{
					if(h[j]>h[j+1])
					{
						tempSwap=tempQ[j];
						tempQ[j]=tempQ[j+1];
						tempQ[j+1]=tempSwap;
						tempH=h[j];
						h[j]=h[j+1];
						h[j+1]=tempH;
					}
				}
			}
			for(i=ptr-1;i>=0;i--)
				push(&top,tempQ[i]);	
		}
		else
		{
			printf("\nPath Length = %d\n", tempNode.distance);
			display(&tempNode,tempNode.distance);
			printf("Number of comparisons = %d\n",count);
			break;
		}
	}
}

int main()
{
	int initMat[3][3];
	int goalMat[3][3];
	int i,j;
	printf("\nEnter Initial Matrix:\n\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Row %d, Column %d: ",i,j);
			scanf("%d",&initMat[i][j]);
		}
	}
	printf("\nEnter Goal Matrix:\n\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Row %d, Column %d: ",i,j);
			scanf("%d",&goalMat[i][j]);
		}
	}
	puzzle(initMat,goalMat);
	return 0;
}

