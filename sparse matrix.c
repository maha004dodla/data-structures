#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int row;
	int col;
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head=NULL;
void insert(int r,int c,int val)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->row=r;
	NN->col=c;
	NN->data=val;
	NN->next=NULL;
	if(head==NULL)
	{
		head=NN;
	}
	else
	{
		temp=head;
		while(temp->next)
		{
			temp=temp->next;
		}
		temp->next=NN;
	}	
}
void display()
{
	NODE *temp;
	temp=head;
	if(head==NULL)
	{
		printf("no nodes\n");
	}
	else
	{
		while(temp)
		{
			printf("%d %d %d\t",temp->row,temp->col,temp->data); 
			temp=temp->next;
		}
	}
}

int main()
{
	int r,c,arr[100][100],i,j;
	scanf("%d %d",&r,&c);
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			scanf("%d ",&arr[i][j]);
		}
	}
	for(i=0; i<r; i++)
	{
		for(j=0; j<c; j++)
		{
			if(arr[i][j]!=0)
			{
				insert(i,j,arr[i][j]);
			}
		}
	}
	printf("\n");
	display();
}