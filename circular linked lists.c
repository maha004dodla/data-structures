#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *add;
};
typedef struct Node NODE;
NODE *Head=NULL;
void insert_head(int data)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->add=NULL;
	if(Head==NULL)
	{
		Head=NN;
		Head->add=Head;
	}
	else
	{
		temp=Head;
		while(temp->add!=Head)
		{
			temp=temp->add;
		}
		NN->add=Head;
		Head=NN;
		temp->add=NN;
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
		Head->add=Head;
	}
	else
	{
		temp=Head;
		while(temp->add!=Head)
		{
			temp=temp->add;
		}
		temp->add=NN;
	    NN->add=Head;
	}	
}
void insert_pos(int data,int pos)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->add=NULL;
	int f=0;
	int i=0;
	if(Head==NULL)
	{
		Head=NN;
	}
	else if(pos==1)
	{
		insert_head(data);
	}
	else
	{
		temp=Head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->add;
			if(temp->add==Head)
			{
				temp->add=NN;
				f=1;
				break;
			}
		}
		if(f==0)
		{
			NN->add=temp->add;
			temp->add=NN;
		}
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
	else if(Head->add==Head)
	{
		val=Head->data;
		Head=NULL;
		return val;
	}
	else
	{
		temp=Head;
		while(temp->add!=Head)
		{
			temp=temp->add;
		}
		val=Head->data;
		Head=Head->add;	
		temp->add=Head;
		return val;
	}
}
int delete_end()
{
	NODE *temp;
	temp=Head;
	int val;
	if(Head==NULL)
	{
		return -1;
	}
	else if(Head->add==Head)
	{
		val=Head->data;
		Head=NULL;
		return val;
	}
	else
	{
		temp=Head;
		while(temp->add->add!=Head)
		{
			temp=temp->add;
		}
		val=temp->add->data;
		temp->add=Head;
		return val;	
	}
}
int delete_pos(int pos)
{
	NODE *temp=Head;
	int val,i,cn=1;
	while(temp)
	{
		temp=temp->add;
		cn++;
	}
	if(Head==NULL)
	{
		return -1;
	}
	else if(Head->add==Head)
	{
		val=Head->data;
		Head=NULL;
		return val;
	}
	else if(pos==1)
	{
		val=delete_head();
		return val;
	}
	else if(pos>cn)
	{
		val=delete_end();
		return val;
	}
	else
	{
		temp=Head;
		for(i=1;i<pos-1;i++)
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
		while(temp->add!=Head)
		{
			printf("%d ",temp->data);
			temp=temp->add;
		}
		printf("%d\n",temp->data);
	}
}
void main()
{
	int ch,val,data,pos;
	while(1)
	{
		printf("1.insert_head 2.insert_end 3.insert_pos 4.delete_head 5.delete_end 6.delete_pos 7.display 8.exit ");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&data);
			insert_head(data);
			
		}
		else if(ch==2)
		{
			scanf("%d",&data);
			insert_end(data);
		}
		else if(ch==3)
		{
			scanf("%d %d",&data,&pos);
			insert_pos(data,pos);
		}
		else if(ch==4)
		{
			val=delete_head();
			if(val==-1)
			{
				printf("no nodes\n");
			}
			else
			{
				printf("%d\n",val);
			}	
		}
		else if(ch==5)
		{
			val=delete_end();
			if(val==-1)
			{
				printf("no nodes\n");
			}
			else
			{
				printf("%d",val);
			}	
		}
		else if(ch==6)
		{
			scanf("%d",&pos);
			val=delete_pos(pos);
			if(val==-1)
			{
				printf("NO NODES\n");
			}
			else
			{
				printf("%d\n",val);
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


