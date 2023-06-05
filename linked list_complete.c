#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *add;
};
typedef struct Node NODE;
NODE *Head =NULL;
void insert_head(int data)
{
	NODE *NN;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->add=NULL;
	if(Head==NULL)
	{
		Head=NN;
	}
	else
	{
		NN->add=Head;
		Head=NN;
	}
	
}
void insert_end(int data)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->add=NULL;
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
/*void insert_pos(int data,int p)
{
    NODE *NN,*temp;
    int i,flag=0;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->add=NULL;
	if(Head==NULL)
	{
		Head=NN;
	}
	else if(p==1)
	{
		insert_head(data);
	}
	else 
	{
		temp=Head;
		for(i=1; i<p-1; i++)
		{
			temp=temp->add;
			if(temp->add==NULL)
			{
				temp->add=NN;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			NN->add=temp->add;
		    temp->add=NN;
		}
	}	
}*/
void insert_pos(int data,int p)
{
    NODE *NN;
    int cn=1,i,flag=0;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->add=NULL;
	NODE *temp=Head;
	while(temp)
	{
		temp=temp->add;
		cn++;
	}
	if(Head==NULL)
	{
		Head=NN;
	}
	else if(p==1)
	{
		insert_head(data);
	}
	else if(p>cn)
	{
		insert_end(data);
	}
	else 
	{
		temp=Head;
		for(i=1; i<p-1; i++)
		{
			temp=temp->add;
		}
		NN->add=temp->add;
		temp->add=NN;
	}	
}
int delete_head()
{
	int val;
	NODE *temp;
	if(Head==NULL)
	{
		return -1;
	}
	else
	{
		temp=Head;
		Head=Head->add;
		temp->add=NULL;
		return temp->data;
	}
}
int delete_end()
{
	int val;
	NODE *temp;
	temp=Head;
	if(Head==NULL)
	{
		return -1;;
	}
	else if(Head->add==NULL)
	{
		val=Head->data;
		Head=NULL;
		return val;
	}
	else
	{
		temp=Head;
		while((temp->add)->add)
		{
           temp=temp->add;
		}
		val=temp->add->data;
		temp->add=NULL;
		return val;
	}
}
int delete_pos(int p)
{
	int i=1,cn=1,val;
	NODE *temp=Head;
	while(temp)
	{
		temp=temp->add;
		cn++;
	}
	if(Head==NULL)
	{
		return -1;
	}
	else if(Head->add==NULL)
	{
		val=Head->data;
		Head=NULL;
		return val;
	}
	else if(p==1)
	{
		val=delete_head();
	}
	else if(p>cn)
	{
		val=delete_end();
		return val;
	}
	else
	{
		temp=Head;
		for(i=1; i<p-1; i++)
		{
			temp=temp->add;
		}
		val=temp->add->data;
		temp->add=temp->add->add;
		return val;
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
void main()
{
	int ch,data,p;
	while(1)
	{
		printf("1.insert_end 2.delete_end 3.insert_head 4.delete_head 5.insert_position 6.delete_position 7.display 8.exit ");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&data);
			insert_end(data);
			
		}
		else if(ch==2)
		{
			data=delete_end();
			if(data==-1)
			{
				printf("no nodes\n");
			}
			else
			{
				printf("%d",data);
			}
			
		}
		else if(ch==3)
		{
			scanf("%d",&data);
			insert_head(data);
		}
		else if(ch==4)
		{
			data=delete_head();
			if(data==-1)
			{
				printf("no nodes\n");
			}
			else
			{
				printf("%d",data);
			}
			
		}
		else if(ch==5)
		{
			scanf("%d %d",&data,&p);
			insert_pos(data,p);
		}
		else if(ch==6)
		{
			scanf("%d",&p);
			data=delete_pos(p);
			if(data==-1)
			{
				printf("no nodes\n");
			}
			else
			{
				printf("%d\n",data);
			}
		}
		else if(ch==7)
		{
			display();
		}
		else
		{
			break;
		}
	}
}


