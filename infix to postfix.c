#include<stdio.h>
#include<string.h>
char pf[100],st[100];
int top=-1;
int is_oper(char ch)
{
	switch(ch)
	{
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case ')':
			return -1;
		case '(':
			return -1;
		default:
			return 0;
	}
}
char *infix_to_postfix(char *infix)
{
	int i,op,k=0;
	for(i=0; infix[i]!='\0'; i++)
	{
		if(infix[i]==')')
		{
			while(st[top]!='(')
			{
				op=st[top--];
				pf[k++]=op;
			}
			top--;
			continue;
		}
		if(is_oper(infix[i]))
		{
			if(top==-1 || infix[i]!='(' || is_oper(infix[i])>is_oper(st[top]))
			{
				st[++top]=infix[i];
			}
			else
			{
				while(top!=-1 && is_oper(infix[i])<=is_oper(st[top]))
				{
					op=st[top--];
					pf[k++]=op;
				}
				st[++top]=infix[i];
			}
		}
		else
		{
			pf[k++]=infix[i];
		}
	}
	for(i=top; i>=0; i--)
	{
		pf[k++]=st[i];
	}
	return pf;	
}
int main()
{
	char st[100],infix[100];
	scanf("%[^\n]s",infix);
	strcpy(pf,infix_to_postfix(infix));
	printf("%s",pf);
}