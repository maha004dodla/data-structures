#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *add;
};
typedef struct Node NODE;
NODE *Head =NULL;
void insert(int data)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->add=NU`LL;
	if(Head==NULL)
	{
		Head=NN;
	}
	else
	{
		temp=Head;
		while(temp->add!=NULL)
		{
			temp=temp->add;
		}
		temp->add=NN;
	}
	
}
void display()
{
	NODE *temp;
	temp=Head;
	if(Head==NULL)
	{
		printf("no nodes\n");
	}
	else
	{
		temp=Head;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->add;
		}
		printf("\n");
	}
}
void del()
{
	NODE *temp;
	temp=Head;
	if(Head==NULL)
	{
		printf("no nodes\n");
	}
	else if(Head->add==NULL)
	{
		Head=NULL;
	}
	else
	{
		temp=Head;
		while((temp->add)->add!=NULL)
		{
           temp=temp->add;
		}
		temp->add=NULL;
	}
}
void main()
{
	int ch,data;
	while(1)
	{
		printf("1.insert 2.delete 3.display 4.exit ");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&data);
			insert(data);
			
		}
		else if(ch==2)
		{
			del();
		}
		else if(ch==3)
		{
			display();
		}
		else
		{
			break;
		}
	}
}
