#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node *pre;
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head=NULL;
void insert_at_end(int data)
{
	NODE *NN,*temp;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->pre=NULL;
	NN->next=NULL;
	if(head==NULL)
	{
		head=NN;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=NN;
		NN->pre=temp;
	}
}
int delete_at_end()
{
	NODE *temp;
	int val;
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else
	{
		temp=head;
		while((temp->next)->next!=NULL)
		{
			temp=temp->next;
		}
		val=temp->next->data;
		temp->next->pre=NULL;
		temp->next=NULL;
		return val;
	}
}
void insert_at_head(int data)
{
	NODE *NN;
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->pre=NULL;
	NN->next=NULL;
	if(head==NULL)
	{
		head=NN;
	}
	else
	{
		head->pre=NULL;
		NN->next=head;
		head=NN;		
	}
}
int delete_at_head()
{
	NODE *temp;
	int val;
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else
	{
		temp=head;
		head=head->next;
		head->pre=NULL;
		val=temp->data;
		temp->next=NULL;
		return val;
	}
}
void insert_by_position(int data,int p)
{
	NODE *NN,*temp,*temp1;
	temp=head;
	int c=1,i;
	while(temp)
	{
		temp=temp->next;
		c++;
	}
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=data;
	NN->pre=NULL;
	NN->next=NULL;
	if(head==NULL)
	{
		head=NN;
	}
	else if(p==1)
	{
		insert_at_head(data);
	}
	else if(c<p)
	{
		insert_at_end(data);
	}
	else
	{
		temp=head;
		for(i=1;i<p-1;i++)
		{
			temp=temp->next;
		}
		temp1=temp->next;
		temp->next=NN;
		NN->pre=temp;
		NN->next=temp1;
		temp1->pre=NN;
	}
}
int delete_by_position(int p)
{
	NODE *temp,*temp1;
	temp=head;
	int c=1,i,val;
	while(temp)
    {
    	temp=temp->next;
    	c++;
	}
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else if(p==1)
	{
		val=delete_at_head();
		return val;
	}
	else if(p>c)
	{
		val=delete_at_end();
		return val;
	}
	else
	{
		temp=head;
		for(i=1;i<p-1;i++)
		{
			temp=temp->next;
		}
		temp1=temp->next;
		val=temp1->data;
		temp->next=temp1->next;
		temp1->next->pre=temp;
		return val;
	}
}
void display()
{
	NODE *temp;
	temp=head;
	if(head==NULL)
	{
		printf("NO NODES\n");
		return;
	}
	while(temp)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void main()
{
	int ch,val,p;
	while(1)
	{
		printf("1.insert at end 2.delete at end 3.display 4.insert at head 5.delete at head 6.insert by position 7.delete by position 8.exit");
		scanf("%d",&ch);
		if(ch==1)
		{
			//insert at end
			scanf("%d",&val);
			insert_at_end(val);
		}
		else if(ch==2)
		{
			//delete at end
			val=delete_at_end();
			if(val==-1)
			{
				printf("NO NODES\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==3)
		{
			//display
			display();
		}
		else if(ch==4)
		{
			//insert at head
			scanf("%d",&val);
			insert_at_head(val);
		}
		else if(ch==5)
		{
			val=delete_at_head();
			if(val==-1)
			{
				printf("NO NODES\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==6)
		{
			//insert by position
			scanf("%d",&val);
			scanf("%d",&p);
			insert_by_position(val,p);
		}
		else if(ch==7)
		{
			scanf("%d",&p);
			val=delete_by_position(p);
			{
				if(val==-1)
			    {
				    printf("NO NODES\n");
			    }
			    else
			    {
				    printf("%d\n",val);
			    }
			}
		}
		else
		{
			break;
		}
	}
	
}
